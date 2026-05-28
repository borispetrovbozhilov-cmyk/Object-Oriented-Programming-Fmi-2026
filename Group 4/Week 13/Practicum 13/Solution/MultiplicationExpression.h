//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MULTIPLICATIONEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MULTIPLICATIONEXPRESSION_H
#include "BinaryExpression.h"


class MultiplicationExpression : public BinaryExpression {

public:

    MultiplicationExpression() = default;
    MultiplicationExpression(std::unique_ptr<IExpression> expression1, std::unique_ptr<IExpression> expression2) :
    BinaryExpression(std::move(expression1), std::move(expression2), '*'){}

    [[nodiscard]] double evaluate() const override;

    ~MultiplicationExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MULTIPLICATIONEXPRESSION_H
