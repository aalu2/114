#include <iostream>
#include <cstring>
#include <algorithm>

class HugeInteger {
public:
    // Default constructor
    HugeInteger();
    // Constructor with initialization from a string
    HugeInteger(const char* number);
    // Input method
    void input(const char* number);
    // Output method
    void output() const;
    // Addition method
    HugeInteger add(const HugeInteger& other) const;
    // Subtraction method
    HugeInteger subtract(const HugeInteger& other) const;
    // Equality check
    bool isEqualTo(const HugeInteger& other) const;
    // Inequality check
    bool isNotEqualTo(const HugeInteger& other) const;
    // Greater than check
    bool isGreaterThan(const HugeInteger& other) const;
    // Less than check
    bool isLessThan(const HugeInteger& other) const;
    // Greater than or equal to check
    bool isGreaterThanOrEqualTo(const HugeInteger& other) const;
    // Less than or equal to check
    bool isLessThanOrEqualTo(const HugeInteger& other) const;
    // Zero check
    bool isZero() const;
    // Multiplication method
    HugeInteger multiply(const HugeInteger& other) const;
    // Division method
    HugeInteger divide(const HugeInteger& other) const;
    // Modulus method
    HugeInteger modulus(const HugeInteger& other) const;

private:
    static const int SIZE = 40;
    int digits[SIZE];

    // Helper method to initialize array with zeros
    void zeroOut();
};

// Default constructor
HugeInteger::HugeInteger() {
    zeroOut();
}

// Constructor with initialization from a string
HugeInteger::HugeInteger(const char* number) {
    zeroOut();
    input(number);
}

// Method to input a number from a string
void HugeInteger::input(const char* number) {
    int length = strlen(number);
    int startIndex = SIZE - length;

    for (int i = 0; i < length; ++i) {
        digits[startIndex + i] = number[i] - '0';
    }
}

// Method to output the number
void HugeInteger::output() const {
    int i = 0;
    while (digits[i] == 0 && i < SIZE - 1) {
        ++i;
    }

    while (i < SIZE) {
        std::cout << digits[i++];
    }
}

// Addition method
HugeInteger HugeInteger::add(const HugeInteger& other) const {
    HugeInteger result;
    int carry = 0;

    for (int i = SIZE - 1; i >= 0; --i) {
        result.digits[i] = digits[i] + other.digits[i] + carry;
        carry = result.digits[i] / 10;
        result.digits[i] %= 10;
    }

    return result;
}

// Subtraction method
HugeInteger HugeInteger::subtract(const HugeInteger& other) const {
    HugeInteger result;
    int borrow = 0;

    for (int i = SIZE - 1; i >= 0; --i) {
        result.digits[i] = digits[i] - other.digits[i] - borrow;
        if (result.digits[i] < 0) {
            result.digits[i] += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
    }

    return result;
}

// Equality check
bool HugeInteger::isEqualTo(const HugeInteger& other) const {
    for (int i = 0; i < SIZE; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}

// Inequality check
bool HugeInteger::isNotEqualTo(const HugeInteger& other) const {
    return !isEqualTo(other);
}

// Greater than check
bool HugeInteger::isGreaterThan(const HugeInteger& other) const {
    for (int i = 0; i < SIZE; ++i) {
        if (digits[i] > other.digits[i]) {
            return true;
        } else if (digits[i] < other.digits[i]) {
            return false;
        }
    }
    return false;
}

// Less than check
bool HugeInteger::isLessThan(const HugeInteger& other) const {
    return !isGreaterThan(other) && !isEqualTo(other);
}

// Greater than or equal to check
bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) const {
    return isGreaterThan(other) || isEqualTo(other);
}

// Less than or equal to check
bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) const {
    return !isGreaterThan(other);
}

// Zero check
bool HugeInteger::isZero() const {
    for (int i = 0; i < SIZE; ++i) {
        if (digits[i] != 0) {
            return false;
        }
    }
    return true;
}

// Multiplication method
HugeInteger HugeInteger::multiply(const HugeInteger& other) const {
    HugeInteger result;
    HugeInteger temp;
    int carry = 0;

    for (int i = SIZE - 1; i >= SIZE / 2; --i) {
        temp.zeroOut();
        for (int j = SIZE - 1; j >= SIZE / 2; --j) {
            temp.digits[i + j - SIZE] = digits[i] * other.digits[j] + carry;
            carry = temp.digits[i + j - SIZE] / 10;
            temp.digits[i + j - SIZE] %= 10;
        }
        result = result.add(temp);
    }

    return result;
}

// Division method
HugeInteger HugeInteger::divide(const HugeInteger& other) const {
    HugeInteger result;
    HugeInteger remainder(*this);

    while (remainder.isGreaterThanOrEqualTo(other)) {
        result.digits[0]++;
        remainder = remainder.subtract(other);
    }

    return result;
}

// Modulus method
HugeInteger HugeInteger::modulus(const HugeInteger& other) const {
    HugeInteger result(*this);
    while (result.isGreaterThanOrEqualTo(other)) {
        result = result.subtract(other);
    }
    return result;
}

// Helper method to initialize array with zeros
void HugeInteger::zeroOut() {
    for (int i = 0; i < SIZE; ++i) {
        digits[i] = 0;
    }
}

// Main function
int main() {
    // Test numbers
    HugeInteger h1("1234567890123456789012345678901234567890");
    HugeInteger h2("9876543210987654321098765432109876543210");

    // Perform arithmetic operations
    HugeInteger sum = h1.add(h2);
    HugeInteger difference = h1.subtract(h2);
    HugeInteger product = h1.multiply(h2);
    HugeInteger quotient = h1.divide(h2);
    HugeInteger mod = h1.modulus(h2);

    // Output results
    std::cout << "Sum: ";
    sum.output();
    std::cout << std::endl;

    std::cout << "Difference: ";
    difference.output();
    std::cout << std::endl;

    std::cout << "Product: ";
    product.output();
    std::cout << std::endl;
    std::cout << "Modulus: ";
    mod.output();
    std::cout << std::endl;
    return 0;
}

