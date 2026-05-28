//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_DIVISIONEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_DIVISIONEXPRESSION_H
#include "BinaryExpression.h"


class DivisionExpression : public BinaryExpression {

private:
    static constexpr double EPSILON = 0.00001;

public:

    DivisionExpression() = default;
    DivisionExpression(std::unique_ptr<IExpression> expression1, std::unique_ptr<IExpression> expression2) :
    BinaryExpression(std::move(expression1), std::move(expression2), '/'){}

    [[nodiscard]] double evaluate() const override;

    ~DivisionExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_DIVISIONEXPRESSION_H
