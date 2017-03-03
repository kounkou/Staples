
#include "StaplesNetworkFactory.h"

StaplesNetworkFactory::StaplesNetworkFactory()
{
}

StaplesNetworkFactory::~StaplesNetworkFactory()
{
}

QNetworkAccessManager* StaplesNetworkFactory::getNetworkManager()
{
    return new QNetworkAccessManager();
}
