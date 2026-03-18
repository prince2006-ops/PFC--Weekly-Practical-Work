#include<stdio.h>
#include<stdlib.h>

int main(){
    /* Intro to dynamic memory allocation
    In C , memory can be added in two ways:
    1. Static (compile-time)
    Example: int a[5];
    2. Dynamic (run-time)--> USING HEAP MEMORY
    fUNCTION:
    -malloc()
    -calloc()
    -realloc()
    -free()
    Heap= large memory area used for dynamic allocation.*/
    
    printf("=== DYNAMIC MEMORY ALLOCATION DEMO===\n\n");
    printf("1. MALLOC DEMO\n");
    int *p;
    //allocare memory for one integer
    p=(int*) malloc(sizeof(int));
    //Always check if allocated succeeded
    if (p==NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;   
    
    }
    /* At this point:
    p points to a memory, but value is garbage
    Example (random):
    p--> 1010101010 (unknown value)
    */
   printf("Befor assigning the value(garbage): %d\n",*p);
   *p=10;
   printf("After assigning value: %d\n\n",*p);
   printf("%d",p);

   /*
   =============CAllOC()--> Allocate memory to zero)===============
   syntax:
   pointer = (type*) calloc(n,size);
   Key Points:
   -allocates memory for multiple elements
   -initializes all values to 0
   -safer than malloc when default values are needed
   */
  printf("2. Calloc DEMO \n");
  int *arr;
  // allocate memory for 5 integers
  arr=(int*)calloc(5,sizeof(int));
  if (arr==NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  /* At this point:
  arr=[0 0 0 0 0]
  */
  for (int i=0; i<5; i++){
    printf("%d\n",arr[i]);
  }
  /*
  3. REALLOC()--> resize exisiting memory

  syntax:
    pointer = realloc(pointer,new_size);
    
    Key Points:
    -Changes size of previously allocated memory
    -May expland or shrink memory
    -old values are preserved
    -Memory may move to a new location

    Common use:
    When we don't know required size innitially
  */
  printf("3. REALLOC DEMO\n");
  //Let's store some values first
  for(int i=0;i<5;i++){
    arr[i]=(i+1)*10;
  }
  printf("Before realloc:\n");
  for(int i=0;i<5;i++){
    printf("%d",arr[i]);
  }
  printf("\n");

  arr=(int*) realloc(arr,8*sizeof(int));
  if (arr==NULL){
    printf("Reallocation failed!");
    return 1;
  }
  /* After reallocation
    Old data is preserved.
    New elements contains garbage value.
  */
 printf("After realloc (new size=8):\n");
 for(int i=0;i<8;i++){
    printf("%d\n",arr[i]);
 }
 printf("\n");
    /*
    Let's assign values to new memory
    */
   arr[5]=60;
   arr[6]=70;
   arr[7]=80;
   printf("After assigning new values:\n");
   for(int i=0;i<8;i++){
    printf("%d\n",arr[i]);
   }
   printf("\n\n");
   /*
   4. Free()--> Release memory

   syntax:
    free(pointer);

    Key Points:
    -Frees allocated memory
    - Prevents memory leaks
    -After free, pointer becomes INVALID

    good practice;
    pointer =NULL;
   */
  printf("4. FREE DEMO\n");
  free(p);
  free(arr);
  // avoid dangling pointers
  p= NULL;
  arr= NULL;
  printf("Memory successfully freed.\n\n");

  /*
  FINAL SUMMARY
  malloc()--> allocate memory (grabage values)
  calloc() --> allocate + initialize to zero
  realloc()--> resize memory
  free()--> release memory

  Important Rules:
  1.Always check Null after allocation
  2. Always free allocated memory
  3. Never use pointer after free
  4.Avoid memory leaks
  */
 printf("==Program Completed Successfully\n");
 

   //dangling pointer
   //why pointer = Null is important
   int *d=(int*) malloc(sizeof(int));
   *d=5;
   free(d);
   //printf()
   /*
   Dynamic Array with User Input(real use case)
   Runtime allocation
   Real world usage*/

   int n;
   printf("Enter number of elements:");
   scanf("%d",&n);
   int *dynamicArr = (int*) malloc(n*sizeof(int));
   if (dynamicArr==NULL){
    printf("Allocation failed!\n");
    return 1;
   }
   for (int i=0;i<5;i++){
    printf("%d\n",dynamicArr[i]);
   }
   return 0;
}