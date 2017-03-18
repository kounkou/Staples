
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

TEST_F(StaplesObjFactory_Test, getNetworkManager)
{
    EXPECT_EQ(true, (stapleObj->getNetworkManager() != NULL));
}

TEST_F(StaplesObjFactory_Test, getStaplesManager)
{
    EXPECT_EQ(true, (stapleObj->getStaplesManager() != NULL));
}
