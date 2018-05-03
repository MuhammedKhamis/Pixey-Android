#include "androidimage.h"

AndroidImage::AndroidImage()
{

}
void AndroidImage::getImage(){
    tmp.buscaImagem();
    QString path = tmp.imagemCaminho();
    if(path.isNull() || path.isEmpty()){
        return;
    }
    QImage img;
    img.load(path);
    setPixmap(QPixmap::fromImage(img));
}

void AndroidImage::saveImage(){
    return;
}

