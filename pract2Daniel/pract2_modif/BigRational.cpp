#include "BigRational.hpp"

// Constructor
template <unsigned char Base>
BigRational<Base>::BigRational(const BigInteger<Base>& num, const BigUnsigned<Base>& den)
    : numerator(num), denominator(den) {}

// Vector


// Suma
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator+(const BigRational<Base>& other) const {
    BigInteger<Base> newNum = numerator * other.denominator + other.numerator * denominator;
    BigUnsigned<Base> newDen = denominator * other.denominator;
    return BigRational<Base>(newNum, newDen);
}

// Resta
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator-(const BigRational<Base>& other) const {
    BigInteger<Base> newNum = numerator * other.denominator - other.numerator * denominator;
    BigUnsigned<Base> newDen = denominator * other.denominator;
    return BigRational<Base>(newNum, newDen);
}

// Multiplicación
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator*(const BigRational<Base>& other) const {
    return BigRational<Base>(numerator * other.numerator, denominator * other.denominator);
}

// División
template <unsigned char Base>
BigRational<Base> BigRational<Base>::operator/(const BigRational<Base>& other) const {
    return BigRational<Base>(numerator * other.denominator, denominator * other.numerator);
}

// Comparación
template <unsigned char Base>
bool BigRational<Base>::operator==(const BigRational<Base>& other) const {
    return (numerator * other.denominator) == (other.numerator * denominator);
}

template <unsigned char Base>
bool BigRational<Base>::operator<(const BigRational<Base>& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}