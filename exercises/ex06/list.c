/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}

int swap(Node **list) {
    if(*list == NULL || (*list)->next == NULL){
        return -1;
    }    
    Node *nextNode = (*list)->next;
    Node *first = (*list);
    first->next = nextNode->next;
    nextNode->next = first;
    *list = nextNode;
    return 0;
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
	int resVal;
	Node *current = *list;
    if(*list == NULL){
    	return -1;
    } else{
    	resVal = current->val;
    	*list = current->next;
    	free(current);
    	return resVal;
    }
    return 0;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *head = make_node(val, *list);
    *list = head;
    // FILL THIS IN!
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    if(*list == NULL){
    	return 0;
    }
    Node *current = *list;
    Node *temp;
    while (current->next != NULL) {
    	if(current->next->val == val){
    		temp = current->next;
    		current->next = current->next->next;
    		free(temp);
    		return 1;
    	}
        current = current->next;
    }
    return 0;
}

/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
	if(*list == NULL){
		return;
	}
	Node *current = (*list)->next;
	Node *prevNode = *list;
	Node *nextNode;
    while(current != NULL){
    	nextNode = current->next;
    	current->next = prevNode;
    	prevNode = current;
    	current = nextNode;
    }
    (*list)->next = NULL;
    *list = prevNode;
}


int main() {
    Node *head = make_node(1, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    int success = swap(list);
    print_list(list);
    printf("%d\n", success);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
