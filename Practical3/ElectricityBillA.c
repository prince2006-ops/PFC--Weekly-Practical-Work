/* Electricity bill
   Practical 3, Part 2
   Programming for Cyber Security UFCFGL-30-1
   @author Prince Bartaula
*/

#include <stdio.h>

int main()
{
    // Define variables
    int previousMetre, currentMetre, day, month;
    int unitsUsed;

    // Prompt user
    printf("Enter previous meter reading, current meter reading, day and month:\n");

    // Defensive programming: check if scanf reads all 4 integers
    if (scanf("%d %d %d %d", &previousMetre, &currentMetre, &day, &month) != 4) {
        printf("Error: Invalid input format\n");
        return 1;
    }

   
    // Validation

    // (i) Current meter reading within range 0-9999
    if (currentMetre < 0 || currentMetre > 9999)
        printf("Error: current meter reading out of range\n");

    // (i) Previous meter reading within range 0-9999
    if (previousMetre < 0 || previousMetre > 9999)
        printf("Error: previous meter reading out of range\n");

    // (ii) Previous not greater than present
    if (previousMetre > currentMetre)
        printf("Error: previous reading is more than present reading\n");

    // (iii) Electricity used not more than 1000
    unitsUsed = currentMetre - previousMetre;
    if (unitsUsed > 1000)
        printf("Error: electricity usage exceeds 1000 units\n");

    // (iv) Month in range 1-12
    if (month < 1 || month > 12)
        printf("Error: month out of range\n");

    // (iv) Day validation based on month
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        if (day < 1 || day > 31)
            printf("Error: invalid day for this month\n");
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30)
            printf("Error: invalid day for this month\n");
    }
    else if (month == 2) {  // February (assuming 29 days max)
        if (day < 1 || day > 29)
            printf("Error: invalid day for February\n");
    }
     // Display input values
    printf("%d %d %d %d\n", previousMetre, currentMetre, day, month);

    return 0;
}