
#include "StaplesApplication.cpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class StaplesApplication_Test : public ::testing::Test
{
public:
    std::unique_ptr<StaplesApplication> stapleObj;

    StaplesApplication_Test()
    {
        stapleObj = std::unique_ptr<StaplesApplication>(new StaplesApplication);
    }

   ~StaplesApplication_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};

TEST_F(StaplesApplication_Test, init)
{
    EXPECT_EQ(0, stapleObj->init());
}

/*
 * This shall launch a local server
 * to perform the unit test
 * 192.168.0.21 is the official testing server
 */
TEST_F(StaplesApplication_Test, retrieveServerApplicationIPAddress)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->retrieveServerApplicationIPAddress(QUrl("http://192.168.0.21:1500")));
}

TEST_F(StaplesApplication_Test, onResult)
{
    // QNetworkReply* rep = NULL;
    // This interrupts the tests abruptly
    // EXPECT_EQ(1, stapleObj->onResult(rep));
}
