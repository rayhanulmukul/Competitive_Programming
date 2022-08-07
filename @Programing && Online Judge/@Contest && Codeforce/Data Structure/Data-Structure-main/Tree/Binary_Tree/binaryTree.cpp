#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
Node *root;

Node *makeTree()
{
    Node *newNode;
    newNode = NULL;
    return newNode;
}

void insert(int item)   // iterative inserting
{ 
    if (root == NULL)
    {
        root = new Node(item);
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (!(temp->left))
        {
            temp->left = new Node(item);
            return;
        }
        else if (!(temp->right))
        {
            temp->right = new Node(item);
            return;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
}

void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    root = makeTree();

    int key[10] = {1, 3, 5, 6, 8, 2, 7, 9, 4, 10};

    for (int i = 0; i < 10; i++)
        insert(key[i]);

    cout << "Pre Order : ";
    preOrder(root);
    cout << endl;
    cout << "Post Order : ";
    postOrder(root);
    cout << endl;

    return 0;
}
