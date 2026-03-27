#include <stdio.h>
#include <stdbool.h>
#include <limits.h>  // Added for INT_MAX, INT_MIN

#define MAX_ARRAY_SIZE 1000
#define ARRAY_SIZE 5

// Validate array parameters
bool validateArrayParams(int *arr, int size) {
    // Check for NULL pointer
    if (arr == NULL) {
        printf("Error: Array pointer is NULL\n");
        return false;
    }
    // Check for valid size
    if (size <= 0) {
        printf("Error: Invalid array size (%d)\n", size);
        return false;
    }
    // Check for reasonable size
    if (size > MAX_ARRAY_SIZE) {
        printf("Error: Array size too large (%d > %d)\n",
               size, MAX_ARRAY_SIZE);
        return false;
    }
    return true;
}

// Secure sum calculation with overflow protection
bool secureCalculateSum(int *arr, int size, int *result) {
    // Validate result pointer
    if (result == NULL) {
        printf("Error: Result pointer is NULL\n");
        return false;
    }
    // Validate array parameters
    if (!validateArrayParams(arr, size)) {
        return false;
    }
    
    // Safe to process with overflow checking
    long long sum = 0;  // Use long long to detect overflow
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);  // Pointer arithmetic
        
        // Check for integer overflow
        if (sum > INT_MAX || sum < INT_MIN) {
            printf("Error: Integer overflow detected in sum calculation\n");
            return false;
        }
    }
    *result = (int)sum;
    return true;
}

// Secure maximum finder with empty array check
bool secureFindMax(int *arr, int size, int *maxValue) {
    // Validate result pointer
    if (maxValue == NULL) {
        printf("Error: Max value pointer is NULL\n");
        return false;
    }
    // Validate array parameters
    if (!validateArrayParams(arr, size)) {
        return false;
    }
    
    // CRITICAL: Check if array has at least one element
    // The original code would crash if size was 1 or more, 
    // but we need to ensure size >= 1
    if (size < 1) {
        printf("Error: Cannot find maximum of empty array\n");
        return false;
    }
    
    // Safe to process
    int max = *arr;  // Initialize with first element
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    *maxValue = max;
    return true;
}

// Secure element access with bounds checking
bool secureAccessElement(int *arr, int size, int index,
                         int *value) {
    // Validate array and result pointer
    if (value == NULL) {
        printf("Error: Value pointer is NULL\n");
        return false;
    }
    
    if (!validateArrayParams(arr, size)) {
        return false;
    }
    
    // CRITICAL: Bounds checking
    if (index < 0 || index >= size) {
        printf("Error: Index %d out of bounds [0, %d)\n",
               index, size);
        return false;
    }
    
    // Safe to access
    *value = *(arr + index);
    return true;
}

int main() {
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    int sum, max, value;
    
    // Test 1: Valid array operations
    printf("=== Test 1: Valid Operations ===\n");
    if (secureCalculateSum(numbers, ARRAY_SIZE, &sum)) {
        printf("Sum: %d\n", sum);
    }
    if (secureFindMax(numbers, ARRAY_SIZE, &max)) {
        printf("Maximum: %d\n", max);
    }
    
    // Test 2: NULL pointer
    printf("\n=== Test 2: NULL Pointer ===\n");
    if (!secureCalculateSum(NULL, ARRAY_SIZE, &sum)) {
        printf("Handled NULL pointer safely\n");
    }
    
    // Test 3: Invalid size
    printf("\n=== Test 3: Invalid Size ===\n");
    if (!secureCalculateSum(numbers, -5, &sum)) {
        printf("Rejected negative size\n");
    }
    
    // Test 4: Bounds checking
    printf("\n=== Test 4: Bounds Checking ===\n");
    // Valid index
    if (secureAccessElement(numbers, ARRAY_SIZE, 2, &value)) {
        printf("Element at index 2: %d\n", value);
    }
    // Out of bounds - too large
    if (!secureAccessElement(numbers, ARRAY_SIZE, 10, &value)) {
        printf("Prevented buffer overflow\n");
    }
    // Out of bounds - negative
    if (!secureAccessElement(numbers, ARRAY_SIZE, -1, &value)) {
        printf("Prevented negative index access\n");
    }
    
    // Test 5: Null result pointer (new test)
    printf("\n=== Test 5: Null Result Pointer ===\n");
    if (!secureCalculateSum(numbers, ARRAY_SIZE, NULL)) {
        printf("Handled NULL result pointer safely\n");
    }
    
    // Test 6: Overflow test (if numbers were large)
    printf("\n=== Test 6: Edge Cases ===\n");
    int largeArray[3] = {INT_MAX, 1, 2};
    if (!secureCalculateSum(largeArray, 3, &sum)) {
        printf("Overflow detected correctly\n");
    }
    
    // Test 7: Empty array check (size = 0)
    printf("\n=== Test 7: Empty Array ===\n");
    int emptyArray[1];  // Declare array but size parameter will be 0
    if (!secureFindMax(emptyArray, 0, &max)) {
        printf("Handled empty array correctly\n");
    }
    
    printf("\nAll tests completed successfully!\n");
    return 0;
}