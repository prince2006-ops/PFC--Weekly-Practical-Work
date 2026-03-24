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
   
    int a=100;
    int *p1=&a;
    int **p2=&p1;
    printf("7.Pointer TO POINTER");
    printf("Value of a=%d\n",a);
    printf("Using *p1=%d\n",*p1);
    printf("Using **p2=%d\n",**p2);

    int rows=2, cols=2;
    int **matrix =(int**)malloc(rows*sizeof(int*));
    for (int i=0;i<rows;i++){
        matrix[i]=(int*)malloc(cols*sizeof(int));
    }
    for(int i=0;i<rows;i++){
        {
            for(int j=0;j<cols;j++){
                printf("%d",matrix[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");

    int *mat =(int*)malloc(rows*cols*sizeof(int));
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            *(mat+i*cols+j)=i+j;
        }
        

    }
}