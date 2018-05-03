#include "caminhoimagens.h"

imageLoader::imageLoader()
{

}

void imageLoader::searchImage()
{
    imagePickerAndroid *imagePicker = new imagePickerAndroid();
    connect(imagePicker, SIGNAL(imagePathSignal(QString)), this, SLOT(returnImage(QString)));

    imagePicker->searchImage();
}

void imageLoader::returnImage(QString path)
{
    imgPath = path;

    emit imagePathChanged();
}

QString imageLoader::imagePath()
{
    return imgPath;
}
