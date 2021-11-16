#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

void init_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value) {
    //cria um novo node
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL) return false;
    new_node->value = value;
    new_node->next = NULL;

    //se tem um tail, conecta ele com o novo node
    if(q->tail != NULL) {
        q->tail->next = new_node;
    }
    q->tail = new_node;

    //ter certeza que o head ainda aponta pro lugar certo
    if (q->head == NULL) {
        q->head = new_node;
    }
    return true;
}

int dequeue(queue *q) {
    if(q->head == NULL) return QUEUE_EMPTY;

    node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if(q->head == NULL) {
        q->tail = NULL;
    }

    free(tmp);
    return result;
}

int main() {
    queue q1;
    init_queue(&q1);

    enqueue(&q1, 5);
    enqueue(&q1, 32);
    enqueue(&q1, 10);
    enqueue(&q1, 99);

    int i;
    while ((i = dequeue(&q1)) != QUEUE_EMPTY) {
        printf("i = %d\n", i);
    }
    
}