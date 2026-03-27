#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(){

    struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));

    if(node1 == NULL || node2 == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    node1->data = 10;
    node2->data = 20;

    node1->next = node2;
    node2->next = NULL;

    printf("Node1 data: %d\n", node1->data);
    printf("Node2 data: %d\n", node2->data);

    free(node1);
    free(node2);

    return 0;
}