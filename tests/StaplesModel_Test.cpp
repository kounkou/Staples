
#include "StaplesModel.cpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class StaplesModel_Test : public ::testing::Test
{
public:
    std::unique_ptr<StaplesModel> stapleObj;

    StaplesModel_Test()
    {
        stapleObj = std::unique_ptr<StaplesModel>(new StaplesModel);
    }

   ~StaplesModel_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};

TEST_F(StaplesModel_Test, rowCount)
{
    EXPECT_EQ(0, stapleObj->rowCount());
}

TEST_F(StaplesModel_Test, staplesContainerSize)
{
    EXPECT_EQ(0, stapleObj->staplesContainerSize());
}

TEST_F(StaplesModel_Test, addStaple)
{
    QDateTime date = QDateTime::fromString("2010-10-25T10:28:58.570Z", "yyyy-MM-ddTHH:mm:ss.zzzZ");
    stapleObj->addStaple(date, "Test Model", 0.78, 3);
    stapleObj->addStaple(date, "Test Model", 0.78, 3);

    EXPECT_EQ(2, stapleObj->staplesContainerSize());
}

TEST_F(StaplesModel_Test, clearListOfStaples)
{
    QDateTime date = QDateTime::fromString("2010-10-25T10:28:58.570Z", "yyyy-MM-ddTHH:mm:ss.zzzZ");
    stapleObj->addStaple(date, "clearListOfStaples", 0.78, 3);
    stapleObj->addStaple(date, "clearListOfStaples", 0.78, 3);

    EXPECT_EQ(2, stapleObj->staplesContainerSize());
    stapleObj->clearListOfStaples();
    EXPECT_EQ(0, stapleObj->staplesContainerSize());
}

TEST_F(StaplesModel_Test, displayListOfStaples)
{
    QDateTime date = QDateTime::fromString("2010-10-25T10:28:58.570Z", "yyyy-MM-ddTHH:mm:ss.zzzZ");
    stapleObj->addStaple(date, "clearListOfStaples", 0.78, 3);
    stapleObj->addStaple(date, "clearListOfStaples", 0.78, 3);
    EXPECT_EQ(0, stapleObj->displayListOfStaples());
    stapleObj->clearListOfStaples();
    EXPECT_EQ(1, stapleObj->displayListOfStaples());
}
