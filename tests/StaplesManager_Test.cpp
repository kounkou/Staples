
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
    QVariantMap map;
    map.insert("integer", 1);
    map.insert("double", 2.34);
    map.insert("bool", QVariant(true));
    map.insert("string", "word");
    QJsonObject object = QJsonObject::fromVariantMap(map);
    QJsonDocument doc;
    doc.setObject(object);

    EXPECT_EQ(1, stapleObj->retrieveStaples(doc));
}
