#ifndef ANDROIDIMAGE_H
#define ANDROIDIMAGE_H

#include<QImage>
#include<QLabel>

#include "caminhoimagens.h"

class AndroidImage: public QLabel
{
    Q_OBJECT
public:
    AndroidImage();

public slots:
    void getImage();
    void saveImage();

private:
    caminhoImagens tmp;
};

#endif // ANDROIDIMAGE_H
