#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct List{
    struct Node* head;
    // struct Node* tail;
};

void insert_at_front(struct List* list , int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("Memory allocation failed");
        return;
    }
    new_node->next = list->head;
    new_node->value = value;
    list->head = new_node;
    return;
    
}

void insert_at_end(struct List* list, int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("Memory allocation failed");
        return;
    }
     new_node->next = NULL;
    new_node->value = value;
    if(list->head == NULL){
        list->head = new_node;
        return;
    }
   
    struct Node* current = list->head;
    while(current->next != NULL){
        current =current ->next;
    }
    current->next = new_node;\
    // OR using tail pointer
    // list->tail->next = new_node;
    // list->tail = new_node;
    return;
}
void insert_at_k_position(struct List* list, int value , int k){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = list->head;
    if(new_node == NULL){
        printf("Memory allocation failed");
        return;
    }
    new_node->next = NULL;
    new_node->value = value;
    if(list->head == NULL){
        list->head = new_node;
        return;
    }
    for(int i=1;i<k;i++){
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;

}

void delete_from_front(struct List* list){
    if(list->head == NULL){
        printf("No nodes in linked list");
        return;
    }
    if(list->head->next == NULL){
        list->head = NULL;
        return;
    }
    struct Node* deleted_node = list->head;
    list->head = list->head->next;
    free(deleted_node);
    return;

}

void delete_from_end(struct List* list){
    struct Node* current = list->head;
    while(current->next->next != NULL){
        current = current->next;
    }
    struct Node* deleted_node = current->next;
    current->next = NULL;
    free(deleted_node);
    return;
}

void delete_at_k_position(struct List* list , int k){
    struct Node* current = list->head;
    for(int i=1;i<k-1;i++){
        current = current->next;
    }
    struct Node* deleted_node = current->next;
    current->next = current->next->next;
    free(deleted_node);
    return;

}
void print_list(struct List* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){

    return 0;
}