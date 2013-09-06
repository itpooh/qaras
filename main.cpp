#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QSettings>
#include "qaras.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QFile fl("flog.txt");
    fl.open(QIODevice::WriteOnly);
    QFile binFileApp(argv[0]);
    QFileInfo fileInfo(binFileApp);
    qDebug() << fileInfo.absolutePath();
    QString pathToFileSettings = fileInfo.absolutePath() + "/" + "us.ini";

    fl.write(pathToFileSettings.toLatin1());
    fl.close();

    //QString pathToFileSettings = QCoreApplication::applicationDirPath() + "/" + "us.ini";
    QSettings settings(pathToFileSettings, QSettings::IniFormat);

    if (!QFile::exists(pathToFileSettings)){
        settings.beginGroup("ServiceSettings");
        settings.setValue("pathtoapp", "c:/Program files/myapp.exe");
        settings.setValue("name", "exampleName");
        settings.setValue("description", "this you app description");
        settings.setValue("param", "-a 12");

        settings.endGroup();

    }
    QString serviceFileRunAsService;
    QString serviceName;
    QString serviceParam;
    QString serviceDescription;
    settings.beginGroup("ServiceSettings");
    serviceFileRunAsService = settings.value("pathtoapp").toString();
    serviceName = settings.value("name").toString();
    serviceParam = settings.value("param").toString();
    serviceDescription = settings.value("description").toString();

    UniversalServise service(argc, argv, serviceFileRunAsService, serviceDescription, serviceParam, serviceName);
    return service.exec();
}
