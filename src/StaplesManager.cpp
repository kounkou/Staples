
#include "StaplesManager.h"
#include "StaplesModel.h"

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

        // adding fake elements
        _model->addStaple(20170318, "Leerdammer",  6.52);
        _model->addStaple(20170318, "Ducros",      3.04);
        _model->addStaple(20170318, "Evian",       1.85);
        _model->addStaple(20170318, "Lactel",      2.82);
        _model->addStaple(20170318, "Daddie",      2.04);
        _model->addStaple(20170318, "some elt 1",  6.52);
        _model->addStaple(20170318, "some elt 2",  3.04);
        _model->addStaple(20170318, "some elt 3",  1.85);
        _model->addStaple(20170318, "some elt 4",  2.82);
        _model->addStaple(20170318, "some elt 5",  2.04);
        _model->addStaple(20170318, "some elt 6",  6.52);
        _model->addStaple(20170318, "some elt 7",  3.04);
        _model->addStaple(20170318, "some elt 8",  1.85);
        _model->addStaple(20170318, "some elt 9",  2.82);
        _model->addStaple(20170318, "some elt A",  2.04);

        status = 0;
    }

    return status;
}
