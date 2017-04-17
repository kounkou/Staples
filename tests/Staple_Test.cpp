
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


TEST_F(Staple_Test, expirationDate)
{
   EXPECT_EQ("", stapleObj->expirationDate().toString());
}

TEST_F(Staple_Test, getStapleName)
{
   std::string stapleName("");
   EXPECT_EQ(stapleName, stapleObj->name());
}

TEST_F(Staple_Test, getStaplePrice)
{
   EXPECT_EQ(0, stapleObj->price());
}

TEST_F(Staple_Test, getStapleQuantity)
{
    EXPECT_EQ(0, stapleObj->quantity());
}

TEST_F(Staple_Test, Staple)
{
    QDateTime date = QDateTime::fromString("2010-10-25T10:28:58.570Z", "yyyy-MM-ddTHH:mm:ss.zzzZ");

    Staple st(date, "TestSt", 0.67f, 2);

    EXPECT_EQ("2010-10-25T10:28:58.570Z", st.expirationDate().toString("yyyy-MM-ddTHH:mm:ss.zzzZ"));
    EXPECT_EQ("TestSt",       st.name());
    EXPECT_EQ(0.67f,          st.price());
    EXPECT_EQ(2,              st.quantity());
}
