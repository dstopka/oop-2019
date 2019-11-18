#include <Displacement.h>
#include <Acceleration.h>
#include <Speed.h>
#include "Observable.h"
#include "TestIncludes.h"

TEST(Observer, WorkingOrNot)
{
    Displacement displacement;
    Speed speed;
    Acceleration acceleration;

    displacement.registerObserver(&acceleration);
    displacement.registerObserver(&speed);
    
    displacement.set(10);
    displacement.set(11);
    EXPECT_EQ(1, speed.get());
    
    displacement.set(13);
    EXPECT_EQ(2, speed.get());
    EXPECT_EQ(1, acceleration.get());
    
    displacement.set(16);
    EXPECT_EQ(3, speed.get());
    EXPECT_EQ(1, acceleration.get());
}
