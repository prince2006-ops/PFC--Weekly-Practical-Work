#include<stdio.h>
#define array 5
int findMax(int *arr, int size){
    int max=*arr;
    for (int i =1; i<size;i++){
        if(*(arr+i)>max){
            max=*(arr+i);
        }
    }
    return max;
    }
int Calculate_sum(int *arr,int size){
    int sum=0;
    for (int i=0;i<size;i++){
        sum=sum+*(arr+i);
    }
    return sum;
}
    int main(){
        int number[array]={10,20,30,40,50};
        int *ptr=number;
        printf("Array elements:");
        for (int i=0;i<array;i++){
            printf("%d",*(ptr+i));
        }
        printf("\n");
        int sum=Calculate_sum(ptr,array);
        int max=findMax(ptr,array);
        printf("Sum:%d\n",sum);
        printf("Maximum=%d\n",max);
        return 0;
    }
