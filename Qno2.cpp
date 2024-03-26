#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;

    // Function to find the greatest common divisor (GCD)
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    // Function to reduce the fraction to its simplest form
    void reduceFraction() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

public:
    // Constructor with default values and reduction to simplest form
    Rational(int num = 1, int denom = 1) : numerator(num), denominator(denom) {
        reduceFraction();
    }

    // Function to add two Rational numbers
    Rational add(const Rational& other) {
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return Rational(resultNumerator, resultDenominator);
    }

    // Function to subtract two Rational numbers
    Rational subtract(const Rational& other) {
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return Rational(resultNumerator, resultDenominator);
    }

    // Function to multiply two Rational numbers
    Rational multiply(const Rational& other) {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        return Rational(resultNumerator, resultDenominator);
    }

    // Function to divide two Rational numbers
    Rational divide(const Rational& other) {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        return Rational(resultNumerator, resultDenominator);
    }

    // Function to print Rational numbers in the form a/b
    void printFraction() const {
        std::cout << numerator << "/" << denominator;
    }

    // Function to print Rational numbers in floating-point format
    void printFloat() const {
        double result = static_cast<double>(numerator) / denominator;
        std::cout << result;
    }
};

int main() {
    Rational r1(2, 4);  // r1 is initialized as 1/2
    Rational r2(3, 5);  // r2 is initialized as 3/5

    Rational sum = r1.add(r2);
    Rational difference = r1.subtract(r2);
    Rational product = r1.multiply(r2);
    Rational quotient = r1.divide(r2);

    std::cout << "Sum: ";
    sum.printFraction();
    std::cout << " or ";
    sum.printFloat();
    std::cout << std::endl;

    std::cout << "Difference: ";
    difference.printFraction();
    std::cout << " or ";
    difference.printFloat();
    std::cout << std::endl;

    std::cout << "Product: ";
    product.printFraction();
    std::cout << " or ";
    product.printFloat();
    std::cout << std::endl;

    std::cout << "Quotient: ";
    quotient.printFraction();
    std::cout << " or ";
    quotient.printFloat();
    std::cout << std::endl;

    return 0;
}
