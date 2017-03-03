#ifndef _STAPLES_NETWORK_FACTORY_H_
#define _STAPLES_NETWORK_FACTORY_H_

#include "StaplesNetworkFactory.h"
#include <QNetworkAccessManager>

class StaplesNetworkFactory
{
public:
    StaplesNetworkFactory();
   ~StaplesNetworkFactory();

    QNetworkAccessManager* getNetworkManager();
};

#endif // _STAPLES_NETWORK_FACTORY_H_
