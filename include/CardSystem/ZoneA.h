#ifndef CardSystem_ZoneA_INCLUDED
#define CardSystem_ZoneA_INCLUDED

#include "CardSystem/ZoneRateInterface.h"

class ZoneA : public ZoneRateInterface {
public:
    ZoneA() = default;
    int day() override;
    int week() override;
    int month() override;
    int single() override;

};


#endif
