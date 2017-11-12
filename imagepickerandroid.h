#ifndef IMAGEPICKERANDROID_H
#define IMAGEPICKERANDROID_H


#include <QObject>
#include <QtAndroidExtras>

#include <QDebug>

class imagePickerAndroid : public QObject, public QAndroidActivityResultReceiver
{
    Q_OBJECT

public:
    imagePickerAndroid();

    void buscaImagem();

    virtual void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject & data);

signals:
    void imagemCaminhoSignal(QString);
};

#endif // IMAGEPICKERANDROID_H
