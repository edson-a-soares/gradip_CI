#include <utility>
#include <iostream>
#include "CardSystem/TimeService.h"

TimeService::TimeService(std::string lastTimeOfUse)
    : _lastTimeOfUse(std::move(lastTimeOfUse))
{}

std::chrono::system_clock::time_point TimeService::fromString(const std::string & anyTime)
{
    std::tm time = {};
    strptime(anyTime.c_str(), "%Y-%m-%d %H:%M", &time);
    return std::chrono::system_clock::from_time_t(std::mktime(&time));
}

Rate TimeService::calculate(const std::string & currentTime)
{
    using namespace std::chrono;
    typedef duration<int, std::ratio_multiply< hours::period, std::ratio<24> >::type> Days;

    if (_lastTimeOfUse.empty())
        return Rate::SINGLE;

    auto currentTimeOfUse   = fromString(currentTime);
    auto lastTimeOfUse      = fromString(_lastTimeOfUse);
    auto elapsedTime        = duration_cast<Days>(currentTimeOfUse - lastTimeOfUse).count();

    switch (elapsedTime) {
        case 1:
            return DAY;

        case 7:
            return WEEK;

        default:
            return MONTH;
    }
}
