#ifndef _STAPLES_OBJ_FACTORY_H_
#define _STAPLES_OBJ_FACTORY_H_

#include "StaplesObjFactory.h"
#include "StaplesManager.h"
#include <QNetworkAccessManager>

class StaplesObjFactory
{
public:
    StaplesObjFactory();
   ~StaplesObjFactory();

    QNetworkAccessManager* getNetworkManager();
    StaplesManager*        getStaplesManager();
};

#endif // _STAPLES_OBJ_FACTORY_H_
