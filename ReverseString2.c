#include <stdio.h>
#include <string.h>

void reverseString(char* str) {

    // Temp array assuming the max size of the original
    // string 100
    char temp[100];

    // Size pointer of the temp array
    int t_size = -1;
    int len =0;
    while(str[len] != '\0')
    {
        len++;
    }

    // Push all characters of the string onto the temp
    for (int i = 0; i < len; i++) {
        temp[++t_size] = str[i];
    }

    // Copying all characters from the temp array and
    // replace in the original string
    for (int i = 0; i < len; i++) {
        str[i] = temp[t_size--];
    }
}

int main() {
    char str[100] = "Hello World";
    printf("Original String: %s\n", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
