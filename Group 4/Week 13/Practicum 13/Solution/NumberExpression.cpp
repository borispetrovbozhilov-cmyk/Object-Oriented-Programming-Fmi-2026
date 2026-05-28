//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "NumberExpression.h"

double NumberExpression::evaluate() const {
    return value;
}

std::string NumberExpression::toString() const {
    return std::to_string(value);
}
