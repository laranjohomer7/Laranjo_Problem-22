#include <stdio.h>

int main() {
    int loan = 20000;
    int balance = loan;
    int total = 0;
    int payments, payment;

    printf("Enter number of payments: ");
    scanf("%d", &payments);

    if (payments <= 0) {
        printf("Invalid number of payments.\n");
        return 0;
    }

    for (int i = 1; i <= payments && balance > 0; i++) {
        printf("Enter payment %d: ", i);
        scanf("%d", &payment);

        if (payment <= 0) {
            printf("Invalid payment amount.\n");
        } else if (payment > balance) {
            printf("Payment exceeds remaining balance.\n");
        } else {
            total = total + payment;
            balance = balance - payment;

            printf("Remaining balance: %d pesos\n", balance);
        }
    }

    printf("\nTotal payments: %d pesos\n", total);
    printf("Remaining balance: %d pesos\n", balance);

    if (balance == 0) {
        printf("Loan fully paid.\n");
    } else {
        printf("Loan not fully paid.\n");
    }

    return 0;
}
