#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node **head, int value);

void display(struct Node *head);

void quick_sort(struct Node *first, struct Node *last);

struct Node *partition(struct Node *first, struct Node *last);

struct Node *last_node(struct Node *head);

int main ()
{
    struct Node *head = NULL;

    int n, i, x;

    printf("How many elements do you want?\n");
    scanf("%d", &n);

    printf("\nEnter the elements :\n");

    for (i=0; i<n; i++){
        scanf("%d", &x);
        insert (&head, x);
    }

    printf("\nBefore sorting :\n");

    display(head);
    printf("\n");

    quick_sort(head, last_node(head));

    printf("\nAfter sorting :\n");

    display(head);
    printf("\n");

    return 0;
}


void insert(struct Node **head, int value)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL) printf("Memory not allocated!\n");

    else {
        node->data = value;
        node->next = NULL;

        if (*head == NULL) *head = node;

        else {
            struct Node *temp = *head;

            while (temp->next != NULL){
                temp = temp->next; // last node find
            }

            temp->next = node;
        }
    }
}


void display(struct Node *head)
{
    if (head == NULL){
        printf("empty linked list!\n");
        return;
    }

    else {
        struct Node *temp = head;

        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

    }
}


void quick_sort(struct Node *first, struct Node *last)
{
    if (first == last) return;

    else {
        struct Node *pivot = partition(first, last);

        if (pivot != NULL && pivot->next != NULL){
            quick_sort(pivot->next, last);
        }

        if (pivot != NULL && first != pivot){
            quick_sort(first, pivot);
        }
    }
}


struct Node *partition(struct Node *first, struct Node *last)
{
    struct Node *pivot = first;
    struct Node *front = first;

    int temp = 0;

    while (front != NULL && front != last){

        if (front->data < last->data){

            pivot = first;
            temp = first->data;

            first->data = front->data;
            front->data = temp;

            first = first->next;
        }

        front = front->next;
    }

    temp = first->data;
    first->data = last->data;
    last->data = temp;

    return pivot;
}


struct Node *last_node(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL && temp->next != NULL){
        temp = temp->next;
    }

    return temp;
}

