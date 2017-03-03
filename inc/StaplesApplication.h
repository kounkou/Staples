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
#include "StaplesNetworkFactory.h"

class StaplesApplication
{

/// public methods
public:
   StaplesApplication();
   virtual ~StaplesApplication();

   int init();

/// protected members
private:
   QNetworkAccessManager* _networkObj;
   StaplesNetworkFactory _networkObjFactory;
};

#endif // end of _STAPLES_APPLICATION_H_
