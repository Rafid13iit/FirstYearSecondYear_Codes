#include <stdio.h>
#include <stdlib.h>
void create();
void display();

struct node{
    int info;
    struct node *next;
};
struct node *start = NULL;

int main()
{
    create();
    display();

    while (start != NULL){
        printf("%d -> ", start->info);
        start = start->next;
    }

    printf("NULL\n");

    return 0;
}

void create()
{
        struct node *temp, *ptr;
        temp = (struct node *)malloc(sizeof(struct node));

        if(temp == NULL){
            printf("Out of Memory Space: ");
            exit(0);
        }

        printf("Enter the data values for the node: ");

        for (int i=0; i<4; i++){
            scanf("%d", &temp->info);
            temp->next = temp;
        }
        temp->next = NULL;

        if(start == NULL){
            start = temp;
        }
        else{
            ptr = start;

            while(ptr->next != NULL){
                ptr = ptr->next;
            }

            ptr->next = temp;
        }
}

void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("nList is empty:n");
                return;
        }
        else
        {
            ptr=start;
            printf("nThe List elements are:n");
            while(ptr!=NULL){
                printf("%dt",ptr->info );
                ptr=ptr->next ;
            }
        }
}

