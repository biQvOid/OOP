#ifndef FAZZYNUMBER_H
#define FAZZYNUMBER_H

#include <iostream>

class FazzyNumber
{
public:
    FazzyNumber operator+(const FazzyNumber& N);
    FazzyNumber operator-(const FazzyNumber& N);
    FazzyNumber operator*(const FazzyNumber& N);
    FazzyNumber operator/(const FazzyNumber& N);

    bool operator<(const FazzyNumber& N);
    bool operator>(const FazzyNumber& N);
    bool operator==(const FazzyNumber& N);
    bool operator<=(const FazzyNumber& N);
    bool operator>=(const FazzyNumber& N);
    bool operator!=(const FazzyNumber& N);

    friend std::ostream& operator<<(std::ostream& os, FazzyNumber other);
    friend std::istream& operator>>(std::istream& is, FazzyNumber other);

    FazzyNumber get_opposite();

    FazzyNumber(float l, float x, float r): l(l), x(x), r(r) {}
    FazzyNumber(): l(0), x(0), r(0) {} 

private:
    float l, x, r;
};

#endif 