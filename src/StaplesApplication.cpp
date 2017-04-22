
#include "StaplesApplication.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QQmlContext>
#include <QtQuick>

StaplesApplication::StaplesApplication(QObject* parent)
    : QObject(parent)
    , _networkObj(NULL)
    , _staplesManager(NULL)
    , _model(NULL)
    , _view(NULL)
    , _item(NULL)
{
}

void StaplesApplication::initUserInterface()
{
    _model = StaplesModel::getInstance();

    // setting-up the UI
    _view = new QQuickView();
    _view->rootContext()->setContextProperty("stapleModel", _model);
    _view->setSource(QUrl("qrc:/main.qml"));
    _item = _view->rootObject();
    _view->setResizeMode(QQuickView::SizeRootObjectToView);
    _view->show();
}

int StaplesApplication::init()
{
    int status = 1;

    // starting services
    _networkObj     = _objFactory.get(_networkObj);
    _staplesManager = _objFactory.get(_staplesManager);
    _timer          = new QTimer(this);

    if (_networkObj != NULL && _staplesManager != NULL)
    {
       QObject::connect(_networkObj, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
       QObject::connect(_timer,      SIGNAL(timeout()),                this, SLOT(retrieveAllStaples()));
       QObject::connect(_item,       SIGNAL(refresh()),                this, SLOT(retrieveAllStaples()));
       status = 0;
    }
    else
    {
        status = 1;
    }

    // To be used for tests only
    // _timer->start(10000);

    QMetaObject::invokeMethod(_timer, "timeout");

    return status;
}

void StaplesApplication::retrieveAllStaples()
{
    retrieveListOfStaples(QUrl("http://192.168.0.21:8080"));
}

/*
 * This is a generic function created for all kinds of
 * commands including :
 * - retrieve list of staples
 * - add a new staple
 * - remove a staple
 */
int StaplesApplication::sendHttpRequest(const QUrl& url) const
{
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
 * This method will call the httpRequest to
 * update the list of staples
 */
int StaplesApplication::retrieveListOfStaples(const QUrl& url) const
{
    qDebug() << "called retrieveListOfStaples";
    return sendHttpRequest(url);
}

/*
 * This function will add staple to the
 * remote server with the provided
 * staple in parameter
 */
int StaplesApplication::addStapleToServer(const Staple& s) const
{
    QString str = "http://192.168.0.21:8080";
    qDebug() << str;
    return sendHttpRequest(QUrl(str));
}

/*
 * This function will remove a staple from the
 * remote server with the provided
 * staple in parameter
 */
int StaplesApplication::removeStapleFromServer(const Staple& s) const
{
    QString str = "http://192.168.0.21:8080";
    qDebug() << str;
    return sendHttpRequest(QUrl(str));
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


