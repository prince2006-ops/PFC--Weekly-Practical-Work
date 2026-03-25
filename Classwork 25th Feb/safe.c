#include<stdio.h>

int *getSafePointer(){
    static int x = 42;
    return &x;
}

void setValue(int *ptr){
    *ptr = 100;
}

int main(){
    int *p;

    p = getSafePointer();

    printf("Initial value: %d\n", *p);

    setValue(p);

    printf("After modification: %d\n", *p);

    return 0;
}