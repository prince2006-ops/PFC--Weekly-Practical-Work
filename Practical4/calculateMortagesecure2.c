#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MIN_SALARY 0.0
#define MAX_SALARY 1000000.0
#define MAX_ATTEMPTS 3

bool readSalaries(double *salary1, double *salary2){
    int c;

    if(salary1==NULL || salary2==NULL)
        return false;

    if(scanf("%lf %lf",salary1,salary2)!=2){
        while((c=getchar())!='\n' && c!=EOF);
        return false;
    }

    return true;
}

bool validateSalary(double salary){
    return (salary>=MIN_SALARY && salary<=MAX_SALARY);
}

double calculateMortgage(double salary1,double salary2){
    double larger,smaller;

    if(salary1>salary2){
        larger=salary1;
        smaller=salary2;
    }else{
        larger=salary2;
        smaller=salary1;
    }

    if(larger > (LLONG_MAX/3))
        return -1;

    double mortgage = larger*3;

    if(mortgage > (LLONG_MAX-smaller))
        return -1;

    return mortgage + smaller;
}

int main(){
    double salary1,salary2,mortgage;
    int attempts=0;
    bool inputValid=false;

    while(attempts<MAX_ATTEMPTS && !inputValid){

        printf("Enter two salaries separated by space: ");

        if(!readSalaries(&salary1,&salary2)){
            attempts++;
            printf("Error: Invalid input format\n");
            printf("Attempts remaining: %d\n",MAX_ATTEMPTS-attempts);
            continue;
        }

        if(!validateSalary(salary1) || !validateSalary(salary2)){
            attempts++;
            printf("Error: Salaries must be between £0 and £1,000,000\n");
            printf("Attempts remaining: %d\n",MAX_ATTEMPTS-attempts);
            continue;
        }

        inputValid=true;
    }

    if(!inputValid){
        printf("Maximum attempts exceeded. Program terminated.\n");
        return 1;
    }

    mortgage = calculateMortgage(salary1,salary2);

    if(mortgage < 0){
        printf("Error: Calculation failed due to overflow\n");
        return 1;
    }

    printf("Maximum mortgage: £%.2lf\n",mortgage);

    return 0;
}