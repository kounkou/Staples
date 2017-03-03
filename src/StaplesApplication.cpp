
#include "StaplesApplication.h"
#include <QNetworkRequest>

StaplesApplication::StaplesApplication()
   : _networkObj(NULL)
{
}

int StaplesApplication::init()
{
    _networkObj = _networkObjFactory.getNetworkManager();
    return (_networkObj != NULL) ? 0 : 1;
}

/*
 * This method will retrieve the current
 * RPI IP address that is being updated
 * accordingly on the server side.
 */
int StaplesApplication::retrieveServerApplicationIPAddress(const QUrl& url)
{
    QNetworkRequest request(url);
    QNetworkReply* result = _networkObj->get(request);
    return (result != NULL) ? 0 : 1;
}

StaplesApplication::~StaplesApplication()
{
    if (_networkObj != NULL)
    {
        delete _networkObj;
    }
    _networkObj = NULL;
}


