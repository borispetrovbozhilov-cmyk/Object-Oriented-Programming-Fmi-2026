//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ADDITIONEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ADDITIONEXPRESSION_H
#include "BinaryExpression.h"


class AdditionExpression : public BinaryExpression {

public:

    AdditionExpression() = default;
    AdditionExpression(std::unique_ptr<IExpression> expression1, std::unique_ptr<IExpression> expression2) :
    BinaryExpression(std::move(expression1), std::move(expression2), '+'){}

    [[nodiscard]] double evaluate() const override;

    ~AdditionExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ADDITIONEXPRESSION_H
