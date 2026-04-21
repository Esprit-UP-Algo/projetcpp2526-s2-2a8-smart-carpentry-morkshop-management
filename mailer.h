#ifndef MAILER_H
#define MAILER_H

#include <QString>

class Mailer
{
public:
    static bool sendMail(const QString& to,
                         const QString& subject,
                         const QString& body,
                         QString* error = nullptr);
};

#endif
