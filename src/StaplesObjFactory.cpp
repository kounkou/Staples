
#include "StaplesObjFactory.h"

StaplesObjFactory::StaplesObjFactory()
{
}

StaplesObjFactory::~StaplesObjFactory()
{
}

QNetworkAccessManager* StaplesObjFactory::getNetworkManager()
{
    return new QNetworkAccessManager();
}

StaplesManager* StaplesObjFactory::getStaplesManager()
{
    return new StaplesManager();
}
