#include<stdio.h>
int main(){
    char buffer[10];
    for (size_t i=0; i< sizeof buffer; i++){
        buffer[i]='A';
    }
    buffer[sizeof buffer -1]='\0';
    printf("%s\n",buffer);
    return 0;
}