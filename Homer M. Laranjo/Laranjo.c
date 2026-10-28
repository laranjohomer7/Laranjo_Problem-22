#include <stdio.h>

int main()
{
    double loanAmount = 20000.00;
    double remainingBalance = loanAmount;
    double totalPayments = 0.00;
    double payment;
    int plannedPayments;
    int paymentNumber;

    printf("Enter the number of planned payments: ");
    if (scanf("%d", &plannedPayments) != 1) {
        printf("Invalid number of payments.\n");
        return 1;
    }

    if (plannedPayments <= 0) {
        printf("The number of planned payments must be greater than zero.\n");
        return 1;
    }

    paymentNumber = 1;

    while (paymentNumber <= plannedPayments && remainingBalance > 0.00) {
        printf("Enter payment %d amount: ", paymentNumber);

        if (scanf("%lf", &payment) != 1) {
            printf("Invalid payment amount.\n");
            return 1;
        }

        if (payment <= 0.00) {
            printf("Payment rejected: the amount must be greater than zero.\n");
        } else if (payment > remainingBalance) {
            printf("Payment rejected: it exceeds the remaining balance of %.2f pesos.\n",
                   remainingBalance);
        } else {
            totalPayments = totalPayments + payment;
            remainingBalance = remainingBalance - payment;

            printf("Remaining balance: %.2f pesos\n", remainingBalance);
        }

        paymentNumber = paymentNumber + 1;
    }

    printf("\nTotal payments received: %.2f pesos\n", totalPayments);
    printf("Remaining balance: %.2f pesos\n", remainingBalance);

    if (remainingBalance == 0.00) {
        printf("The loan has been fully paid.\n");
    } else {
        printf("The loan has not been fully paid.\n");
    }

    return 0;
}
