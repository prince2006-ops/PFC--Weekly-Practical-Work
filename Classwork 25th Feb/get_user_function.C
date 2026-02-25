#include<stdio.h>
#include<limits.h>  // For INT_MAX

// Function prototype
int get_user_input();

int main(){
    int user_value = get_user_input();
    
    // Check for negative or values that would cause overflow
    if(user_value < 0 || user_value > INT_MAX/1000) {
        printf("Invalid input. Value would cause overflow.\n");
        return 1;
    }
    
    // Calculate safely - check for overflow during multiplication
    long long total_iterations = (long long)user_value * 1000;
    
    printf("Loop will run %lld times\n", total_iterations);
    
    for (int i = 0; i < total_iterations; i++) {
        // Do something useful here
        // Even empty loops waste CPU time!
    }
    
    return 0;
}

int get_user_input() {
    int value;
    printf("Enter a positive integer: ");
    
    // Check if scanf succeeded
    if(scanf("%d", &value) != 1) {
        return -1;  // Return error indicator
    }
    
    return value;
}