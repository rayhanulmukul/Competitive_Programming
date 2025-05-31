#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
void enqueue(int a){
    Node *new_node = new Node;
    new_node -> data = a;
    new_node -> next = NULL:
}