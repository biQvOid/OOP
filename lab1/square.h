#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"


class Square : Figure
{
public:
    Square(std::istream& is);
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);

private:
    Point a_;
    Point b_;
    Point c_;
    Point d_;
};

#endif
