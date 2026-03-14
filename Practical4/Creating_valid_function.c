#include <stdio.h>
#include <stdbool.h>

bool readSalaries(double *salary1, double *salary2) {
    int c;

    if (salary1 == NULL || salary2 == NULL)
        return false;

    if (scanf("%lf %lf", salary1, salary2) != 2) {
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }

    return true;
}

int main() {
    double s1, s2;

    if (readSalaries(&s1, &s2))
        printf("Salaries: %.2lf %.2lf\n", s1, s2);
    else
        printf("Invalid input\n");

    return 0;
}