#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Queue *newQueue(){
    Queue *new = (Queue *) malloc(sizeof(Queue));
    
    new->head = NULL;
    new->tail = NULL;
    new->length = 0;
}

int isEmptyQueue(Queue *queue){
    return queue->length == 0;
}

int dequeue(Queue *queue){
    if(isEmptyQueue(queue)){
        printf("Não é possível retirar um elemento da fila vazia\n");
        return 0;
    }

    int data = queue->head->data;
    Celula *newHead = queue->tail;
    // printf("%d\n", newHead->data);

    for(int i = 1; i < queue->length - 1; i++){
        newHead = newHead->next;
        // printf("%d\n", newHead->data);
    }

    newHead->next = NULL;

    free(queue->head);
    queue->head = newHead;
    queue->length--;

    printf("%d\n", data);
    return data;
}

int enqueue(Queue *queue, int data){
    Celula *new = (Celula *) malloc(sizeof(Celula));

    if(!new){
        return 1;
    }

    if(isEmptyQueue(queue)){ //se for o primeiro elemento da fila
        queue->head = new;
    }

    new->data = data;
    new->next = queue->tail;

    queue->tail = new;
    queue->length++;

    return 0;
}

int getLengthQueue(Queue *queue){
    return queue->length;
}

void deleteQueue(Queue *queue){
    free(queue);
}