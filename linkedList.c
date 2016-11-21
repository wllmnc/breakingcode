#include <stdlib.h>
#include <stdio.h>
typedef struct node {
    int val;
    struct node * next;
} node_t;
void print_list(node_t * head);
void push(node_t * head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);
int remove_index(int index, node_t ** head);
int remove_byValue(node_t ** head,int val);

void main(){

	node_t * head = NULL;
	head = malloc(sizeof(node_t));
        remove_index(5,&head);
	head->val =0; 
	head->next = NULL;
        remove_index(5,&head);
	int i=1;
	for(i;i<10;i++){
		push(head,i);
		print_list(head); 
		}
	remove_index(5,&head);
	remove_byValue(&head,2);
 	print_list(head);
    }
int remove_index(int index, node_t ** head)
{
	int count=1;
	int retval=-1;
	node_t * current = *head;
        node_t * tempN   =  NULL;

	while (current->next != NULL && count<index-1) {
		current = current->next;
		count++;
	}

        if(count==index-1)
	{
		retval = current->val;
                tempN  = current->next;
		current->next = tempN->next;
		free(tempN);
	}
	return retval;
}
int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    /* get to the last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    /* now current points to the last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
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
int remove_byValue(node_t ** head,int val) {
	node_t * current = *head;
	node_t * prev   = NULL;
	int retval=-1;
	while (current != NULL) {        
        	if(val==current->val){
			retval=val;
			prev->next=current->next;
			free(current);		
			break;
		}
		prev=current;
	        current = current->next;
	}
	return retval;
}
