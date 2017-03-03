
#include "StaplesNetworkFactory.cpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class StaplesNetworkFactory_Test : public ::testing::Test
{
public:
    std::unique_ptr<StaplesNetworkFactory> stapleObj;

    StaplesNetworkFactory_Test()
    {
        stapleObj = std::unique_ptr<StaplesNetworkFactory>(new StaplesNetworkFactory);
    }

   ~StaplesNetworkFactory_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};
