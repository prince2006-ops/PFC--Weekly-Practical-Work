#include <stdio.h>
#include <stdbool.h>

#define MIN_SALARY 0.0
#define MAX_SALARY 1000000.0

bool validateSalary(double salary){
    if(salary >= MIN_SALARY && salary <= MAX_SALARY)
        return true;
    else
        return false;
}

int main(){
    double salary;

    printf("Enter salary: ");
    scanf("%lf",&salary);

    if(validateSalary(salary))
        printf("Valid salary\n");
    else
        printf("Invalid salary\n");

    return 0;
}