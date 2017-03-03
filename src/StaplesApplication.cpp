
#include "StaplesApplication.h"

StaplesApplication::StaplesApplication()
   : _networkObj(NULL)
{
}

int StaplesApplication::init()
{
    _networkObj = _networkObjFactory.getNetworkManager();

    if (_networkObj != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

StaplesApplication::~StaplesApplication()
{
    if (_networkObj != NULL)
    {
        delete _networkObj;
    }
    _networkObj = NULL;
}


