#include<stdio.h>
void printArray(int arr[],int size){
    printf("Array elements: ");
    for (int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
int main(){
    int myArray[] = {100,200,300,400,500};
    int size=sizeof(myArray)/sizeof(myArray[0]);
    printArray(myArray,size);
    return 0;
}