#include "startuplaunch.h"

#include <QDesktopServices>

StartupLaunch::StartupLaunch()
{
}


bool StartupLaunch::addOnStartup(QString name, QString executable, QString)
{
    QString autostartPath = QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"/Library/LaunchAgents";
    if(false==QDir().exists(autostartPath))
        QDir().mkdir(autostartPath);
    QString filepath = autostartPath+"/"+name.toLower()+".plist";
    QFile file(filepath);
    if(false==file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        qWarning() << "Startuplaunch : impossible to open " << filepath;
        return false;
    }
    QTextStream out(&file);
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl
        << "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd\">" << endl
        << "<plist version=\"1.0\">" << endl
        << "<dict>" << endl
        << "<key>Label</key>" << endl
        << "<string>me.boxti.boxtime</string>" << endl
        << "<key>RunAtLoad</key>" << endl
        << "<true/>" << endl
        << "<key>Program</key>" << endl
        << "<string>/Applications/boxtime.app/Contents/MacOS/boxtime</string>" << endl
        << "</dict>" << endl
        << "</plist>" << endl;
    file.close();
    qDebug() << name << " added to startup " << executable;
    return true;
}

bool StartupLaunch::removeFromStartup(QString name)
{
    qDebug() << name << " removed from startup";
    return QFile::remove(QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+QString("/Library/LaunchAgents/")+name.toLower()+QString(".plist"));
}


bool StartupLaunch::isOnStartup(QString name)
{
    return QFile::exists(QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+QString("/Library/LaunchAgents/")+name.toLower()+QString(".plist"));
}

