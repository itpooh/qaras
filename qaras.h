#ifndef UNIVERSALSERVISE_H
#define UNIVERSALSERVISE_H
#include <QtService.h>
#include <QDebug>
#include <QProcess>
#include <QtCore/QCoreApplication>

class UniversalServise : public QtService<QCoreApplication>
{
public:
    UniversalServise(int argc, char **argv, const QString&pathToRun, const QString&serviceDescription, const QString&serviceCLIParam , const QString&name):QtService<QCoreApplication>(argc, argv, name){
        m_pathToRun = pathToRun;
        m_serviceCLIParam << serviceCLIParam.split(" ");

        setServiceDescription(serviceDescription);
        setServiceFlags(QtServiceBase::CanBeSuspended);
        setStartupType(QtServiceController::AutoStartup);

    }
    ~UniversalServise(){};
public:
    QString m_pathToRun;

    QStringList m_serviceCLIParam;
    QProcess m_process;
protected:
    void start(){
        qDebug() << "process run";
        m_process.start( m_pathToRun, m_serviceCLIParam);
    };
    void stop(){
        m_process.terminate();
    };
    void pause(){};
    void resume(){};
    void processCommand(int code){};
};

#endif // UNIVERSALSERVISE_H
