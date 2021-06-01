#include "CardSystem/InsufficientBalanceException.h"

const char * InsufficientBalanceException::what() const noexcept {
    return "Insufficient balance for this operation.";
}
