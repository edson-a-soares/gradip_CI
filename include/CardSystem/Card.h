#ifndef CardSystem_Card_INCLUDED
#define CardSystem_Card_INCLUDED

#include <memory>
#include <string>
#include "CardSystem/BankAccount.h"
#include "CardSystem/TimeService.h"
#include "CardSystem/ZoneRateInterface.h"

class Card {
public:
    Card() = delete;
    Card(BankAccount &, TimeService );
    void currentTimeOfUse(std::string time);
    void pass(std::unique_ptr<ZoneRateInterface> zone);

private:
    BankAccount & _account;
    TimeService timeService;
    std::string _currentTimeOfUse;

};

#endif
