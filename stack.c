#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node stack;

stack *create_new_node (int value) {
    stack *result = malloc(sizeof(stack));
    result->value = value;
    result->next = NULL;
    return result;
}

stack *head = NULL;


bool is_empty(stack *head) {
    if(head->next == NULL) {
        return true;
    } else {
        return false;
    }
}

bool push(int value) {
    stack *new_node = malloc(sizeof(stack));

    if(new_node == NULL) {
        return false;
    } else {
        new_node->value = value;
        new_node->next = head;
        head = new_node;
    return true;
    }

    
}

void pop(){
    
    if(!is_empty(head)) {
        //int result = head->value;
        stack *tmp = head;
        head = head->next;
        free(tmp);
    } else {
        printf("pilha vazia!");
    }
}

void print_stack(stack *head) {
    stack *temporary = head;

    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        temporary = temporary->next;
    }

    printf("\n");   
}

int main() {
    push(6);
    push(3);
    push(99);
    print_stack(head);
    pop();
    print_stack(head);
    
}