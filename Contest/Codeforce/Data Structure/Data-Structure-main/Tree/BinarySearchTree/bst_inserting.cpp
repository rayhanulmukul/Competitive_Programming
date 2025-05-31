#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int item)
    {
        data = item;
        left = right = NULL;
    }
};

Node *insert(Node *root, int item)
{
    Node *currNode = root;
    Node *newNode = new Node(item);

    while (currNode)
    {
        if (currNode->data > item)
        {
            if (currNode->left)
                currNode = currNode->left;
            else
            {
                currNode->left = newNode;
                break;
            }
        }
        else if (currNode->data < item)
        {
            if (currNode->right)
                currNode = currNode->right;
            else
            {
                currNode->right = newNode;
                break;
            }
        }
        else
            return root;
    }
    return root ? root : newNode;
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int key[] = {7, 6, 4, 5, 9, 8, 10, 25, 12, 9, 11, 2, 3, 1};
    for (int item : key)
    {
        root = insert(root, item);
    }
    cout << root->data << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}
