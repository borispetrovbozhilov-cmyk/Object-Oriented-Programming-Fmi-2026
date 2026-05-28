//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_SUBTRACTIONEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_SUBTRACTIONEXPRESSION_H
#include "BinaryExpression.h"


class SubtractionExpression : public BinaryExpression {

public:

    SubtractionExpression() = default;
    SubtractionExpression(std::unique_ptr<IExpression> expression1, std::unique_ptr<IExpression> expression2) :
    BinaryExpression(std::move(expression1), std::move(expression2), '-'){}

    [[nodiscard]] double evaluate() const override;

    ~SubtractionExpression() override = default;
};


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_SUBTRACTIONEXPRESSION_H
