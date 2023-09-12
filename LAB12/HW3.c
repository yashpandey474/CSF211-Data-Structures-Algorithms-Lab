/**
 * We haven't actually searched in our implementation of Breadth-First-Search yet.
 *  Add a function to t2.c that takes a directed unweighted graph G,
 *  a source s and a target t and prints the path from the source to the target. 
 * [Hint: You might want to add a predecessor attribute in the graph node]
 * 
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

typedef struct queue
{
    ll_node *front;
    ll_node *rear;
} queue;

queue *get_queue()
{
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

void enqueue(queue *Q, int data)
{
    ll_node *temp = (ll_node *)malloc(sizeof(ll_node));
    temp->data = data;
    temp->next = NULL;
    if (Q->rear == NULL)
    {
        Q->front = temp;
        Q->rear = temp;
    }
    else
    {
        Q->rear->next = temp;
        Q->rear = temp;
    }
}

int is_empty(queue *Q)
{
    return Q->front == NULL;
}

int dequeue(queue *Q)
{
    if (is_empty(Q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    ll_node *temp = Q->front;
    int data = temp->data;
    Q->front = Q->front->next;
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
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

    // HW2: DISTANCE FROM SOURCE
    int distance;

    //HW3: STORE PREDECESSOR
    int predecessor;
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
        G->vertices[i].distance = 2 * (G->V);
        G->vertices[i].predecessor = -1;
    }

    return G;
}

// HW3: PRINT A PATH FROM A SOURCE VERTEX TO TARGET VERTEX USING BFS
void printPath(struct Graph *G, int source, int target)
{
    if (source == target)
    {
        printf("%d -> ", source);
    }
    else if (G->vertices[target].predecessor == -1)
    {
        printf("NO PATH FOUND FROM SOURCE TO VERTEX");
    }
    else
    {
        printPath(G, source, G->vertices[target].predecessor);
        printf("%d -> ", target);
    }
}

// BFS
void bfs(Graph *G, int source, int target)
{
    // Initialize the queue
    queue *Q = get_queue();

    // Mark the source s as grey and enqueue it

    // 1. ALL NODES ARE WHITE: DONE IN GET_GRAPH

    // 2. MARK SOURCE AS GREY AND ENQUEUE IT
    G->vertices[source].c = GREY;

    // SET DISTANCE OF SOURCE AS 0
    G->vertices[source].distance = 0;

    //NO PREDECESSOR IN PATH
    G->vertices[source].predecessor = -1;


    enqueue(Q, source);

    // While the queue is not empty:
    while (!is_empty(Q))
    {
        // Dequeue a node u
        int current = dequeue(Q); // INDEX AND DATA OF VERTEX

        // For each white node v adjacent to u:
        for (int v = 0; v < G->V; v++)
        {
            if (G->adjacency_matrix[current][v] >= 1 && G->vertices[v].c == WHITE)
            {

                // Mark v as grey
                G->vertices[v].c = GREY;

                G->vertices[v].distance = G->adjacency_matrix[current][v] + G->vertices[current].distance;

                G->vertices[v].predecessor = current;
                // Enqueue v
                enqueue(Q, v);
            }
        }

        // Mark u as black
        G->vertices[current].c = BLACK;
    }


    printPath(G, source, target);
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
    bfs(G, 0, 3);

    return 0;
}