#include "CardSystem/Rate.h"
#include "CardSystem/Card.h"

Card::Card(BankAccount & account, TimeService  service)
    : _account(account),
      timeService(std::move(service))
{}

void Card::pass(std::unique_ptr<ZoneRateInterface> zone)
{
    Rate rate = timeService.calculate(_currentTimeOfUse);
    switch (rate) {
        case SINGLE:
            _account.withdrawal(zone->single());
            break;

        case DAY:
            _account.withdrawal(zone->day());
            break;

        case WEEK:
            _account.withdrawal(zone->week());
            break;

        case MONTH:
            _account.withdrawal(zone->month());
            break;
    }
}

void Card::currentTimeOfUse(std::string time)
{
    _currentTimeOfUse = std::move(time);
}
