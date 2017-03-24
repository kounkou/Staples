#ifndef _STAPLES_OBJ_FACTORY_H_
#define _STAPLES_OBJ_FACTORY_H_

#include "StaplesObjFactory.h"
#include "StaplesManager.h"
#include <QNetworkAccessManager>
#include "StaplesModel.h"

class StaplesObjFactory
{
public:
    StaplesObjFactory();
   ~StaplesObjFactory();

    /*
     * This templatized function provides object
     * of given type to the caller.
     * The function also provides a checking mechanism
     * for the object to be created
     */
    template <typename T>
    T* get(T* type) const
    {
        // object was already created
        if (type != NULL) { return type; }

        return new T();
    }
};

#endif // _STAPLES_OBJ_FACTORY_H_
