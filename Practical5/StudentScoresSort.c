#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_STUDENTS 5
#define MAX_STUDENTS 100
#define MIN_SCORE 0
#define MAX_SCORE 100
#define MAX_ATTEMPTS 3

// Function declarations
bool validateArrayParams(int scores[], int size);
bool readScores(int scores[], int size);
void displayScores(int scores[], int size);

// New sorting functions
bool swapElements(int scores[], int size, int index1, int index2);
bool sortScoresAscending(int scores[], int size);

int main() {
    int scores[NUM_STUDENTS];

    if (!readScores(scores, NUM_STUDENTS)) {
        printf("Error reading scores\n");
        return 1;
    }

    displayScores(scores, NUM_STUDENTS);

    // Sorting
    printf("\nSorting scores...\n");
    if (sortScoresAscending(scores, NUM_STUDENTS)) {
        printf("Scores sorted successfully.\n");
        displayScores(scores, NUM_STUDENTS);
    } else {
        printf("Error: Failed to sort scores.\n");
        return 1;
    }

    return 0;
}

// Validate array
bool validateArrayParams(int scores[], int size) {
    if (scores == NULL) return false;
    if (size <= 0 || size > MAX_STUDENTS) return false;
    return true;
}

// Simple input (reuse your secure version if needed)
bool readScores(int scores[], int size) {
    if (!validateArrayParams(scores, size)) return false;

    for (int i = 0; i < size; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }
    return true;
}

// Display scores
void displayScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d: %d\n", i + 1, scores[i]);
    }
}

// 🔐 Secure swap
bool swapElements(int scores[], int size, int index1, int index2) {
    if (!validateArrayParams(scores, size)) return false;

    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
        printf("Error: Swap indices out of bounds.\n");
        return false;
    }

    int temp = scores[index1];
    scores[index1] = scores[index2];
    scores[index2] = temp;

    return true;
}

// 🔐 Secure bubble sort
bool sortScoresAscending(int scores[], int size) {
    if (!validateArrayParams(scores, size)) return false;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            // Ensure j and j+1 are valid
            if (j < 0 || j + 1 >= size) {
                printf("Error: Index out of bounds.\n");
                return false;
            }

            if (scores[j] > scores[j + 1]) {
                if (!swapElements(scores, size, j, j + 1)) {
                    return false;
                }
            }
        }
    }

    return true;
}