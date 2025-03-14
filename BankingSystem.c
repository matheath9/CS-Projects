#include <stdio.h>

void initializeAccounts(float bankOfMatan[][3]) {
    for (int i = 0; i < 50; i++) {
        bankOfMatan[i][0] = i + 1;    // Account numbers 1 to 50
        bankOfMatan[i][1] = -1;       // Initialize account as closed
        bankOfMatan[i][2] = 0;        // Initialize balance as 0
    }
}

void openAccount(float bankOfMatan[][3]) {
    int accountNumber;
    float initialDeposit;
    
    printf("Enter the account number (1-50) for opening an account: \n");
    scanf("%d", &accountNumber);

    // Adjust to 0-based indexing
    accountNumber--;

    // Validate the account number
    if (accountNumber < 0 || accountNumber >= 50) {
        printf("Invalid account number. Please choose between 1 and 50.\n");
        return;
    }

    // Check if the account is already open
    if (bankOfMatan[accountNumber][1] != -1) {
        printf("Account %d is already open.\n", accountNumber + 1);
    } else {
        // Prompt for initial deposit
        printf("Enter initial deposit amount (minimum $100): \n");
        scanf("%f", &initialDeposit);

        // Validate initial deposit
        if (initialDeposit < 100) {
            printf("Initial deposit must be at least $100.\n");
            return;
        }

        // Open the account and set the initial balance
        bankOfMatan[accountNumber][2] = initialDeposit;
        bankOfMatan[accountNumber][1] = 1;  // Mark account as open

        printf("Account %d opened with an initial deposit of $%.2f\n", accountNumber + 1, initialDeposit);
    }
}

void checkBalance(float bankOfMatan[][3]) {
    int accountNumber;

    printf("Enter account number to check balance (1-50): \n");
    scanf("%d", &accountNumber);

    accountNumber--;

    if (accountNumber < 0 || accountNumber >= 50) {
        printf("Invalid account number. Please choose between 1 and 50.\n");
        return;
    }

    if (bankOfMatan[accountNumber][1] == -1) {
        printf("Account %d is closed.\n", accountNumber + 1);
    } else {
        printf("Balance of account %d is $%.2f\n", accountNumber + 1, bankOfMatan[accountNumber][2]);
    }
}

void deposit(float bankOfMatan[][3]) {
    int accountNumber;
    float depositAmount;

    printf("Enter account number to deposit into (1-50): \n");
    scanf("%d", &accountNumber);

    accountNumber--;

    if (accountNumber < 0 || accountNumber >= 50) {
        printf("Invalid account number. Please choose between 1 and 50.\n");
        return;
    }

    if (bankOfMatan[accountNumber][1] == -1) {
        printf("Account %d is closed.\n", accountNumber + 1);
    } else {
        printf("Enter amount to deposit into account %d: \n", accountNumber + 1);
        scanf("%f", &depositAmount);
        
        bankOfMatan[accountNumber][2] += depositAmount;
        printf("Deposit of $%.2f successful. New balance: $%.2f\n", depositAmount, bankOfMatan[accountNumber][2]);
    }
}

void withdraw(float bankOfMatan[][3]) {
    int accountNumber;
    float withdrawAmount;

    printf("Enter account number to withdraw from (1-50): \n");
    scanf("%d", &accountNumber);

    accountNumber--;

    if (accountNumber < 0 || accountNumber >= 50) {
        printf("Invalid account number. Please choose between 1 and 50.\n");
        return;
    }

    if (bankOfMatan[accountNumber][1] == -1) {
        printf("Account %d is closed.\n", accountNumber + 1);
    } else {
        printf("Enter amount to withdraw from account %d: \n", accountNumber + 1);
        scanf("%f", &withdrawAmount);

        if (withdrawAmount > bankOfMatan[accountNumber][2]) {
            printf("Insufficient funds in account %d\n", accountNumber + 1);
        } else {
            bankOfMatan[accountNumber][2] -= withdrawAmount;
            printf("Withdrawal of $%.2f successful. New balance: $%.2f\n", withdrawAmount, bankOfMatan[accountNumber][2]);
        }
    }
}

void closeAccount(float bankOfMatan[][3]) {
    int accountNumber;

    printf("Enter account number to close (1-50): \n");
    scanf("%d", &accountNumber);

    accountNumber--;

    if (accountNumber < 0 || accountNumber >= 50) {
        printf("Invalid account number. Please choose between 1 and 50.\n");
        return;
    }

    if (bankOfMatan[accountNumber][1] == -1) {
        printf("Account %d is already closed.\n", accountNumber + 1);
    } else {
        bankOfMatan[accountNumber][1] = -1;
        printf("Account %d closed. Final balance: $%.2f\n", accountNumber + 1, bankOfMatan[accountNumber][2]);
    }
}

void printAccounts(float bankOfMatan[][3]) {
    printf("Account Status:\n");
    printf("Account Number | Status | Balance\n");
    for (int i = 0; i < 50; i++) {
        printf("%d | %c | $%.2f\n", i + 1, (bankOfMatan[i][1] == -1 ? 'X' : 'O'), bankOfMatan[i][2]);
    }
}

int main() {
    float bankOfMatan[50][3];  // Array to store account data
    char option;

    initializeAccounts(bankOfMatan);

    do {
        printf("\nMenu:\n");
        printf("O/o - Open Account\n");
        printf("B/b - Balance Inquiry\n");
        printf("D/d - Deposit Funds\n");
        printf("W/w - Withdraw Funds\n");
        printf("C/c - Close Account\n");
        printf("P/p - Print Accounts\n");
        printf("E/e - Exit Program\n");

        printf("Select an option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'O':
            case 'o':
                openAccount(bankOfMatan);
                break;
            case 'B':
            case 'b':
                checkBalance(bankOfMatan);
                break;
            case 'D':
            case 'd':
                deposit(bankOfMatan);
                break;
            case 'W':
            case 'w':
                withdraw(bankOfMatan);
                break;
            case 'C':
            case 'c':
                closeAccount(bankOfMatan);
                break;
            case 'P':
            case 'p':
                printAccounts(bankOfMatan);
                break;
            case 'E':
            case 'e':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
    } while (option != 'E' && option != 'e');

    return 0;
}
