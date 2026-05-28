//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(std::unique_ptr<IExpression> expression1, std::unique_ptr<IExpression> expression2,
    const char expressionOperator) :
expression1(std::move(expression1)), expression2(std::move(expression2)), expressionOperator(expressionOperator) {

    if (expression1 == nullptr)
        throw std::invalid_argument("Can't use an empty pointer to set expression value in BinaryExpression");
    if (expression2 == nullptr)
        throw std::invalid_argument("Can't use an empty pointer to set expression value in BinaryExpression");
}

std::string BinaryExpression::toString() const {

    return expression1->toString() + " " + expressionOperator + " " + expression2->toString();
}
