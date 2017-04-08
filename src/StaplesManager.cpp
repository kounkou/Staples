
#include "StaplesManager.h"
#include "StaplesModel.h"
#include <sstream>

#include <QFile>

StaplesManager::StaplesManager()
{
}

StaplesManager::~StaplesManager()
{
}

/*
 * The structure of the data file can be found on
 * the README note
 */
int StaplesManager::retrieveStaples(const QJsonDocument& doc)
{
    int status = 1;

    QJsonObject jsonObj = doc.object();

    // accessing the singleton
    StaplesModel* _model = StaplesModel::getInstance();

    if (jsonObj.value(QString("status")) != "ok")
    {
        status = 1;
    }
    else
    {
        qDebug() << "status is ok";

        // clear the list before it's appent with garbage
        _model->clearListOfStaples();

        QJsonValue  agentsArrayValue = jsonObj.value("staples");
        QJsonArray  agentsArray      = agentsArrayValue.toArray();

        foreach (const QJsonValue & v, agentsArray)
        {
            qDebug() << v.toObject().value("name").toString();

            _model->addStaple(v.toObject().value("exp").toString().toStdString(),
                              v.toObject().value("name").toString().toStdString(),
                              v.toObject().value("price").toDouble(),
                              v.toObject().value("qty").toInt());
        }

        qDebug() << "finished reading the json file";
        _model->displayListOfStaples();

        status = 0;
    }

    return status;
}

/*
 * The authentificate method will identify the user of the
 * application. If you're already known, then we skip to
 * run the application, else we request for an ID
 */
int StaplesManager::authentificates(const QJsonDocument& doc)
{
    int status = 1;

    QJsonObject jsonObj = doc.object();

    // accessing the singleton
    StaplesModel* _model = StaplesModel::getInstance();

    if (jsonObj.value(QString("status")) != "ok")
    {

        status = 1;
    }
    else
    {
        qDebug() << "status is ok";

        status = 0;
    }

    return status;
}
