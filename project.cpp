#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Expense {
    double amount;
    string description;
};

class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    void addExpense(double amount, const string &description) {
        Expense newExpense = {amount, description};
        expenses.push_back(newExpense);
        cout << "Expense added successfully!\n";
    }

    double getTotalExpenses() {
        double total = 0.0;
        for (const auto &expense : expenses) {
            total += expense.amount;
        }
        return total;
    }

    void displayExpenses() {
        if (expenses.empty()) {
            cout << "No expenses logged.\n";
            return;
        }

        cout << "\n--- List of Expenses ---\n";
        cout << setw(20) << "Description" << setw(10) << "Amount" << endl;
        cout << string(30, '-') << endl;

        for (const auto &expense : expenses) {
            cout << setw(20) << expense.description << setw(10) << fixed << setprecision(2) << expense.amount << endl;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    bool loop = true;

    while (loop) {
        int choice;
        double amount;
        string description;

        cout << "\n--- Expense Tracker ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Total Expenses\n";
        cout << "3. Display All Expenses\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Expense Amount: ";
                cin >> amount;
                cin.ignore();
                cout << "Enter Expense Description: ";
                getline(cin, description);
                tracker.addExpense(amount, description);
                break;
            case 2:
                cout << "Total Expenses: $" << fixed << setprecision(2) << tracker.getTotalExpenses() << endl;
                break;
            case 3:
                tracker.displayExpenses();
                break;
            case 0:
                loop = false;
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
