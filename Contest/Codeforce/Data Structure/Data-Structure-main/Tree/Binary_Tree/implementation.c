#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} * root;
typedef struct Node node;

// Inorder travesal
void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Preorder traversal
void preOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Postorder traversal
void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// returning a dynamically allocated node with a given value.
node *getNode(int item)
{

    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Add an element to the left child
node *addLeftChild(node *tree, int item)
{
    tree->left = getNode(item);
    return tree->left;
}

// Add an element to the right child
node *addRightChild(node *tree, int item)
{
    tree->right = getNode(item);
    return tree->right;
}

int main()
{

    root = getNode(2);  // set the root node

    node *rootLeft = addLeftChild(root, 5);   // add root nodes left child
    node *rootRight = addRightChild(root, 8);  // add root nodes right child

    node *rootLeft_left = addLeftChild(rootLeft, 10);  // add root-left nodes left child
    node *rootLeft_right = addRightChild(rootLeft, 11);   // add root-left nodes right child

    node *rootRight_left = addLeftChild(rootRight, 3);  // add roog-right nodes left child
    node *rootRight_right = addRightChild(rootRight, 4);  // add root-right nodes right child

    printf("\nInorder Traversing : "); 
    inOrderTraversal(root);  // traverse inorder

    printf("\nPreOrder Traversing : ");
    preOrderTraversal(root);  // traverse preorder

    printf("\nPostOrder Traversing : ");
    postOrderTraversal(root);  // traverse postorder

    return 0;
}
