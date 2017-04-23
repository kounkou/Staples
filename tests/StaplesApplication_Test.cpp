
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

// Nominal cases

TEST_F(StaplesApplication_Test, init)
{
    EXPECT_EQ(0, stapleObj->init());
}

TEST_F(StaplesApplication_Test, retrieveListOfStaples)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->retrieveListOfStaples(QUrl("http://127.0.0.1:1500")));
}

TEST_F(StaplesApplication_Test, addStapleToServer)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->onAddStaple("2010-10-25T10:28:58.570Z", "Test", 5.80, 2));
}

TEST_F(StaplesApplication_Test, removeStapleFromServer)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->onRemoveStaple("Test"));
}

TEST_F(StaplesApplication_Test, authentificate)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->onAuthentificate("Test", "Test"));
}

TEST_F(StaplesApplication_Test, addOneStaple)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->onAddOneStaple("Test"));
}

TEST_F(StaplesApplication_Test, removeOneStaple)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->onRemoveOneStaple("Test"));
}

TEST_F(StaplesApplication_Test, onSearchStaple)
{
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->onSearchStaple("Test"));
}

// Non Nominal cases
TEST_F(StaplesApplication_Test, sendHttpRequest)
{
    stapleObj->init();
    EXPECT_EQ(1, stapleObj->retrieveListOfStaples(QUrl("")));
}
