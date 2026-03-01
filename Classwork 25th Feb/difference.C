#include <stdio.h>
#include <string.h>

int main() {
    char x[10] = "PrinceBar";           
    int y[10] = {1,2,3,4,5,6,7,8,9,10}; 

    printf("The name is %s\n", x);      
    printf("The numbers are: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", y[i]);           
    }

    printf("\n");
    return 0;
}