#include "androidimage.h"

AndroidImage::AndroidImage()
{
    loader = new imageLoader;
    connect(loader,SIGNAL(imagePathChanged()),this,SLOT(putImage()));

}
void AndroidImage::getImage(){

    loader->searchImage();
}

void AndroidImage::putImage(){

    QString fileName = loader->imagePath();

    if(fileName.isNull() || fileName.isEmpty())return;

    QImage img(fileName);

    if(img.isNull())return;


    setPixmap(QPixmap::fromImage(img));

    setScaledContents( true );

    setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    emit imageLoaded();
}


void AndroidImage::zoom(int value){
    Q_ASSERT(pixmap());
    double factor = .04*value;
    resize(factor * pixmap()->size());
}

void AndroidImage::rotate(int value){
    double factor = (180/25.0)*(value)-180;
    QPixmap pixmap(*this->pixmap());
    QMatrix rm;
    rm.rotate(factor);
    pixmap = pixmap.transformed(rm);
    setPixmap(pixmap);
}
void AndroidImage::saveImage(){
    return;
}
void AndroidImage::mousePressEvent(QMouseEvent *ev){
    this->setStyleSheet("background-color : pink;");
}

void AndroidImage::mouseReleaseEvent(QMouseEvent *ev){
    this->setStyleSheet("background-color : red;");
}
