#include "mailer.h"

#include <QByteArray>
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcessEnvironment>
#include <QTimer>
#include <QUrl>

namespace {

const QString kBrevoSenderEmail = QStringLiteral("smart.scwm@gmail.com");
const QString kBrevoSenderName = QStringLiteral("Brahim");

QString brevoApiKey()
{
    return qEnvironmentVariable("BREVO_API_KEY").trimmed();
}

QString extractErrorText(QNetworkReply* reply)
{
    const QByteArray raw = reply->readAll();
    const QJsonDocument doc = QJsonDocument::fromJson(raw);
    if (doc.isObject()) {
        const QJsonObject obj = doc.object();
        const QString message = obj.value(QStringLiteral("message")).toString();
        const QString code = obj.value(QStringLiteral("code")).toString();
        if (!code.isEmpty() || !message.isEmpty()) {
            return code.isEmpty() ? message : (code + QStringLiteral(": ") + message);
        }
    }

    const QString text = QString::fromUtf8(raw).trimmed();
    if (!text.isEmpty()) {
        return text;
    }

    return reply->errorString();
}

bool waitForReply(QNetworkReply* reply, int timeoutMs = 15000)
{
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);

    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    timer.start(timeoutMs);
    loop.exec();

    return reply->isFinished();
}

} // namespace

bool Mailer::sendMail(const QString& to,
                      const QString& subject,
                      const QString& body,
                      QString* error)
{
    const QString apiKey = brevoApiKey();
    if (apiKey.isEmpty()) {
        if (error) {
            *error = QStringLiteral("BREVO_API_KEY non definie.");
        }
        return false;
    }

    if (to.trimmed().isEmpty()) {
        if (error) {
            *error = QStringLiteral("Adresse destinataire vide.");
        }
        return false;
    }

    QJsonObject sender;
    sender[QStringLiteral("email")] = kBrevoSenderEmail;
    sender[QStringLiteral("name")] = kBrevoSenderName;

    QJsonObject recipient;
    recipient[QStringLiteral("email")] = to.trimmed();

    QJsonArray recipients;
    recipients.append(recipient);

    QJsonObject payload;
    payload[QStringLiteral("sender")] = sender;
    payload[QStringLiteral("to")] = recipients;
    payload[QStringLiteral("subject")] = subject;
    payload[QStringLiteral("textContent")] = body;

    QNetworkRequest request(QUrl(QStringLiteral("https://api.brevo.com/v3/smtp/email")));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));
    request.setRawHeader("accept", "application/json");
    request.setRawHeader("api-key", apiKey.toUtf8());

    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.post(request, QJsonDocument(payload).toJson(QJsonDocument::Compact));

    if (!waitForReply(reply)) {
        reply->abort();
        if (error) {
            *error = QStringLiteral("Timeout lors de l'appel Brevo API.");
        }
        reply->deleteLater();
        return false;
    }

    const int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    const bool ok = (reply->error() == QNetworkReply::NoError) && (httpStatus >= 200 && httpStatus < 300);

    if (!ok) {
        if (error) {
            const QString details = extractErrorText(reply);
            *error = QStringLiteral("Brevo API error (%1): %2").arg(httpStatus).arg(details);
        }
        reply->deleteLater();
        return false;
    }

    reply->deleteLater();
    return true;
}
