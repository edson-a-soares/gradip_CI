#ifndef CardSystem_TimeService_INCLUDED
#define CardSystem_TimeService_INCLUDED

#include <memory>
#include <chrono>
#include "CardSystem/Rate.h"

class TimeService {
public:
    TimeService() = default;
    explicit TimeService(std::string lastTimeOfUse);
    Rate calculate(const std::string & currentTime);
private:
    std::string _lastTimeOfUse;

    std::chrono::system_clock::time_point fromString(const std::string & anyTime);

};

#endif
