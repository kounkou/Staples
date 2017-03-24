
#include "StaplesObjFactory.cpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class StaplesObjFactory_Test : public ::testing::Test
{
public:
    std::unique_ptr<StaplesObjFactory> stapleObj;

    StaplesObjFactory_Test()
    {
        stapleObj = std::unique_ptr<StaplesObjFactory>(new StaplesObjFactory);
    }

   ~StaplesObjFactory_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};

/* Testing the factory with different type of object */
TEST_F(StaplesObjFactory_Test, getNetworkManager)
{
    QNetworkAccessManager* _nt = NULL;
    int* _intPtr = NULL;
    int  _int    = 9;
    _intPtr      = &_int;

    EXPECT_EQ(true, (stapleObj->get(_nt)     != NULL));
    EXPECT_EQ(true, (stapleObj->get(_intPtr) != NULL));
}

TEST_F(StaplesObjFactory_Test, getStaplesManager)
{
    StaplesManager* _st = NULL;
    EXPECT_EQ(true, (stapleObj->get(_st) != NULL));
}
