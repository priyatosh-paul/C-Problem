#include <stdio.h>

int main() {
    int a, b, n = 0, r = 0, c, d;
    printf("Please enter the input values: ");
    scanf("%d %d", &a, &b);  // Use a single scanf to take both inputs at once

    c = a * b;  // Multiply a and b
    d = c;      // Set d equal to the product (c)

    // Reverse the digits of d
    while (d != 0) {
        r = r * 10 + d % 10;  // Add the last digit of d to r
        d = d / 10;            // Remove the last digit from d
    }

    printf("Reversed number is %02d\n", r);  // Print the reversed number
    return 0;
}