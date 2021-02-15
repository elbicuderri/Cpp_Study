#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int val;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* createnode(int value)
{
    treenode* node = malloc(sizeof(treenode));

    if (node != NULL)
    {
        node->left = NULL;
        node->right = NULL;
        node->val = value;
    }

    return node;
}

void printnode(treenode* root)
{
    if (root == NULL)
    {
        printf("---<empty>---\n");
        return;
    }

    printf("value: %d\n", root->val);
    printf("left\n");
    printnode(root->left);
    printf("right\n");
    printnode(root->right);
}

int main()
{
    treenode* n1 = createnode(1);
    treenode* n2 = createnode(2);
    treenode* n3 = createnode(3);
    treenode* n4 = createnode(4);
    treenode* n5 = createnode(5);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printnode(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}