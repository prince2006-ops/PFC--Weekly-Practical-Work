#include <stdio.h>
int main(){
    int size =10;
    double mylist[size];
    printf("Enter %d value form the keyboard: \n",size);

    for (int i=0 ; i< size ;i++){
        printf("Enter value %d: ",i+1);

        if (scanf("%lf",&mylist[i])!=1){
            printf("Error: Invalid input \n");
            while(getchar()!= '\n');
            i--;
            continue;
        }
        if (mylist[i]<0){
            printf("Error: Only positive number allowed \n");
            i--;
            continue;
        }
    }
    return 0;
}