#include <stdio.h>
void modify(int *ptr){
    printf("Inside modify- before *ptr=%d\n",*ptr);
    *ptr=100;
    printf("Inside modify-after :*ptr=%d\n",*ptr);
}
int main(){
int num =5;
printf("Before calling modify:num=%d\n",num);
modify(&num);

printf("After calling modify num =%d\n",num);
return 0;
}
