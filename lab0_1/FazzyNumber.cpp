#include "FazzyNumber.h"

FazzyNumber FazzyNumber::operator+(const FazzyNumber& N)
{
    return FazzyNumber(this->l + N.l, this->x + N.x, this->r + N.r);
}

FazzyNumber FazzyNumber::operator-(const FazzyNumber& N)
{
    return FazzyNumber(this->l - N.r, this->x - N.x, this->r - N.l);
}

FazzyNumber FazzyNumber::operator*(const FazzyNumber& N)
{
    return FazzyNumber(this->l * N.l, this->x * N.x, this->r * N.r);
}

FazzyNumber FazzyNumber::operator/(const FazzyNumber& N)
{   
    if (N.x <= 0) {
        throw std::invalid_argument("Operation A/B, where B < 0\n");
    }
    return FazzyNumber(this->l / N.r, this->x / N.x, this->r / N.l);
}

FazzyNumber FazzyNumber::get_opposite()
{
    if (this->x <= 0) {
        throw std::invalid_argument("Operation of getting opposite of A, where A < 0\n");
    }
    return FazzyNumber(1 / this->r, 1 / this->x, 1 / this->l);
}

bool FazzyNumber::operator<(const FazzyNumber& N)
{
    return this->x < N.x;
}

bool FazzyNumber::operator>(const FazzyNumber& N)
{
    return this->x > N.x;
}

bool FazzyNumber::operator==(const FazzyNumber& N)
{
    return this->x == N.x;
}

bool FazzyNumber::operator<=(const FazzyNumber& N)
{
    return this->x <= N.x;
}

bool FazzyNumber::operator>=(const FazzyNumber& N)
{
    return this->x >= N.x;
}

bool FazzyNumber::operator!=(const FazzyNumber& N)
{
    return this->x != N.x;
}

std::ostream& operator<<(std::ostream& os, FazzyNumber other)
{
    os << "(" << other.l << ", " << other.x << ", " << other.r << ")";
    return os;
}
    
std::istream& operator>>(std::istream& is, FazzyNumber other)
{
    is >> other.l >> other.x >> other.r;
    return is;
}