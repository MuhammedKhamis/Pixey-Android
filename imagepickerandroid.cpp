#include "imagepickerandroid.h"

imagePickerAndroid::imagePickerAndroid()
{

}

void imagePickerAndroid::buscaImagem()
{
    // convert from QString to Java String
    QAndroidJniObject ACTION_PICK = QAndroidJniObject::fromString("android.intent.action.GET_CONTENT");
    // name of the class is between prantacess
    QAndroidJniObject intent("android/content/Intent");
    // Checking if I made a valid call for above two lines
    if (ACTION_PICK.isValid() && intent.isValid())
    {
        //calling the method in the object ( name of the method , (signature)returntype, input to method );
        intent.callObjectMethod("setAction", "(Ljava/lang/String;)Landroid/content/Intent;", ACTION_PICK.object<jstring>());
        intent.callObjectMethod("setType", "(Ljava/lang/String;)Landroid/content/Intent;", QAndroidJniObject::fromString("image/*").object<jstring>());
        // start activity (android thing i don't understand);
        // 101 is a specail code
        QtAndroid::startActivity(intent.object<jobject>(), 101, this);
        qDebug() << "OK";
    }
    else
    {
        qDebug() << "ERRO";
    }
}

void imagePickerAndroid::handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data)
{
    qDebug() << "Trabalha com os dados";
    // I think it check for results; but when we call it ??
    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
    if (receiverRequestCode == 101 && resultCode == RESULT_OK) {
        QString imagemCaminho = data.callObjectMethod("getData", "()Landroid/net/Uri;").callObjectMethod("getPath", "()Ljava/lang/String;").toString();
        emit imagemCaminhoSignal(imagemCaminho);
        qDebug() << imagemCaminho;
        }
        else
        {
            qDebug() << "Caminho errado";
        }
    }
