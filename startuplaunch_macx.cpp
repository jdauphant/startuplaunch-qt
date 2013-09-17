#include "startuplaunch.h"

#include <QDesktopServices>

StartupLaunch::StartupLaunch()
{
}


bool StartupLaunch::addOnStartup(QString name, QString executable, QString comments)
{
    qWarning() << " add to startup not yet implemented on macx";
    return false;
}

bool StartupLaunch::removeFromStartup(QString name)
{
    qWarning() << " remove from startup not yet implemented on macx";
    return false;
}


bool StartupLaunch::isOnStartup(QString name)
{
    qWarning() << " is on startup not yet implemented on macx";
    return false;
}

