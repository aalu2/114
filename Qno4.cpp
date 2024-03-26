#include <iostream>

class SavingsAccount {
private:
    static double annualInterestRate; // Static member to store the annual interest rate
    double savingsBalance; // Amount the saver currently has on deposit

public:
    SavingsAccount(double balance) : savingsBalance(balance) {} // Constructor to set initial balance

    void calculateMonthlyInterest() { // Calculates and adds monthly interest
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
        savingsBalance += monthlyInterest;
    }

    static void modifyInterestRate(double newInterestRate) { // Modifies the annual interest rate
        annualInterestRate = newInterestRate;
    }

    double getBalance() const {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.03; // Initialize the static annualInterestRate

int main() {
    // Instantiate two different objects of class SavingsAccount
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Saver 1: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver 2: $" << saver2.getBalance() << std::endl;

    // Set the annualInterestRate to 3 percent
    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nBalances after 1 month at 3% interest rate:" << std::endl;
    std::cout << "Saver 1: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver 2: $" << saver2.getBalance() << std::endl;

    // Set the annualInterestRate to 4 percent
    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nBalances after 1 more month at 4% interest rate:" << std::endl;
    std::cout << "Saver 1: $" << saver1.getBalance() << std::endl;
    std::cout << "Saver 2: $" << saver2.getBalance() << std::endl;

    return 0;
}
