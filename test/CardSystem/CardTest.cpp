#include <memory>
#include "gtest/gtest.h"
#include "CardSystem/Card.h"
#include "CardSystem/ZoneA.h"
#include "CardSystem/ZoneB.h"
#include "CardSystem/TimeService.h"
#include "CardSystem/BankAccount.h"

class CardTest : public ::testing::Test
{
protected:
    int accountBalance = 250;
    std::string timeOfCardUse = "2021-04-20 00:00";

};

TEST_F(CardTest, ChargeZoneASingleRate)
{
    TimeService timeService;
    BankAccount account(accountBalance);
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneA>());

    ASSERT_EQ(account.balance(), 244);
}

TEST_F(CardTest, ChargeZoneADayRate)
{
    BankAccount account(accountBalance);
    TimeService timeService("2021-04-19 00:00");
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneA>());

    ASSERT_EQ(account.balance(), 240);
}

TEST_F(CardTest, ChargeZoneAWeekRate)
{
    BankAccount account(accountBalance);
    TimeService timeService("2021-04-13 00:00");
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneA>());

    ASSERT_EQ(account.balance(), 220);
}

TEST_F(CardTest, ChargeZoneAMonthRate)
{
    BankAccount account(accountBalance);
    TimeService timeService("2021-03-20 00:00");
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneA>());

    ASSERT_EQ(account.balance(), 120);
}

TEST_F(CardTest, ChargeZoneBSingleRate)
{
    TimeService timeService;
    BankAccount account(accountBalance);
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneB>());

    ASSERT_EQ(account.balance(), 243);
}

TEST_F(CardTest, ChargeZoneBDayRate)
{
    BankAccount account(accountBalance);
    TimeService timeService("2021-04-19 00:00");
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneB>());

    ASSERT_EQ(account.balance(), 238);
}

TEST_F(CardTest, ChargeZoneBWeekRate)
{
    BankAccount account(accountBalance);
    TimeService timeService("2021-04-13 00:00");
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneB>());

    ASSERT_EQ(account.balance(), 205);
}

TEST_F(CardTest, ChargeZoneBMonthRate)
{
    BankAccount account(accountBalance);
    TimeService timeService("2021-03-20 00:00");
    auto card = Card(account, timeService);

    card.currentTimeOfUse(timeOfCardUse);
    card.pass(std::make_unique<ZoneB>());

    ASSERT_EQ(account.balance(), 80);
}
