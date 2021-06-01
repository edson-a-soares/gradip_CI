#include "gtest/gtest.h"
#include "CardSystem/TimeService.h"

class TimeServiceTest : public ::testing::Test
{
protected:
    std::string newTimeOfUse = "2021-04-20 00:00";

};

TEST_F(TimeServiceTest, CalculateTimeForSingleRate)
{
    TimeService timeService;
    ASSERT_EQ(timeService.calculate(newTimeOfUse), Rate::SINGLE);
}

TEST_F(TimeServiceTest, CalculateTimeForDayRate)
{
    TimeService timeService("2021-04-19 00:00");
    ASSERT_EQ(timeService.calculate(newTimeOfUse), Rate::DAY);
}

TEST_F(TimeServiceTest, CalculateTimeForWeekRate)
{
    TimeService timeService("2021-04-13 00:00");
    ASSERT_EQ(timeService.calculate(newTimeOfUse), Rate::WEEK);
}

TEST_F(TimeServiceTest, CalculateTimeForMonthRate)
{
    TimeService timeService("2021-03-20 00:00");
    ASSERT_EQ(timeService.calculate(newTimeOfUse), Rate::MONTH);
}
