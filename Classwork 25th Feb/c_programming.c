#include<stdio.h>
int main(){
    int x=10;
    int *p=&x;
    printf("1.Basic Pointer\n");
    printf("Value of x =%d\n",x);
    printf("Address of x=%p\n",&x);
    printf("Pointer p stores=%p\n",p);
    printf("value at address(*p)=%d\n\n",*p);
    *p=20;
    printf("2. Dereferencing\n");
    printf("New value of x =%d\n\n",x);
    int arr[3]={10,20,30};
    int *ptr=arr;
    printf("Pinter with array:\n");
    for (int i=0;i<3;i++){
        printf("value:%d | Address:%p\n",*(ptr+i),(ptr+i));
    }
    printf("%d",arr[0]);
    printf("%p",ptr);
    
    int *d=(int*)malloc(sizeof(int));
    if(d == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    *d = 50000;
    printf("\n4.Malloc\n");
    printf("Value in heap=%d\n\n",*d);
    
    int *dynArr = (int*) malloc(3*sizeof(int));
    for(int i=0;i<3;i++){
        printf("%d\n",dynArr[i]);
    }
    printf("\n\n");
    
    
    int *temp =  realloc(dynArr, 5 *sizeof(int));
    if(temp ==NULL)
    {
        printf("Realloc failed!\n");
        free(dynArr);
        return 1;
    }

    dynArr = temp;
    
    //initialize new elements
    dynArr[3] = 40;
    dynArr[4] = 50;

    printf("6. Realloc\n\n");
    for (int i =0 ; i<5 ; i++)
    {
        printf("%d \n", dynArr[i]);
    }
    printf("\n\n");
   return 0;
}