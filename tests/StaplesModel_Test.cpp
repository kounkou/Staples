
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

TEST_F(StaplesModel_Test, data)
{
    QModelIndex index;
    QVariant var = stapleObj->data(index, NameRole);

    EXPECT_EQ(true,  var != "");
}

TEST_F(StaplesModel_Test, addStaple)
{
    stapleObj->addStaple("Jan 01 2017", "Test Model", 0.78, 3);
    stapleObj->addStaple("Jan 01 2017", "Test Model", 0.78, 3);

    EXPECT_EQ(2, stapleObj->staplesContainerSize());
}

TEST_F(StaplesModel_Test, clearListOfStaples)
{
    stapleObj->addStaple("Jan 01 2017", "clearListOfStaples", 0.78, 3);
    stapleObj->addStaple("Jan 01 2017", "clearListOfStaples", 0.78, 3);

    EXPECT_EQ(2, stapleObj->staplesContainerSize());
    stapleObj->clearListOfStaples();
    EXPECT_EQ(0, stapleObj->staplesContainerSize());
}
