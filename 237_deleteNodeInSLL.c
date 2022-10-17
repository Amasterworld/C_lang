/*
237.delete the node in the singly linked list - C language
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next; // in C++ we only need to write: node* next;
};

/*if we want to avoid repeat struct node in the future, so we can:

    typedef struct node{
        int val;
        struct node* next;
    }Node; 
    from now we can use Node instead of struct node
*/
void addLastNode(struct node** head, int input_val) {

    /*create a new node when we add */
    struct node* newNode = malloc(sizeof(struct node));
    /*assign the val of newNode to input val*/
    newNode->val = input_val;
    newNode->next = NULL;
    /*if head is pointing to NULL that means the LL is empty then head should assign the address of the newNode*/
    if(*head == NULL) {
        *head = newNode;
    }
    /*Otherwise, find the final node and assign it to the newNode*/
    else{
        struct node* final_node = *head;

        while(final_node->next != NULL){
            final_node = final_node->next;
        }
    final_node->next = newNode;
    }  

}
void deleteNode(struct node** head, int del_val){

    /*whenver find the node->next->val == del_val (if node is not head), immediately isolate it, however if we only isolate it
    it can create mem leak, to avoid it we should use temp pointer to keep address of the del_node to free(temp) late  */

    struct node* temp_node; // keep address of the del_node to free it later
    if((*head)->val == del_val) {
        temp_node = *head;
        /*isolate current head by connecting it the next node */
        *head = (*head)->next;
        /*free the old head or temp_node to avoid mem leak*/
        free(temp_node);
    }
    /*Otherwise, we should find which node contain the val == del_val*/
    else{
        struct node* current = *head;
        while(current != NULL){
            if(current->val != del_val){
                current = current->next;
            }
            else{
                temp_node = current->next; //to delete later
                /*replace the value of the current node by the value of the next node*/
                current->val = current->next->val;
                current->next = temp_node->next; // or = current->next->next;
                /*now temp_node should be deleted or freed  after coping its value and connect to the next its node*/
                free(temp_node);
                return;

            }
        }
    }
    printf("the input_value doest not maych with any values in nodes\n");
    /*note that the above code lines still can make them more compact*/
}

void printList(struct node *head){
    if (head == NULL){
        printf("list is empty \n");
        return;
    } 
    while (head != NULL){
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
/*drive code*/
int main(){
    struct node* head = NULL;
    addLastNode(&head, 10);
    addLastNode(&head, 39);
    addLastNode(&head, 52);
    addLastNode(&head, 10);
    addLastNode(&head, 31);
    addLastNode(&head, 102);

    /*print the input list*/
    printList(head);
    /*delete the node->val = 39*/
    deleteNode(&head, 103);
    printList(head);
    return 0;
}
