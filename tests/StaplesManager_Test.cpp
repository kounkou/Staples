
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

TEST_F(StaplesManager_Test, retrieveStaples_Wrong)
{
    QString data_faulty("{\"status\":\"nok\",\"data\": {\"staples\": {\"s1\" :{ \"exp\"  :"
                        " \"Jan 28 2018\", \"name\" : \"BÃ©nÃ©dicta Mayo\", \"price\" : \"1.00\", \"qty\" : \"1\" }}}}");
    QJsonDocument doc_faulty = QJsonDocument::fromJson(data_faulty.toUtf8());

    /* This test will evaluate a syntaxically correct but wrong (from Staples POV) json document */
    EXPECT_EQ(1, stapleObj->retrieveStaples(doc_faulty));
}

TEST_F(StaplesManager_Test, retrieveStaples_Right)
{
    QString data_spare("{\"status\":\"ok\",\"data\": {\"staples\": {\"s1\" :{ \"exp\"  :"
                       " \"Jan 28 2018\", \"name\" : \"BÃ©nÃ©dicta Mayo\", \"price\" : \"1.00\", \"qty\" : \"1\" }}}}");
    QJsonDocument doc_spare = QJsonDocument::fromJson(data_spare.toUtf8());

    /* This test will evaluate a syntaxically correct but right (from Staples POV) json document */
    EXPECT_EQ(0, stapleObj->retrieveStaples(doc_spare));
}

TEST_F(StaplesManager_Test, authentificate)
{
    QString data_auth("{\"status\":\"ok\",\"data\": {\"staples\": {\"s1\" :{ \"exp\"  :"
                       " \"Jan 28 2018\", \"name\" : \"BÃ©nÃ©dicta Mayo\", \"price\" : \"1.00\", \"qty\" : \"1\" }}}}");
    QJsonDocument doc_auth = QJsonDocument::fromJson(data_auth.toUtf8());

    EXPECT_EQ(0, stapleObj->authentificates(doc_auth));
}
