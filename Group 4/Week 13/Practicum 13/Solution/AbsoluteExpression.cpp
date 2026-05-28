//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "AbsoluteExpression.h"

double AbsoluteExpression::evaluate() const {

    return std::abs(expression->evaluate());
}

std::string AbsoluteExpression::toString() const {

    return "|" + expression->toString() + "|";
}
