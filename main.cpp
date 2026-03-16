#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class BankAccount
{
private:
    std::string owner;
    double balance;
    int pin;

public:
    BankAccount(std::string name, double initialDeposit, int initialPin)
    {
        owner = name;
        pin = initialPin;

        if (initialDeposit >= 0)
        {
            balance = initialDeposit;
        }
        else
        {
            balance = 0;
            std::cout << "Warning: Initial deposit cannot be negatice. Setting balance to 0.";
        }
    }

    void showInfo() const
    {
        std::cout << "Owner: " << owner << "| Balance: $" << std::fixed << std::setprecision(0) << balance << '\n';
    }

    bool withrawMoney(double amount, int enteredPin)
    {
        if (enteredPin != pin)
        {
            std::cout << "Pin invalid try again...";
            return false;
        }
        if (amount > balance)
        {
            std::cout << "the amount is higher than your current balance, please enter a smaller amount.";
            return false;
        }

        balance -= amount;
        std::cout << "Processing... Withdrawal of $" << std::fixed << std::setprecision(0) << amount << " successful!\n";
        return true;
    }

    bool depositAmount(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "ERROR: Deposit amount mus be positive\n";
        };

        balance += amount;
        std::cout << "deposit success..";
        return true;
    }
};

int main()
{
    std::vector<BankAccount> accounts{};
    std::string temporalName;
    double temporalDesposit{};
    int temporalPin{};
    bool keepRunning{true};

    std::cout << "|-----Creating Account-----|\n";

    std::cout << "Enter your FullName: ";
    std::getline(std::cin >> std::ws, temporalName);

    std::cout << "Initial Deposit: ";
    std::cin >> temporalDesposit;

    std::cout << "Set your PIN (numbers only): ";
    std::cin >> temporalPin;

    accounts.push_back(BankAccount(temporalName, temporalDesposit, temporalPin));
    std::cout << "\nAccount created successfully!\n";

    return 0;
}