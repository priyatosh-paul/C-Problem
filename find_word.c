#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "Find a word from this sentence using strtok";
    char delimiters[] = " ";
    char *token;
    char *desired_word = "word"; // The word you want to find

    // Get the first token
    token = strtok(sentence, delimiters);

    // Iterate through all the tokens
    while (token != NULL) {
        // Check if the current token matches the desired word
        if (strcmp(token, desired_word) == 0) {
            printf("Found the word: %s\n", token);
            return 0; // Exit the program as we found the word
        }
        // Get the next token
        token = strtok(NULL, delimiters);
    }

    printf("Word not found.\n");
    return 0;
}
