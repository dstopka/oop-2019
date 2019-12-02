#include "Universe.h"
#include "TestIncludes.h"
#include "ObserverMock.h"
#include "SpaceMock.h"
#include "TimeMock.h"

//class Interface {
//public: virtual int test() = 0;
//
//
//};
//
//class Implementation : public Interface {
//public:
//    int test() override {
//        return 10;
//    }
//};
//
//class MyMock : public Interface {
//public:
//    MOCK_METHOD0(test, int());
//};
//
//class Dummy {
//    Interface &interface;
//public:
//    explicit Dummy(Interface &interface) : interface(interface) {}
//    int execute() {return interface.test(); }
//};
//
//
//TEST(Universe, Create)
//{
//    StrictMock<MyMock> myMock{};
//    Dummy dummy{myMock};
//
//    EXPECT_CALL(myMock, test()).WillOnce(Return(10));
//
//    EXPECT_EQ(10, dummy.execute());
//}


TEST(Universe, Create)
{
    StrictMock<ObserverMock> observerMock{};
    StrictMock<TimeMock> timeMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock, spaceMock, observerMock};

    EXPECT_CALL(timeMock, create(true));
    EXPECT_CALL(spaceMock, create(11));
    EXPECT_CALL(spaceMock, dimensions()).WillOnce(Return(11));
    EXPECT_CALL(observerMock, remember("How many dimensions there are?", std::to_string(11)));

    universe.create();
}

TEST(Universe, Simulate93)
{
    StrictMock<ObserverMock> observerMock{};
    StrictMock<TimeMock> timeMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock, spaceMock, observerMock};

    EXPECT_CALL(timeMock, now()).WillOnce(Return(9300000000)).WillOnce(Return(9300000001));
    EXPECT_CALL(observerMock, remember("Is there planet Earth?", "Yes!")).WillOnce(Return());
    EXPECT_CALL(timeMock, flow()).WillOnce(Return());
    universe.simulate(9300000001);
}

TEST(Universe, Simulate99)
{
    StrictMock<ObserverMock> observerMock{};
    StrictMock<TimeMock> timeMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock, spaceMock, observerMock};

    EXPECT_CALL(timeMock, now()).WillOnce(Return(9900000000)).WillOnce(Return(9900000001));
    EXPECT_CALL(observerMock, remember("Does life exist?", "Yes!")).WillOnce(Return());
    EXPECT_CALL(timeMock, flow()).WillOnce(Return());
    universe.simulate(9900000001);
}

TEST(Universe, Simulate138)
{
    StrictMock<ObserverMock> observerMock{};
    StrictMock<TimeMock> timeMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock, spaceMock, observerMock};

    EXPECT_CALL(timeMock, now()).WillOnce(Return(13800000000)).WillOnce(Return(13800000001));
    EXPECT_CALL(observerMock, remember("Have People evolved?", "Yes!")).WillOnce(Return());
    EXPECT_CALL(timeMock, flow()).WillOnce(Return());
    universe.simulate(13800000001);
}


