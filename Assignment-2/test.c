#include <stdio.h>

int main() {
    float price, priceVat, discount, finalPrice;

    printf("Enter the price: ");
    scanf("%f", &price);

    priceVat = price + price * 0.07;

    if (priceVat <= 10000) {
        discount = priceVat * 0.05;
    } else {
        discount = priceVat * 0.1;
    }

    finalPrice = priceVat - discount;

    printf("Price with VAT: %.2f\n", priceVat);
    printf("Discount: %.2f\n", discount);
    printf("Final Price: %.2f\n", finalPrice);

    return 0;
}
