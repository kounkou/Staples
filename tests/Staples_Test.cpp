
#include "Staples.cpp"
#include <gtest/gtest.h>
#include <memory>

class Staples_Test : public ::testing::Test
{
public:
    std::unique_ptr<Staples> staplesObj;

    Staples_Test()
    {
        staplesObj = std::unique_ptr<Staples>(new Staples);
    }

   ~Staples_Test()
    {
        // nothing here as we use smart pointers
    }

protected:
   virtual void SetUp()    {}
   virtual void TearDown() {}
};


TEST_F(Staples_Test, getSizeOfStaplesList)
{
   // TEST_DESCRIPTION("This test will check the value of Staples at initialization");

   EXPECT_EQ(0, staplesObj->getSizeOfStaplesList()); 
}
