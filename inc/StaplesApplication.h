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
#include <QQuickView>
#include "StaplesModel.h"
#include <QTimer>

class StaplesApplication : public QObject
{
    Q_OBJECT

public:
   explicit StaplesApplication(QObject *parent = 0);
   virtual ~StaplesApplication();

   int  init();
   int  retrieveListOfStaples(const QUrl& url)  const;
   int  addStapleToServer(const Staple& s)      const;
   int  removeStapleFromServer(const Staple& s) const;
   void initUserInterface();

private:
   int  sendHttpRequest(const QUrl& url) const;

private slots:
    int  onResult(QNetworkReply* rep);
    void retrieveAllStaples();

/// protected members
private:
   QNetworkAccessManager* _networkObj;
   StaplesObjFactory      _objFactory;
   StaplesManager*        _staplesManager;
   StaplesModel*          _model;
   QQuickView*            _view;
   QTimer*                _timer;
   QObject*               _item;
};

#endif // end of _STAPLES_APPLICATION_H_
