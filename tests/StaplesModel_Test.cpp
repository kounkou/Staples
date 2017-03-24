
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
