
#include "StaplesApplication.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QQmlContext>

StaplesApplication::StaplesApplication(QObject* parent)
    : QObject(parent)
    , _networkObj(NULL)
    , _staplesManager(NULL)
    , _model(NULL)
    , _view(NULL)
{
}

void StaplesApplication::initUserInterface()
{
    _model = StaplesModel::getInstance();

    // setting-up the UI
    _view = new QQuickView;
    _view->rootContext()->setContextProperty("stapleModel", _model);
    _view->setSource(QUrl("qrc:/main.qml"));
    _view->setResizeMode(QQuickView::SizeRootObjectToView);
}

int StaplesApplication::init()
{
    int status = 1;

    // starting services
    _networkObj     = _objFactory.get(_networkObj);
    _staplesManager = _objFactory.get(_staplesManager);

    if (_networkObj != NULL && _staplesManager != NULL)
    {
       QObject::connect(_networkObj, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
       status = 0;
    }
    else
    {
        status = 1;
    }

    // fake request
    // retrieveServerApplicationIPAddress(QUrl("http://192.168.0.21:1500"));

    return status;
}

/*
 * This method will retrieve the current
 * RPI IP address that is being updated
 * accordingly on the server side.
 */
int StaplesApplication::retrieveServerApplicationIPAddress(const QUrl& url) const
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
            // retrieve the elements
            qDebug() << "retrieving information ";
            status = _staplesManager->retrieveStaples(doc);
        }
    }

    return status;
}

StaplesApplication::~StaplesApplication()
{
    if (_networkObj     != NULL) { delete _networkObj;     } _networkObj     = NULL;
    if (_staplesManager != NULL) { delete _staplesManager; } _staplesManager = NULL;
    if (_model          != NULL) { delete _model;          } _model          = NULL;
    if (_view           != NULL) { delete _view;           } _view           = NULL;
}


