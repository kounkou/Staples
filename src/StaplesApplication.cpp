
#include "StaplesApplication.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

StaplesApplication::StaplesApplication(QObject* parent)
    : QObject(parent)
    , _networkObj(NULL)
{
}

int StaplesApplication::init()
{
    int status = 1;

    _networkObj = _networkObjFactory.getNetworkManager();

    if (_networkObj != NULL)
    {
       QObject::connect(_networkObj, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
       status = 0;
    }
    else
    {
        status = 1;
    }

    return status;
}

/*
 * This method will retrieve the current
 * RPI IP address that is being updated
 * accordingly on the server side.
 */
int StaplesApplication::retrieveServerApplicationIPAddress(const QUrl& url)
{
    qDebug() << "retrieveServerApplicationIPAddress";

    int status = 1;

    if (!url.isEmpty())
    {
        qDebug() << "sending request";
        QNetworkRequest request(url);
        _networkObj->get(request);
        status = 0;
    }
    else
    {
        status = 1;
    }

    return status;
}

/*
 * This method will retrieve the network reply
 * The corresponding message is read with
 * respect to the message struct
 */
int StaplesApplication::onResult(QNetworkReply* rep)
{
    int status = 1;

    if (rep->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error when reading the data";
        status = 1;
    }
    else
    {
        QString data = (QString)rep->readAll();
        qDebug() << "data received is : " << data;
        QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

        if (doc.isNull())
        {
            qDebug() << "Invalid json document";
            status = 1;
        }
        else if (doc.isObject())
        {
            status = 0;
        }
    }

    return status;
}

StaplesApplication::~StaplesApplication()
{
    if (_networkObj != NULL)
    {
        delete _networkObj;
    }
    _networkObj = NULL;
}


