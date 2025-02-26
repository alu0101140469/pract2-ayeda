#include "BigInteger.hpp"

// Constructor desde un BigInteger
template <unsigned char Base>
BigInteger<Base>::BigInteger(int n) : number(std::to_string(std::abs(n)).c_str()), isNegative(n < 0) {}

// Constructor desde un BigUnsigned
template <unsigned char Base>
BigInteger<Base>::BigInteger(const BigUnsigned<Base>& bigUnsigned) : number(bigUnsigned), isNegative(false) {}

// Operador de salida
template <unsigned char Base>
std::ostream& operator<<(std::ostream& out, const BigInteger<Base>& num) {
    if (num.isNegative) {
        out << "-";
    }
    out << num.number;
    return out;
}

// Operador módulo
template <unsigned char Base>
BigInteger<Base> BigInteger<Base>::operator%(const BigInteger<Base>& other) const {
    unsigned long long num1 = number.to_decimal();
    unsigned long long num2 = other.number.to_decimal();
    unsigned long long modResult = num1 % num2;

    return BigInteger<Base>(modResult);
}

// Instanciaciones explícitas para obligar al compilador a generar las clases necesarias
template class BigInteger<2>;
template class BigInteger<8>;
template class BigInteger<10>;
template class BigInteger<16>;

template std::ostream& operator<<(std::ostream&, const BigInteger<2>&);
template std::ostream& operator<<(std::ostream&, const BigInteger<8>&);
template std::ostream& operator<<(std::ostream&, const BigInteger<10>&);
template std::ostream& operator<<(std::ostream&, const BigInteger<16>&);