#ifndef CardSystem_ZoneB_INCLUDED
#define CardSystem_ZoneB_INCLUDED

#include "CardSystem/ZoneRateInterface.h"

class ZoneB : public ZoneRateInterface {
public:
    ZoneB() = default;
    int day() override;
    int week() override;
    int month() override;
    int single() override;

};


#endif
