
#include "StaplesManager.h"
#include "StaplesModel.h"
#include <sstream>

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

        QVariantMap staplesMap = jsonObj.toVariantMap();
        QVariantMap dataMap    = staplesMap["data"].toMap();
        QVariantMap staples    = dataMap["staples"].toMap();

        /*
         * This loop will iterate through the elements of the data
         * file, and staples inside the listview
         */
        for (int ii = 1; ii < staples.size(); ++ii)
        {
            QString ss = QString("s%1").arg(ii);

            _model->addStaple((staples[ss].toMap())["exp"].toInt(),
                              (staples[ss].toMap())["name"].toString().toStdString(),
                              (staples[ss].toMap())["price"].toFloat(),
                              (staples[ss].toMap())["qty"].toInt());
        }

        status = 0;
    }

    return status;
}
