#include<stdio.h>
#include <stdlib.h>
#define N 6

struct Node {
    int dest;
    struct Node* next;
};
typedef struct Node node;

struct Graph {
    node* head[N];
};
typedef struct Graph graph;

graph* createGraph(int n) {
    graph* g = (graph*)malloc(sizeof(graph));

    for(int i = 0; i < n; i++) {
        g->head[i] = NULL;
    }

    printf("Enter number of Edges : ");
    int E;
    scanf("%d", &E);

    for(int i = 0; i < E; i++) {
        int src, dest;
        printf("Enter source and destination : ");
        scanf("%d %d", &src, &dest);

        node *newNode1 = (node*)malloc(sizeof(node));
        newNode1->dest = dest;
        newNode1->next = NULL;
        if(g->head[src] == NULL) g->head[src] = newNode1;
        else {
            node *temp = g->head[src];
            while(temp->next != NULL) temp = temp->next;
            temp -> next = newNode1;
        }


        node *newNode2 = (node*)malloc(sizeof(node));
        newNode2->dest = src;
        newNode2->next = NULL;
        if(g->head[dest] == NULL) g->head[dest] = newNode2;
        else {
            node *temp = g->head[dest];
            while(temp->next != NULL) temp = temp->next;
            temp -> next = newNode2;
        }

    }
    return g;
}

void printGraph(graph* g, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d --> ", i);
        node *temp = g->head[i];
        while(temp != NULL) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {

    int n;
    printf("Enter number of Nodes : ");
    scanf("%d",&n);

    graph *graph1 = createGraph(n);

    printGraph(graph1, n);

    return 0;

}
