/**
 * Implement DFS in the file t2.c in the same way you implemented BFS,
 * replacing the queue and queue operations with a stack 
 * and the corresponding stack operations
 */

/*
The major steps of the algorithm are as follows:
Start off with all nodes being white. Initialize an empty stack.
Mark the source s as grey and push it
While the stack is not empty:
    pop a node u
    For each white node v adjacent to u:
        Mark v as grey
        push v
    Mark u as black
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue
typedef struct linked_list_node
{
    int data;
    struct linked_list_node *next;
} ll_node;

typedef struct stack
{
    ll_node *front;
} stack;

stack *get_stack()
{
    stack *Q = (stack *)malloc(sizeof(stack));
    Q->front = NULL;
    return Q;
}

void push(stack *Q, int data)
{
    ll_node *temp = (ll_node *)malloc(sizeof(ll_node));
    temp->data = data;
    temp->next = Q->front;
    Q->front = temp;
}

int is_empty (stack *Q)
{
    return Q->front == NULL;
}

int pop(stack *Q)
{
    if (is_empty(Q))
    {
        printf("stack is empty\n");
        return -1;
    }
    ll_node *temp = Q->front;
    int data = temp->data;
    Q->front = Q->front->next;
    free(temp);
    return data;
}

typedef enum color
{
    WHITE,
    GREY,
    BLACK
} color;

// Graph Node
typedef struct graph_node
{
    int data;
    color c;
} graph_node;

// Graph
typedef struct Graph
{
    int V;
    int E;
    int **adjacency_matrix;
    graph_node *vertices;
} Graph;

// Modify the get_graph function from Task 1 to now only use the adjacency matrix and not the adjacency list
// Allocate memory for the vertices array (Array of |V| graph_nodes)
// Initialize all the vertices to WHITE
// Initialize data to the index of the vertex

Graph *get_graph(int V, int E)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->V = V;
    G->E = E;

    // Allocate memory for the adjacency matrix (V x V int array)
    G->adjacency_matrix = (int **)malloc(sizeof(int *) * G->V);
    // Allocate memory for each row of the adjacency matrix
    for (int i = 0; i < G->V; i++)
    {
        G->adjacency_matrix[i] = (int *)malloc(sizeof(int) * G->V);
        memset(G->adjacency_matrix[i], 0, sizeof(int) * G->V);
    }

    // Allocate memory for the vertices array (Array of |V| graph_nodes)
    G->vertices = (graph_node *)malloc(sizeof(graph_node) * G->V);

    // Initialize all the vertices to WHITE
    for (int i = 0; i < G->V; i++)
    {
        G->vertices[i].data = i;
        G->vertices[i].c = WHITE;
    }

    return G;
}

// BFS
void dfs(Graph *G, int s)
{
    // Initialize the queue
    stack *Q = get_stack();

    printf("DFS: ");

    // Mark the source s as grey and push it

    // 1. ALL NODES ARE WHITE: DONE IN GET_GRAPH

    // 2. MARK SOURCE AS GREY AND ENQUEUE IT
    G->vertices[s].c = GREY;
    push(Q, s);

    // While the stack is not empty:
    while (!is_empty(Q))
    {
        // pop a node u
        int current = pop(Q); // INDEX AND DATA OF VERTEX

        // Print the data of the popped node that would now be explored
        printf("%d ", G->vertices[current].data);

        // For each white node v adjacent to u:
        for (int v = 0; v < G->V; v++)
        {
            if (G->adjacency_matrix[current][v] == 1 && G->vertices[v].c == WHITE)
            {
                G->vertices[v].c = GREY;
                // Mark v as grey

                // push v
                push(Q, v);
            }
        }

        // Mark u as black
        G->vertices[current].c = BLACK;
    }
}

void add_edge_adj_matrix(Graph *G, int u, int v)
{
    G->adjacency_matrix[u][v] = 1;
}

int main()
{
    // You can change the file name to input1.txt or input2.txt to test your code for different graphs
    FILE *fp = fopen("input2.txt", "r");
    int V, E;
    fscanf(fp, "%d", &V);
    fscanf(fp, "%d", &E);
    struct Graph *G = get_graph(V, E);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        add_edge_adj_matrix(G, u, v);
    }
    fclose(fp);
    dfs(G, 0);

    return 0;
}