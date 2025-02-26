#ifndef BIGINTEGER_HPP
#define BIGINTEGER_HPP

#include "BigUnsigned.hpp"

template <unsigned char Base>
class BigInteger {
private:
    BigUnsigned<Base> number;
    bool isNegative;

public:
    // Constructores
    BigInteger(int n = 0);
    BigInteger(const BigUnsigned<Base>& bigUnsigned);

    // Operadores de salida
    template <unsigned char B>
    friend std::ostream& operator<<(std::ostream& out, const BigInteger<B>& num);

    // Módulo
    BigInteger operator%(const BigInteger& other) const;
};

#endif