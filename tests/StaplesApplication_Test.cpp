
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
    Staple s("Apr 2 2017", "Test", 5.80, 2);
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->addStapleToServer(s));
}

TEST_F(StaplesApplication_Test, removeStapleFromServer)
{
    Staple s("Apr 2 2017", "Test", 5.80, 2);
    stapleObj->init();
    EXPECT_EQ(0, stapleObj->removeStapleFromServer(s));
}


// Non Nominal cases

TEST_F(StaplesApplication_Test, sendHttpRequest)
{
    stapleObj->init();
    EXPECT_EQ(1, stapleObj->retrieveListOfStaples(QUrl("")));
}
