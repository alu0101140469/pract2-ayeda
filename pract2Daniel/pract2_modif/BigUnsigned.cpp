#include "BigUnsigned.hpp"

#include <cstring>

// Constructor desde cadena de caracteres
template <unsigned char Base>
BigUnsigned<Base>::BigUnsigned(const char* str) {
    for (int i = strlen(str) - 1; i >= 0; --i) {
        digits.push_back(str[i] - '0');
    }
}

// Operación de suma
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator+(const BigUnsigned<Base>& other) const {
    BigUnsigned<Base> result("0");
    return result;
}

// Conversión a decimal
template <unsigned char Base>
unsigned long long BigUnsigned<Base>::to_decimal() const {
    unsigned long long value = 0;
    unsigned long long power = 1;
    for (auto digit : digits) {
        value += digit * power;
        power *= Base;
    }
    return value;
}

// Operador de salida
template <unsigned char Base>
std::ostream& operator<<(std::ostream& out, const BigUnsigned<Base>& num) {
    for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
        out << static_cast<char>((*it) + '0');
    }
    return out;
}

// Instanciaciones explícitas para obligar al compilador a generar las clases necesarias
template class BigUnsigned<2>;
template class BigUnsigned<8>;
template class BigUnsigned<10>;
template class BigUnsigned<16>;

template std::ostream& operator<<(std::ostream&, const BigUnsigned<2>&);
template std::ostream& operator<<(std::ostream&, const BigUnsigned<8>&);
template std::ostream& operator<<(std::ostream&, const BigUnsigned<10>&);
template std::ostream& operator<<(std::ostream&, const BigUnsigned<16>&);