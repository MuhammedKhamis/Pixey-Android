#ifndef CAMINHOIMAGENS_H
#define CAMINHOIMAGENS_H

#include <QObject>

#include "imagepickerandroid.h"

#include <QDebug>

class imageLoader : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imagePath READ imagePath NOTIFY imagePathChanged)

public slots:
    void searchImage();
    void returnImage(QString path);

public:
    imageLoader();

    QString imagePath();

private:
    QString imgPath = "";

signals:
    void imagePathChanged();
};

#endif //CAMINHOIMAGENS_H
