#include <stdio.h>

int main() {

    // Declare variables
    char firstWord[20];   // Buffer size is 20 (19 chars + '\0')
    char secondWord[20];  // Buffer size is 20 (19 chars + '\0')
    int num;

    // Prompt user
    printf("Enter two words and an integer from keyboard:\n");

    // Read input (limit strings to 19 characters to prevent overflow)
    scanf("%19s %19s %d", firstWord, secondWord, &num);

    // Display output
    printf("\nYou entered:\n");
    printf("%s %s\n%d\n", firstWord, secondWord, num);

    return 0;
}