#include "common.h"


void setTextCodec(const QString& encodingName)
{
    QTextCodec *codec = QTextCodec::codecForName(encodingName.toStdString().c_str());
    QTextCodec::setCodecForLocale(codec);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setTextCodec("UTF-8");

    a.exec();

    return 0;
}
