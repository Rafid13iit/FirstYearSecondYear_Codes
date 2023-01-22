#include <stdio.h>
#include <stdlib.h>
struct node* createNode (int data);
void inOrder (struct node *root);

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main ()
{
    int root;

    printf("What is the root?\n");
    scanf("%d", &root);

    struct node *p = createNode(root);
    //other
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(5);
    struct node *p3 = createNode(3);
    struct node *p4 = createNode(8);
    struct node *p5 = createNode(1);
    struct node *p6 = createNode(6);
    struct node *p7 = createNode(7);

    //linking the node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    p2->left = p6;
    p2->right = p7;

    /*the tree is :
               root
             /     \
            2       5
          / \      / \
         3   8    6   7
        /
       1                    */

    printf("In order sequence is : Left -> Root -> Right\n");
    inOrder(p);
}

struct node* createNode (int data)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;//returning the created node
}

void inOrder (struct node *root)
{
    if (root != NULL){
        inOrder (root->left);
        printf("%d ", root->data);
        inOrder (root->right);
    }
}


