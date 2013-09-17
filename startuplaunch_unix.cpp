#include "startuplaunch.h"

#include <QDesktopServices>

StartupLaunch::StartupLaunch()
{
}


bool StartupLaunch::addOnStartup(QString name, QString executable, QString comments)
{
    QString autostartPath = QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+"/.config/autostart";
    if(false==QDir().exists(autostartPath))
        QDir().mkdir(autostartPath);

    QString filepath = autostartPath+"/"+name.toLower()+".desktop";
    QFile file(filepath);
    if(false==file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        qWarning() << "Startuplaunch : impossible to open " << filepath;
        return false;
    }
    QTextStream out(&file);
    out << "[Desktop Entry]" << endl
        << "Type=Application" << endl
        << "Exec=" << executable  << endl
        << "Hidden=false" << endl
        << "NoDisplay=false" << endl
        << "X-GNOME-Autostart-enabled=true" << endl
        << "Name[en]=" << name  << endl
        << "Name=" << name << endl
        << "Comment[en]=" << comments << endl
        << "Comment=" << comments << endl;
    file.close();
    qDebug() << name << " added to startup " << executable;
    return true;
}

bool StartupLaunch::removeFromStartup(QString name)
{
    qDebug() << name << " removed from startup";
    return QFile::remove(QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+QString("/.config/autostart/")+name.toLower()+QString(".desktop"));
}


bool StartupLaunch::isOnStartup(QString name)
{
    return QFile::exists(QDesktopServices::storageLocation(QDesktopServices::HomeLocation)+QString("/.config/autostart/")+name.toLower()+QString(".desktop"));
}
