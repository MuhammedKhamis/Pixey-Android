#include "imagepickerandroid.h"

imagePickerAndroid::imagePickerAndroid()
{

}

void imagePickerAndroid::searchImage()
{
//    // convert from QString to Java String
//    QAndroidJniObject ACTION_PICK = QAndroidJniObject::fromString("android.intent.action.GET_CONTENT");
//    // name of the class is between prantacess
//    QAndroidJniObject intent("android/content/Intent");
//    // Checking if I made a valid call for above two lines
//    if (ACTION_PICK.isValid() && intent.isValid())
//    {
//        //calling the method in the object ( name of the method , (signature)returntype, input to method );
//        intent.callObjectMethod("setAction", "(Ljava/lang/String;)Landroid/content/Intent;", ACTION_PICK.object<jstring>());
//        intent.callObjectMethod("setType", "(Ljava/lang/String;)Landroid/content/Intent;", QAndroidJniObject::fromString("image/*").object<jstring>());
//        // start activity (android thing i don't understand);
//        // 101 is a specail code
//        QtAndroid::startActivity(intent.object<jobject>(), 101, this);
//    }

    QAndroidJniObject ACTION_PICK = QAndroidJniObject::getStaticObjectField("android/content/Intent", "ACTION_PICK", "Ljava/lang/String;");
    QAndroidJniObject EXTERNAL_CONTENT_URI = QAndroidJniObject::getStaticObjectField("android/provider/MediaStore$Images$Media", "EXTERNAL_CONTENT_URI", "Landroid/net/Uri;");

    QAndroidJniObject intent=QAndroidJniObject("android/content/Intent", "(Ljava/lang/String;Landroid/net/Uri;)V", ACTION_PICK.object<jstring>(), EXTERNAL_CONTENT_URI.object<jobject>());

    if (ACTION_PICK.isValid() && intent.isValid())
    {
        intent.callObjectMethod("setType", "(Ljava/lang/String;)Landroid/content/Intent;", QAndroidJniObject::fromString("image/*").object<jstring>());
        QtAndroid::startActivity(intent.object<jobject>(), 101, this);
    }
}

void imagePickerAndroid::handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data)
{
//    // I think it check for results;
//    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
//    if (receiverRequestCode == 101 && resultCode == RESULT_OK) {
//        QString imagemCaminho = data.callObjectMethod("getData", "()Landroid/net/Uri;").callObjectMethod("getPath", "()Ljava/lang/String;").toString();
//        emit imagePathSignal(imagemCaminho);
//    }
    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
    if (receiverRequestCode == 101 && resultCode == RESULT_OK)
    {
        QAndroidJniObject uri = data.callObjectMethod("getData", "()Landroid/net/Uri;");
        QAndroidJniObject dadosAndroid = QAndroidJniObject::getStaticObjectField("android/provider/MediaStore$MediaColumns", "DATA", "Ljava/lang/String;");
        QAndroidJniEnvironment env;
        jobjectArray projecao = (jobjectArray)env->NewObjectArray(1, env->FindClass("java/lang/String"), NULL);
        jobject projacaoDadosAndroid = env->NewStringUTF(dadosAndroid.toString().toStdString().c_str());
        env->SetObjectArrayElement(projecao, 0, projacaoDadosAndroid);
        QAndroidJniObject contentResolver = QtAndroid::androidActivity().callObjectMethod("getContentResolver", "()Landroid/content/ContentResolver;");
        QAndroidJniObject cursor = contentResolver.callObjectMethod("query", "(Landroid/net/Uri;[Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)Landroid/database/Cursor;", uri.object<jobject>(), projecao, NULL, NULL, NULL);
        jint columnIndex = cursor.callMethod<jint>("getColumnIndex", "(Ljava/lang/String;)I", dadosAndroid.object<jstring>());
        cursor.callMethod<jboolean>("moveToFirst", "()Z");
        QAndroidJniObject resultado = cursor.callObjectMethod("getString", "(I)Ljava/lang/String;", columnIndex);
        QString imagemCaminho = resultado.toString();
        emit imagePathSignal(imagemCaminho);
    }
}
