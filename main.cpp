#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Digital Bank Vault - Object Oriented Implementation
class BankAccount
{
protected:
    // Private attributes: These are protected by encapsulation
    std::string owner;
    double balance;
    int pin;

public:
    // Constructor: Initializes the object and validates initial business rules
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
            std::cout << "Warning: Initial deposit cannot be negative. Setting balance to 0.";
        }
    }

    // Displays account summary - Marked as 'const' because it doesn't modify data
    void showInfo() const
    {
        std::cout << "Owner: " << owner << " | Balance: $" << std::fixed << std::setprecision(0) << balance << '\n';
    }

    // Secured withdrawal method - Validates both identity (PIN) and funds
    bool withrawMoney(double amount, int enteredPin)
    {
        if (enteredPin != pin)
        {
            std::cout << "Pin invalid try again...";
            return false;
        }
        if (amount > balance)
        {
            std::cout << "The amount is higher than your current balance.\n";
            return false;
        }

        balance -= amount;
        std::cout << "Processing... Withdrawal of $" << std::fixed << std::setprecision(0) << amount << " successful!\n";
        return true;
    }

    // Deposit method - Ensures only positive transactions are allowed
    bool depositAmount(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "ERROR: Deposit amount must be positive\n";
            return false; // Stop execution if amount is invalid
        }

        balance += amount;
        std::cout << "Deposit successful!";
        return true;
    }
};

class SavingAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingAccount(std::string name, double deposit, int pin, double rate)
        : BankAccount(name, deposit, pin)
    {
        interestRate = rate;
    }

    void applyInterest()
    {
        double interest{balance * (interestRate / 100)};
        balance += interest;
        std::cout << "Interest applied: $" << interest << "success!n\n";
    }
};

int main()
{
    // Container to store our account objects
    std::vector<BankAccount> accounts{};
    std::vector<SavingAccount> savingAccounts{};

    // Temporal variables for data input/handling
    std::string temporalName;
    double temporalAmount{};
    int temporalPin{};
    bool keepRunning{true};

    std::cout << "|----- Creating Account -----|\n";

    std::cout << "Enter your Full Name: ";
    std::getline(std::cin >> std::ws, temporalName);

    std::cout << "Initial Deposit: ";
    std::cin >> temporalAmount;

    std::cout << "Set your PIN (numbers only): ";
    std::cin >> temporalPin;

    // Instantiate the object and move it into the vector
    accounts.push_back(BankAccount(temporalName, temporalAmount, temporalPin));
    std::cout << "\nAccount created successfully!\n\n";

    // Main interaction loop
    while (keepRunning)
    {
        int optionChoise{};
        int confirmPin{};

        accounts[0].showInfo();
        std::cout << "\n|---------------- BANK OPTIONS ---------------|\n\n";
        std::cout
            << " 1. Deposit Money |"
            << " 2. Withdraw Money |"
            << " 3. Exit |\n\n"
            << "Choice: ";

        std::cin >> optionChoise;

        switch (optionChoise)
        {
        case 1:
            std::cout << "How much do you want to deposit? ";
            std::cin >> temporalAmount;
            accounts[0].depositAmount(temporalAmount);
            break;

        case 2:
            std::cout << "How much do you want to withdraw? ";
            std::cin >> temporalAmount;
            std::cout << "Please enter your PIN to authorize: ";
            std::cin >> confirmPin;

            // Critical fix: passing confirmPin to validate the transaction
            accounts[0].withrawMoney(temporalAmount, confirmPin);
            break;

        case 3:
            keepRunning = false;
            break;

        default:
            std::cout << "Invalid option.\n";
        }
    }

    std::cout << "See you soon...";
    return 0;
}