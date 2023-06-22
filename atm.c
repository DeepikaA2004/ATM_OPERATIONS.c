#include <stdio.h>
#include <stdlib.h>

void balance_f();
void withdraw();
void deposit();
void pin_f();

int pin = 1234, pinuser, withdraw_Amount, deposit_Amount;
char ch;
float balance = 0;

int main() {
    int n;
    do {
        printf("WELCOME TO SBI\n-----------------------------\n1. CHECK BALANCE\n2. DEPOSIT MONEY\n3. WITHDRAW MONEY\n4. PIN CHANGE\n5. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                printf("CHECKING BALANCE ...\n");
                balance_f();
                break;
            case 2:
                printf("DEPOSITING YOUR MONEY ...\n");
                deposit();
                break;
            case 3:
                printf("WITHDRAWING YOUR MONEY ...\n");
                withdraw();
                break;
            case 4:
                printf("PIN CHANGE REQUEST IS IN PROCESS ...\n");
                pin_f();
                break;
            case 5:
                printf("Thank you ...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');

    return 0;
}

void balance_f() {
    printf("\nENTER YOUR PIN: ");
    scanf("%d", &pinuser);

    if (pin == pinuser) {
        printf("Your balance is Rs. %.2f\n", balance);
    } else {
        printf("Invalid pin\n");
        exit(1);
    }
}

void withdraw() {
    printf("\nENTER YOUR PIN: ");
    scanf("%d", &pinuser);

    if (pin == pinuser) {
        printf("Enter the amount to be withdrawn: ");
        scanf("%d", &withdraw_Amount);

        if (balance < withdraw_Amount) {
            printf("Insufficient Balance\n");
        } else {
            printf("Success! Please collect Rs. %d\n", withdraw_Amount);
            balance -= withdraw_Amount;
        }
    } else {
        printf("Invalid pin\n");
        exit(1);
    }
}

void deposit() {
    printf("\nENTER YOUR PIN: ");
    scanf("%d", &pinuser);

    if (pin == pinuser) {
        printf("Enter the amount to be deposited: ");
        scanf("%d", &deposit_Amount);

        printf("Success! Rs. %d credited to your account.\n", deposit_Amount);
        balance += deposit_Amount;
    } else {
        printf("Invalid pin\n");
        exit(1);
    }
}

void pin_f() {
    int pinuser1, pinuser2;
pinn:
    printf("\nEnter old PIN: ");
    scanf("%d", &pinuser);

    if (pin == pinuser) {
        printf("\nEnter new PIN: ");
        scanf("%d", &pinuser1);
        printf("\nConfirm new PIN: ");
        scanf("%d", &pinuser2);

        if (pinuser1 == pinuser2) {
            printf("Success! Your PIN has been changed.\n");
            pin = pinuser1;
        } else {
            printf("PINs do not match. Please try again.\n");
            goto pinn;
        }
    } else {
        printf("Incorrect pin. Please try again.\n");
        goto pinn;
    }
}
