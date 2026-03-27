#include <stdio.h>
int main(){
    int num=42;
    int *ptr;
    ptr=&num;
    printf("Value of num:%d\n",num);
    printf("Address of num:%d\n",(void*)&num);
    printf("Value of ptr:%d\n",ptr);
    printf("Value pointed to by ptr: %d", *ptr);
    return 0;
}