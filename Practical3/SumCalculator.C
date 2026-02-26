#include <stdio.h>

int main()
{
    int number;
    int sum = 0;

    printf("Enter positive numbers (enter a negative number to stop):\n");

    while (1)   // infinite loop
    {
        if(scanf("%d", &number)!=1){
            printf("Invalid input!!");
            while (getchar() != '\n');
                continue;
        }

        if (number < 0)   // stop condition
        {
            break;
        }

        sum = sum + number;    // add to sum
    }

    printf("Sum of positive numbers: %d\n", sum);

    return 0;
}