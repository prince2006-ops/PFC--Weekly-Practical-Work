#include<stdio.h>
int *getDanglingPointer(){
    int x=42;
    return &x;
}
 int main(){
    int *ptr=getDanglingPointer();
    printf("%d",*ptr);
    return 0;
 }