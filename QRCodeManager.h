#ifndef QRCODEMANAGER_H
#define QRCODEMANAGER_H

#include <QString>
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QColor>

class QRCodeManager
{
public:
    QRCodeManager();
    QPixmap genererQRCode(const QString &data, int taille = 300);
};

#endif // QRCODEMANAGER_H
