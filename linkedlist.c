#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node_t;

void printlist(node_t *head) {
    //ponteiro temporario
    node_t *temporary = head;

    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        temporary = temporary->next;
    }

    printf("\n");   
}

node_t *create_new_node (int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t *find_node(node_t *head, int value) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }

    return NULL;
}
/*
Primeiro procura o Nó a ser deletado
pecorre a lista novamente
Se o tmp.next for igual ao Nó achado
o tmp.next = delete.next
Solução muito custosa requer percorrer a lista 2 vezes (talvez tenha uma forma melhor)
*/
void *delete_node(node_t *head, node_t *node_to_delete) {
    node_t *tmp = head;
    node_t *deleted;
    deleted = find_node(head, node_to_delete->value);
    while (tmp != NULL)
    {
        if (tmp->next == deleted)
        {
            tmp->next = deleted->next;
            printf("Nó deletado!\n");
            free(node_to_delete);
        }
        tmp = tmp->next;
    }
    
}

void update_node(node_t *node_to_update, int value) {
    node_to_update->value = value;
}

void insert_after_node(node_t *node_to_insert_after, node_t *new_node) {
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

//teste
int main () {
    node_t *head = NULL;
    node_t *tmp;

    for(int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);

    }
    
    tmp = find_node(head,5);
    printf("Nó achado com o valor: %d\n",tmp->value);

    insert_after_node(tmp, create_new_node(76));

    printlist(head);
    tmp = find_node(head, 15);

    delete_node(head, tmp);
    printlist(head);

    tmp = find_node(head, 18);
    update_node(tmp, 59);
    printlist(head);
    
}