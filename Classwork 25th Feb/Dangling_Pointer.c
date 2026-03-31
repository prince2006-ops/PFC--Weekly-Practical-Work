// // // // #include <stdio.h>
// // // // int *getDanglingPointer(){
// // // //     int x=42;
// // // //     return &x;
// // // // }
// // // // int main(){
// // // //     int *ptr =getDanglingPointer();
// // // //     printf("%d\n",*ptr);
// // // //     return 0;
// // // // }

// // // #include<stdio.h>
// // // #include<stdlib.h>
// // // int main(){
// // //     int *ptr=(int*)malloc(sizeof(int));
// // //     *ptr=42;
// // //     free(ptr);
// // //     *ptr=100;
// // //     return 0;
// // // }
// // #include<stdio.h>
// // #include<stdlib.h>
// // int *getSafePointer(){
// //     int *x= (int*) malloc(sizeof(int));
// //     if(x!=NULL){
// //         *x=42;
// //     }
// //     return x;
// // }
// // int main(){
// //     int *ptr=getSafePointer();
// //     if(ptr!=NULL){
// //         printf("&d\n",*ptr);
// //         free(ptr);
// //     }
// // return 0;
// // }
// #include <stdio.h>
// int *getStaticPointer(){
//     static int x=42;
//     return &x;
// }
// int  main(){
//     int *ptr=getStaticPointer();
//     printf("%d\n",*ptr);
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr=(int*)malloc(sizeof(int));
    *ptr=42;
    free(ptr);
    ptr=NULL;
    if(ptr!=NULL){
        *ptr=100;
    }
    else{
        printf("Pointer is NULL,safe from dangling use\n");
    }
    return 0;
}