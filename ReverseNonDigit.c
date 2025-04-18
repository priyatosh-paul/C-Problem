#include <stdio.h>
#include <ctype.h>  // for isdigit()

void reverse_non_digits(const char str[], int size, char result[]) {
    int j = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (!isdigit((unsigned char)str[i])) {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';  // Null-terminate the result string
}

int main() {
    char str[] = "a1b2c3d4e5";
    int size = sizeof(str) - 1;  // exclude null terminator

    char reversed[100];  // make sure this is large enough

    reverse_non_digits(str, size, reversed);

    printf("Reversed without digits: %s\n", reversed);

    return 0;
}
