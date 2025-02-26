#ifndef BIGUNSIGNED_HPP
#define BIGUNSIGNED_HPP

#include <iostream>
#include <vector>
#include <string>

template <unsigned char Base>
class BigUnsigned {
private:
    std::vector<unsigned char> digits;

public:
    // Constructores
    BigUnsigned(const char* str);
    
    // Operador de asignación
    BigUnsigned& operator=(const BigUnsigned& other);

    // Operadores de flujo
    template <unsigned char B>
    friend std::ostream& operator<<(std::ostream& out, const BigUnsigned<B>& num);

    // Operaciones aritméticas
    BigUnsigned operator+(const BigUnsigned& other) const;
    BigUnsigned operator-(const BigUnsigned& other) const;
    BigUnsigned operator*(const BigUnsigned& other) const;
    BigUnsigned operator/(const BigUnsigned& other) const;

    // Conversión a decimal
    unsigned long long to_decimal() const;
};

#endif