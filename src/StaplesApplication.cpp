
#include "StaplesApplication.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

StaplesApplication::StaplesApplication(QObject* parent)
    : QObject(parent)
    , _networkObj(NULL)
    , _staplesManager(NULL)
    , _childContext(NULL)
    , _component(NULL)
    , _model(NULL)
{
}

int StaplesApplication::init()
{
    int status = 1;

    _model = new StaplesModel();

    _model->addStaple(20170318, "Evian",  1.80);
    _model->addStaple(20170318, "Lactel", 2.80);
    _model->addStaple(20170318, "Daddie", 2.00);
    _model->addStaple(20170318, "Ducros", 3.00);

    // setting-up the UI
    QQmlApplicationEngine engine;
    _childContext = new QQmlContext(&engine, &engine);
    _childContext->setContextProperty("stapleModel", _model);
    _component = new QQmlComponent(&engine, &engine);
    _component->loadUrl(QUrl("qrc:/main.qml"));

    // Create component in child context
    QObject *o = _component->create(_childContext);
    QQuickWindow* window = qobject_cast<QQuickWindow*>(o);
    window->show();

    // starting services
    _networkObj     = _objFactory.getNetworkManager();
    _staplesManager = _objFactory.getStaplesManager();

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
    retrieveServerApplicationIPAddress(QUrl("http://192.168.0.21:1500"));

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
            // retrieve the elements
            status = _staplesManager->retrieveStaples(doc);
        }
    }

    return status;
}

StaplesApplication::~StaplesApplication()
{
    if (_networkObj     != NULL) { delete _networkObj;     } _networkObj     = NULL;
    if (_staplesManager != NULL) { delete _staplesManager; } _staplesManager = NULL;
    if (_childContext   != NULL) { delete _childContext;   } _childContext   = NULL;
    if (_component      != NULL) { delete _component;      } _component      = NULL;
    if (_model          != NULL) { delete _model;          } _model          = NULL;
}


