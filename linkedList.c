#include <stdlib.h>
#include <stdio.h>
typedef struct node {
    int val;
    struct node * next;
} node_t;
void print_list(node_t * head);
void push(node_t * head, int val);

void main(){

node_t * head = NULL;
head = malloc(sizeof(node_t));

head->val =0; 
head->next = NULL;
int i=1;
for(i;i<10;i++){
push(head,i);
print_list(head); 
}   
}

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}


void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\t", current->val);
        current = current->next;
    }
printf("\n");
}
