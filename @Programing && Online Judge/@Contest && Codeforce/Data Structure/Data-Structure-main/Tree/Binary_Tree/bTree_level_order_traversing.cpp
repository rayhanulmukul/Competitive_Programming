#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
    Node() {

    }

    Node* insert(Node *root, int data) {
        if(root == NULL) {
            root = new Node(data);
            return root;
        }
        queue<Node *> q;
        q.push(root);

        while(!(q.empty())) {
            Node *currNode = q.front();
            q.pop();

            if(!currNode->left) {
                currNode->left = new Node(data);
                break;
            }
            else if(!currNode->right) {
                currNode->right = new Node(data);
                break;
            }
            q.push(currNode->left);
            q.push(currNode->right);
        }
        return root;
    }

    void inOrder(Node *root) {
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void levelOrder(Node *root) {
        if(root == NULL) {
            cout << "tree is empty!"<< endl;
            return;
        }
        queue<Node *> q;
        q.push(root);
        while(!q.empty()) {
            Node *currNode = q.front();
            q.pop();

            cout << currNode->data << " ";
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        cout << endl << "level Order done!\n";
    }
};

int main() {
    Node tree;
    Node *root = NULL;
    root = tree.insert(root, 5);
    root = tree.insert(root, 9);
    root = tree.insert(root, 7);
    root = tree.insert(root,4);
    root = tree.insert(root, 2);
    root = tree.insert(root, 20);

    tree.inOrder(root);
    cout << endl;
    tree.levelOrder(root);

    return 0;
}

