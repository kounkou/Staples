#ifndef _STAPLES_MANAGER_H_
#define _STAPLES_MANAGER_H_

#include "Staple.h"
#include <memory>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

class StaplesManager
{
public:
    StaplesManager();
   ~StaplesManager();

    int retrieveStaples(const QJsonDocument& doc);

private:
    std::vector<Staple> _listOfStaples;
};

#endif
