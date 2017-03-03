
#include "Staple.cpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

class Staple_Test : public ::testing::Test
{
public:
    std::unique_ptr<Staple> stapleObj;

    Staple_Test()
    {
        stapleObj = std::unique_ptr<Staple>(new Staple);
    }

   ~Staple_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};


TEST_F(Staple_Test, getNumberOfDaysBeforeExpiration)
{
   EXPECT_EQ(0, stapleObj->getNumberOfDaysBeforeExpiration());
}

TEST_F(Staple_Test, getStapleName)
{
   std::string stapleName("");
   EXPECT_EQ(stapleName, stapleObj->getStapleName());
}

TEST_F(Staple_Test, getStaplePrice)
{
   EXPECT_EQ(0, stapleObj->getStaplePrice());
}

