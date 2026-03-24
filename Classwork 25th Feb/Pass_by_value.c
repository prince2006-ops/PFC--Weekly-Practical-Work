#include<stdio.h>
void modify(int x){
    printf("Inside modify-before: x=%d\n",x);
    x=100l;
    printf("Inside modify - after: x=%d\n",x);
}
int main(){
    int num=5;
    printf("Before calling modify num = %d\n ",num);
    modify(num);
    printf("After calling modify num =%d\n",num);
    return 0;
}