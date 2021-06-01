#ifndef CardSystem_InsufficientBalanceException_INCLUDED
#define CardSystem_InsufficientBalanceException_INCLUDED

#include <exception>

class InsufficientBalanceException : public std::exception {
public:
    const char * what() const noexcept override;

};

#endif
