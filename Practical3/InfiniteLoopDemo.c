#include <stdio.h>
int main() {
    //  DANGEROUS: Infinite loop with unsigned integers
    unsigned int i = 10;
    
    printf("This loop will never end!\n");
    // DON'T RUN THIS! Just analyse it
    /*
    while (i >= 0) {  // Always true for unsigned!
        printf("%u ", i);
        i--;
    }
    */
    
    return 0;
}
