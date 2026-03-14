#include <stdio.h>
#include <stdbool.h>

// Function declaration
bool readSalaries(double *salary1, double *salary2);

int main() {
    double salary1, salary2;
    
    printf("Enter two salaries: ");
    
    if (readSalaries(&salary1, &salary2)) {
        printf("Success! You entered: %.2f and %.2f\n", salary1, salary2);
        printf("Average: %.2f\n", (salary1 + salary2) / 2);
    } else {
        printf("Error: Invalid input. Please enter two numbers.\n");
        return 1;
    }
    
    return 0;
}

// Function definition
bool readSalaries(double *salary1, double *salary2) {
    // Check if pointers are NULL
    if (salary1 == NULL || salary2 == NULL) {
        return false;
    }
    
    // Use scanf to read two salaries
    int result = scanf("%lf %lf", salary1, salary2);
    
    // Check scanf return value (should equal 2)
    if (result != 2) {
        // Clear input buffer on error
        while (getchar() != '\n');
        return false;
    }
    
    // Returns true on success
    return true;
}