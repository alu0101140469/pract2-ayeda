#include <iostream>
#include <fstream>
#include <variant>
#include <memory>
#include "BigRational.hpp"

int main() {
    std::ifstream inputFile("entrada.txt");
    if (!inputFile) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    unsigned char base;
    std::string label, equals;
    inputFile >> label >> equals >> base;  // Lee "Base = X"

    std::string n1_str, n2_str;
    inputFile >> label >> equals >> n1_str;  // Lee "N1 = ..."
    std::string num1 = n1_str.substr(0, n1_str.find('/'));
    std::string den1 = n1_str.substr(n1_str.find('/') + 1);

    inputFile >> label >> equals >> n2_str;  // Lee "N2 = ..."
    std::string num2 = n2_str.substr(0, n2_str.find('/'));
    std::string den2 = n2_str.substr(n2_str.find('/') + 1);

    inputFile.close();

    // Creación de los objetos BigRational según la base
    std::unique_ptr<BigRational<2>> number1_2, number2_2;
    std::unique_ptr<BigRational<8>> number1_8, number2_8;
    std::unique_ptr<BigRational<10>> number1_10, number2_10;
    std::unique_ptr<BigRational<16>> number1_16, number2_16;

    if (base == 2) {
        number1_2 = std::make_unique<BigRational<2>>(BigInteger<2>(num1.c_str()), BigUnsigned<2>(den1.c_str()));
        number2_2 = std::make_unique<BigRational<2>>(BigInteger<2>(num2.c_str()), BigUnsigned<2>(den2.c_str()));
    } else if (base == 8) {
        number1_8 = std::make_unique<BigRational<8>>(BigInteger<8>(num1.c_str()), BigUnsigned<8>(den1.c_str()));
        number2_8 = std::make_unique<BigRational<8>>(BigInteger<8>(num2.c_str()), BigUnsigned<8>(den2.c_str()));
    } else if (base == 10) {
        number1_10 = std::make_unique<BigRational<10>>(BigInteger<10>(num1.c_str()), BigUnsigned<10>(den1.c_str()));
        number2_10 = std::make_unique<BigRational<10>>(BigInteger<10>(num2.c_str()), BigUnsigned<10>(den2.c_str()));
    } else if (base == 16) {
        number1_16 = std::make_unique<BigRational<16>>(BigInteger<16>(num1.c_str()), BigUnsigned<16>(den1.c_str()));
        number2_16 = std::make_unique<BigRational<16>>(BigInteger<16>(num2.c_str()), BigUnsigned<16>(den2.c_str()));
    } else {
        std::cerr << "Base no disponible." << std::endl;
        return -1;
    }

    // Escribir en salida.txt
    std::ofstream outputFile("salida.txt");
    outputFile << "Base = " << (int)base << "\n";
    outputFile << "N1 = " << num1 << " / " << den1 << "\n";
    outputFile << "N2 = " << num2 << " / " << den2 << "\n";

    // Validar que number1 y number2 tienen la misma base
    if (number1.index() != number2.index()) {
        std::cerr << "Error: Los números tienen bases distintas y no pueden ser operados." << std::endl;
        return -1;
    }

    std::visit([&outputFile](auto&& n1, auto&& n2) {
        outputFile << "N1 == N2: " << (n1->operator==(*n2) ? "true" : "false") << "\n";
        outputFile << "N1 < N2: " << (n1->operator<(*n2) ? "true" : "false") << "\n";
        outputFile << "N1 + N2 = " << (*n1 + *n2) << "\n";
        outputFile << "N1 - N2 = " << (*n1 - *n2) << "\n";
        outputFile << "N1 * N2 = " << (*n1 * *n2) << "\n";
        outputFile << "N1 / N2 = " << (*n1 / *n2) << "\n";
    }, number1, number2);

    outputFile.close();

    return 0;
}