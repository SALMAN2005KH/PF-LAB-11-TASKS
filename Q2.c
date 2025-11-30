#include <stdio.h>
#include <string.h>

struct Transaction {
    char transactionDate[20];
    char transactionType[20];
    float transactionAmount;
};

struct BankAccount {
    char accountHolderName[50];
    int accountNumber;
    char accountType[20];
    float accountBalance;
    char accountCreationDate[20];
    char lastTransactionDate[20];
    struct Transaction transactionList[100];
    int totalTransactions;
};

float getMinimumBalance(char type[]) {
    if (strcmp(type, "Savings") == 0) return 1000;
    if (strcmp(type, "Current") == 0) return 5000;
    return 10000;
}

float getInterestRate(char type[]) {
    if (strcmp(type, "Savings") == 0) return 0.04;
    if (strcmp(type, "Fixed") == 0) return 0.07;
    return 0.0;
}

void depositAmount(struct BankAccount *account) {
    float amount;
    char date[20];

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", date);

    account->accountBalance += amount;

    strcpy(account->lastTransactionDate, date);

    struct Transaction t;
    strcpy(t.transactionDate, date);
    strcpy(t.transactionType, "Deposit");
    t.transactionAmount = amount;

    account->transactionList[account->totalTransactions++] = t;

    printf("Deposit successful. New balance: %.2f\n", account->accountBalance);
}

void withdrawAmount(struct BankAccount *account) {
    float amount;
    char date[20];

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    float minimumBalance = getMinimumBalance(account->accountType);

    if (account->accountBalance - amount < minimumBalance) {
        printf("Insufficient balance. Minimum balance required: %.2f\n", minimumBalance);
        return;
    }

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", date);

    account->accountBalance -= amount;

    strcpy(account->lastTransactionDate, date);

    struct Transaction t;
    strcpy(t.transactionDate, date);
    strcpy(t.transactionType, "Withdrawal");
    t.transactionAmount = amount;

    account->transactionList[account->totalTransactions++] = t;

    printf("Withdrawal successful. New balance: %.2f\n", account->accountBalance);
}

void displayAccount(struct BankAccount account) {
    printf("\nAccount Holder: %s\n", account.accountHolderName);
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Type: %s\n", account.accountType);
    printf("Account Balance: %.2f\n", account.accountBalance);
    printf("Account Created On: %s\n", account.accountCreationDate);
    printf("Last Transaction: %s\n", account.lastTransactionDate);

    printf("\nTransaction History:\n");
    for (int i = 0; i < account.totalTransactions; i++)
        printf("%s  %s  %.2f\n",
               account.transactionList[i].transactionDate,
               account.transactionList[i].transactionType,
               account.transactionList[i].transactionAmount);
}

int main() {
    struct BankAccount bankAccount;
    int userChoice;

    printf("Enter account holder name: ");
    scanf("%s", bankAccount.accountHolderName);

    printf("Enter account number: ");
    scanf("%d", &bankAccount.accountNumber);

    printf("Enter account type (Savings/Current/Fixed): ");
    scanf("%s", bankAccount.accountType);

    printf("Enter account creation date (DD-MM-YYYY): ");
    scanf("%s", bankAccount.accountCreationDate);

    bankAccount.accountBalance = 0;
    bankAccount.totalTransactions = 0;
    strcpy(bankAccount.lastTransactionDate, bankAccount.accountCreationDate);

    while (1) {
        printf("\n1. Deposit Amount\n2. Withdraw Amount\n3. Display Account Details\n4. Apply Interest\n5. Exit\nEnter choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 1)
            depositAmount(&bankAccount);

        else if (userChoice == 2)
            withdrawAmount(&bankAccount);

        else if (userChoice == 3)
            displayAccount(bankAccount);

        else if (userChoice == 4) {
            float rate = getInterestRate(bankAccount.accountType);
            float interest = bankAccount.accountBalance * rate;
            bankAccount.accountBalance += interest;
            printf("Interest added: %.2f\nNew balance: %.2f\n", interest, bankAccount.accountBalance);
        }

        else if (userChoice == 5)
            break;
    }

    return 0;
}
