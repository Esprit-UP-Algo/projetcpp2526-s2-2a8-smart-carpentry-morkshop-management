#include "QRCodeManager.h"
#include <QDebug>

QRCodeManager::QRCodeManager()
{
}

QPixmap QRCodeManager::genererQRCode(const QString &data, int taille)
{
    // Créer une image blanche
    QImage image(taille, taille, QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    int cellSize = taille / 25;
    if (cellSize < 2) cellSize = 2;

    // Créer un motif simple qui ressemble à un QR code
    // Basé sur les données pour que chaque QR soit différent
    QString text = data;
    QByteArray bytes = text.toUtf8();

    for (int i = 0; i < 25 && i < bytes.size(); i++) {
        for (int j = 0; j < 25; j++) {
            int val = (bytes[i] + j) % 2;
            if (val == 0) {
                painter.fillRect(i * cellSize, j * cellSize, cellSize, cellSize, Qt::black);
            }
        }
    }

    // Ajouter les 3 carrés caractéristiques des QR codes (pour l'apparence)
    // Carré haut-gauche
    painter.fillRect(0, 0, 7 * cellSize, 7 * cellSize, Qt::black);
    painter.fillRect(2 * cellSize, 2 * cellSize, 3 * cellSize, 3 * cellSize, Qt::white);
    painter.fillRect(3 * cellSize, 3 * cellSize, 1 * cellSize, 1 * cellSize, Qt::black);

    // Carré haut-droit
    painter.fillRect(taille - 7 * cellSize, 0, 7 * cellSize, 7 * cellSize, Qt::black);
    painter.fillRect(taille - 7 * cellSize + 2 * cellSize, 2 * cellSize, 3 * cellSize, 3 * cellSize, Qt::white);
    painter.fillRect(taille - 7 * cellSize + 3 * cellSize, 3 * cellSize, 1 * cellSize, 1 * cellSize, Qt::black);

    // Carré bas-gauche
    painter.fillRect(0, taille - 7 * cellSize, 7 * cellSize, 7 * cellSize, Qt::black);
    painter.fillRect(2 * cellSize, taille - 7 * cellSize + 2 * cellSize, 3 * cellSize, 3 * cellSize, Qt::white);
    painter.fillRect(3 * cellSize, taille - 7 * cellSize + 3 * cellSize, 1 * cellSize, 1 * cellSize, Qt::black);

    painter.end();

    return QPixmap::fromImage(image);
}
