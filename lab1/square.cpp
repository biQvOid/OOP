#include "square.h"

Square::Square(std::istream& is)
{
    std::cin >> a_ >> b_ >> c_ >> d_;
}

size_t Square::VertexesNumber()
{
    return (size_t)4;
}

double Square::Area()
{
    int a = a_.dist(b_);
    return a * a;
}

void Square::Print(std::ostream& os)
{
    std::cout << "Square: " << a_ << " " << b_ << " " << c_ << " " << d_ << "\n";
}
