/*
 *
 * FILE : StaplesApplication.h
 *
 * DESCRIPTION
 * Staple Application is the main class to
 * be instanciated to launch the Staple
 * application
 */

#ifndef _STAPLES_APPLICATION_H_
#define _STAPLES_APPLICATION_H_

#include <string>
#include "StaplesObjFactory.h"
#include <QObject>
#include <QNetworkReply>
#include "StaplesManager.h"

class StaplesApplication : public QObject
{
    Q_OBJECT

/// public methods
public:
   explicit StaplesApplication(QObject *parent = 0);
   virtual ~StaplesApplication();

   int init();
   int retrieveServerApplicationIPAddress(const QUrl &url);

public slots:
    int onResult(QNetworkReply* rep);

/// protected members
private:
   QNetworkAccessManager* _networkObj;
   StaplesObjFactory      _objFactory;
   StaplesManager*        _staplesManager;
};

#endif // end of _STAPLES_APPLICATION_H_
