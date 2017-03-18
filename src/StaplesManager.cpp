
#include "StaplesManager.h"

StaplesManager::StaplesManager()
{
}

StaplesManager::~StaplesManager()
{
}

/*
 * The structure of the data file can be found on
 * the README note
 */
int StaplesManager::retrieveStaples(const QJsonDocument& doc)
{
    int status = 1;

    QJsonObject jsonObj = doc.object();

    if (jsonObj.value(QString("status")) != "ok")
    {
        status = 1;
    }
    else
    {
        status = 0;
    }

    return 1;
}
