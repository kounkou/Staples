
#include "StaplesManager.cpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class StaplesManager_Test : public ::testing::Test
{
public:
    std::unique_ptr<StaplesManager> stapleObj;

    StaplesManager_Test()
    {
        stapleObj = std::unique_ptr<StaplesManager>(new StaplesManager);
    }

   ~StaplesManager_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};

TEST_F(StaplesManager_Test, retrieveStaples)
{
    QJsonDocument doc;

    EXPECT_EQ(1, stapleObj->retrieveStaples(doc));
}
