#ifndef BIGRATIONAL_HPP
#define BIGRATIONAL_HPP

#include "BigInteger.hpp"

template <unsigned char Base>
class BigRational {
private:
    BigInteger<Base> numerator;
    BigUnsigned<Base> denominator;

public:
    // Constructor
    BigRational(const BigInteger<Base>& num = 0, const BigUnsigned<Base>& den = 1);

    // Operaciones aritméticas
    BigRational operator+(const BigRational& other) const;
    BigRational operator-(const BigRational& other) const;
    BigRational operator*(const BigRational& other) const;
    BigRational operator/(const BigRational& other) const;

    // Comparación
    bool operator==(const BigRational& other) const;
    bool operator<(const BigRational& other) const;

    // Operador de salida
    template <unsigned char B>
    friend std::ostream& operator<<(std::ostream& out, const BigRational<B>& num);
};

#endif