#include <stdio.h>


typedef struct Node {
    void *data;
    struct Node *next;
} Node;
typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;

/**
 * Creates a new LinkedList instance.
 *
 * @return A pointer to the newly created LinkedList.
 */
LinkedList *create_list() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

/**
 * @post add node and increase list size by 1
 * 
 * @param list-> pointer to head of List
 * @param data-> pointer to any data type
 */
void list_add_node(LinkedList *list, void *data) {

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->size = 1;
    } else {
        Node *pointer = list->head;
        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        pointer->next = newNode;
        list->size += 1;
    }
}

/**
 * 
 * @param list-> pointer to head of list
 * @return amount of elements in the list
 */
int size_of_list(LinkedList *list) {
    return list->size;
}

/**
 * @param list-> pointer to head of list 
 * @param index ->  index of element
 * @return pointer to index of position "index"
 */
void *list_get(LinkedList *list, int index) {
    Node *header = list->head;
    if (index > list->size) {
        printf("error: elemento inexistente");
    }
    for (int i = 0; i < index; i++) {
        header = header->next;
    }
    return header->data;
}

/**
 * @param list-> pointer to head of list
 * @param data-> pointer to wanted data
 * @return true if data inside the list, false if not
 */
bool list_contains(LinkedList *list, void *data) {
    Node *pointer = list->head;
    while (pointer->next != NULL) {
        if (pointer->data == data)
            return true;
        pointer = pointer->next;
    }
    return false;
}

/**
 *  @post frees memories being used by a list
 *  @param list-> pointer to head of list
 */
void delete_list(LinkedList *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    free(list);
}

/**
 * Deletes an element while maintaining list structure.
 * @param list -> pointer to head of list
 * @param element -> index of element to delete
 * @return list with deleted element
 */
LinkedList *list_delete_element(LinkedList *list, int element) {
    Node *previous = list->head;
    if (element > list->size) {
        printf("error: elemento inexistente");
    }
    if (element == 0) {
        LinkedList *newHead = create_list();
        newHead->head = previous->next;
        newHead->size = list->size - 1;
        free(previous);
        return newHead;
    } else {
        for (int i = 0; i < element - 1; i++) {
            previous = previous->next;
        }
        Node *consecutive = previous->next->next;
        free(previous->next);
        previous->next = consecutive;
        list->size -= 1;
        return list;
    }
}
