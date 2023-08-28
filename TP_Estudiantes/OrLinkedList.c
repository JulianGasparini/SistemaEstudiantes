#include <stdio.h>
#include <malloc.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef struct OrLinkedList {
    Node *head;
    int size;

} OrLinkedList;

OrLinkedList *newList() {
    OrLinkedList *list = malloc(sizeof(OrLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

OrLinkedList *addNode(OrLinkedList *list, int data) {

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->size = 1;
    } else {
        Node *pointer = list->head;
        while (pointer->next != NULL && pointer->next->data < data) {
            pointer = pointer->next;
        }
        if (pointer->next == NULL) {
            if (pointer->data > data) {
                newNode->next = list->head;
                list->head = newNode;
            } else {
                pointer->next = newNode;
            }
        } else {
            Node *consecutive = pointer->next;
            pointer->next = newNode;
            newNode->next = consecutive;
        }
        list->size += 1;
    }
    return list;
}

int sizeOfList(OrLinkedList *list) {
    printf("Size: %d", list->size);
    return list->size;
}

int get(OrLinkedList *list, int element) {
    Node *header = list->head;
    if (element > list->size) {
        printf("error: elemento inexistente");
    }
    for (int i = 0; i < element; i++) {
        header = header->next;
    }
    return header->data;
}

OrLinkedList* delete(OrLinkedList *list, int element) {
    Node *previous = list->head;
    if (element > list->size) {
        printf("error: elemento inexistente");
    }
    if(element==0){
        OrLinkedList* newHead = newList();
        newHead->head = previous->next;
        newHead->size = list->size-1;
        free(previous);
        return newHead;
    }else{
        for (int i = 0; i < element-1; i++) {
            previous = previous->next;
        }
        Node *consecutive = previous->next->next;
        free(previous->next);
        previous->next = consecutive;
        list->size -=1;
        return list;}
}


void printList(OrLinkedList *list) {
    Node *pointer = list->head;
    while (pointer->next != NULL) {
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
    printf("%d\n", pointer->data);
}


int main() {
    OrLinkedList *list = newList();
    addNode(list, 7);
    addNode(list, 1);
    addNode(list, 4);
    addNode(list, 16);
    addNode(list, 99);
    addNode(list, 4);
    addNode(list, 16);
    addNode(list, 99);
    addNode(list, 4563);
    addNode(list, 16213456);
    addNode(list, 991241);
    printList(list);
    sizeOfList(list);
    printf("\n-----\n");
    printf("%d\n", get(list, 0));
    list = delete(list, 0);
    printf("-----\n");
    printList(list);
    sizeOfList(list);
    return 0;
}