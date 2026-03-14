#include <stdio.h>
#include <limits.h>

long long calculateMortgage(long long salary1, long long salary2){
    long long larger, smaller, mortgage;

    if(salary1 > salary2){
        larger = salary1;
        smaller = salary2;
    }else{
        larger = salary2;
        smaller = salary1;
    }

    if(larger > (LLONG_MAX / 3))
        return -1;

    mortgage = larger * 3;

    if(mortgage > (LLONG_MAX - smaller))
        return -1;

    mortgage = mortgage + smaller;

    return mortgage;
}

int main(){
    long long s1, s2, result;

    printf("Enter two salaries: ");
    scanf("%lld %lld", &s1, &s2);

    result = calculateMortgage(s1, s2);

    if(result == -1)
        printf("Overflow error\n");
    else
        printf("Mortgage amount: %lld\n", result);

    return 0;
}