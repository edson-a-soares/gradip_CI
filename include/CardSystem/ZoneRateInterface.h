#ifndef CardSystem_ZoneRateInterface_INCLUDED
#define CardSystem_ZoneRateInterface_INCLUDED

class ZoneRateInterface {
public:
    ~ZoneRateInterface() = default;
    virtual int day() = 0;
    virtual int week() = 0;
    virtual int month() = 0;
    virtual int single() = 0;

};

#endif
