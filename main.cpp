#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

/**
 * BASE CLASS: BankAccount
 * Represents the fundamental blueprint for any bank account.
 * Focuses on Encapsulation: hiding sensitive data (balance, pin).
 */
class BankAccount
{
protected: // Accessible by this class and its children (SavingAccount)
    std::string owner;
    double balance;
    int pin;

public:
    // CONSTRUCTOR: Initializes the "capsule" with starting data
    BankAccount(std::string name, double initialDeposit, int initialPin)
    {
        owner = name;
        pin = initialPin;

        // Data Validation: Ensuring the object starts in a valid state
        if (initialDeposit >= 0)
        {
            balance = initialDeposit;
        }
        else
        {
            balance = 0;
            std::cout << "Warning: Initial deposit cannot be negative. Setting balance to 0.\n";
        }
    }

    // PUBLIC INTERFACE: Methods allowed to interact with the private data
    void showInfo() const
    {
        std::cout << "Owner: " << owner << " | Balance: $" << std::fixed << std::setprecision(0) << balance << '\n';
    }

    bool withrawMoney(double amount, int enteredPin)
    {
        // Security Check
        if (enteredPin != pin)
        {
            std::cout << "Pin invalid. Try again...\n";
            return false;
        }
        // Business Rule Check
        if (amount > balance)
        {
            std::cout << "Insufficient funds.\n";
            return false;
        }

        balance -= amount; // Modifying protected data safely
        std::cout << "Withdrawal of $" << amount << " successful!\n";
        return true;
    }

    bool depositAmount(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "ERROR: Deposit amount must be positive.\n";
            return false;
        }
        balance += amount;
        std::cout << "Deposit successful!\n";
        return true;
    }
};

/**
 * DERIVED CLASS: SavingAccount
 * Inherits all logic from BankAccount but adds a specific "Interest" feature.
 * Example of Inheritance (Is-A relationship).
 */
class SavingAccount : public BankAccount
{
private:
    double interestRate; // Specific to savings only

public:
    SavingAccount(std::string name, double deposit, int pin, double rate)
        : BankAccount(name, deposit, pin) // Passing data to the Parent constructor
    {
        interestRate = rate;
    }

    // NEW SPECIALIZED BEHAVIOR
    void applyInterest()
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        std::cout << "Interest applied: $" << interest << " successfully!\n";
    }
};

int main()
{
    // Vectors to manage our created objects
    std::vector<BankAccount> accounts{};
    std::vector<SavingAccount> savingAccounts{};

    // Temporary variables for user input
    std::string temporalName;
    int accountType{};
    double temporalAmount{};
    int temporalPin{}, confirmPin{};
    bool keepRunning{true};
    bool isSavingMode{false};

    std::cout << "|----- BANK SYSTEM INITIALIZATION -----|\n";
    std::cout << "1. Standard Account | 2. Savings Account: ";
    std::cin >> accountType;

    std::cout << "Enter Full Name: ";
    std::getline(std::cin >> std::ws, temporalName);

    std::cout << "Initial Deposit: ";
    std::cin >> temporalAmount;

    std::cout << "Set 4-digit PIN: ";
    std::cin >> temporalPin;

    // OBJECT INSTANTIATION
    if (accountType == 2)
    {
        savingAccounts.push_back(SavingAccount(temporalName, temporalAmount, temporalPin, 2.5));
        isSavingMode = true;
    }
    else
    {
        accounts.push_back(BankAccount(temporalName, temporalAmount, temporalPin));
        isSavingMode = false;
    }

    // INTERACTION LOOP
    while (keepRunning)
    {
        int choice{};
        std::cout << "\n--- Current Status ---\n";
        if (isSavingMode)
            savingAccounts[0].showInfo();
        else
            accounts[0].showInfo();

        std::cout << "\nOptions: 1.Deposit | 2.Withdraw | 3.Exit";
        if (isSavingMode)
            std::cout << " | 4.Apply Interest";
        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Amount: ";
            std::cin >> temporalAmount;
            if (isSavingMode)
                savingAccounts[0].depositAmount(temporalAmount);
            else
                accounts[0].depositAmount(temporalAmount);
            break;
        case 2:
            std::cout << "Amount: ";
            std::cin >> temporalAmount;
            std::cout << "PIN: ";
            std::cin >> confirmPin;
            if (isSavingMode)
                savingAccounts[0].withrawMoney(temporalAmount, confirmPin);
            else
                accounts[0].withrawMoney(temporalAmount, confirmPin);
            break;
        case 3:
            keepRunning = false;
            break;
        case 4:
            if (isSavingMode)
                savingAccounts[0].applyInterest();
            else
                std::cout << "Not a Savings Account.\n";
            break;
        default:
            std::cout << "Invalid Option.\n";
        }
    }
    return 0;
}