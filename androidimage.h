#ifndef ANDROIDIMAGE_H
#define ANDROIDIMAGE_H

#include<QImage>
#include<QLabel>
#include<Qt>
#include "caminhoimagens.h"

class AndroidImage: public QLabel
{
    Q_OBJECT
public:
    AndroidImage();

public slots:
    void getImage();
    void saveImage();
    void zoom(int value);
    void rotate(int value);


private:
    imageLoader* loader;
    void scaleImage(double factor);
private slots:
    void putImage();

protected:
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent *ev);


signals:
    void imageLoaded();

};

#endif // ANDROIDIMAGE_H
