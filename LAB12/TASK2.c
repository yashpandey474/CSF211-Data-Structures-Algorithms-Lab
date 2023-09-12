/*
The major steps of the algorithm are as follows:
Start off with all nodes being white. Initialize an empty queue.
Mark the source s as grey and enqueue it
While the queue is not empty:
    Dequeue a node u
    For each white node v adjacent to u:
        Mark v as grey
        Enqueue v
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
    G->adjacency_matrix = (int**)malloc(sizeof(int*)*G->V);
    // Allocate memory for each row of the adjacency matrix
    for(int i = 0; i<G->V; i++){
        G->adjacency_matrix[i] = (int*)malloc(sizeof(int)*G->V);
        memset(G->adjacency_matrix[i], 0, sizeof(int)*G->V);
    }

    // Allocate memory for the vertices array (Array of |V| graph_nodes)
    G->vertices = (graph_node*)malloc(sizeof(graph_node)*G->V);

    // Initialize all the vertices to WHITE
    for(int i = 0; i<G->V; i++){
        G->vertices[i].data = i;
        G->vertices[i].c = WHITE;
    }

    return G;
}

// BFS
void bfs(Graph *G, int s)
{
    // Initialize the queue
    queue* Q = get_queue();

    printf("BFS: ");

    // Mark the source s as grey and enqueue it

    //1. ALL NODES ARE WHITE: DONE IN GET_GRAPH

    //2. MARK SOURCE AS GREY AND ENQUEUE IT
    G->vertices[s].c = GREY;
    enqueue(Q, s);

    // While the queue is not empty:
    while (!is_empty(Q))
    {
        // Dequeue a node u
        int current = dequeue(Q); //INDEX AND DATA OF VERTEX

        // Print the data of the dequeued node that would now be explored
        printf("%d ", G->vertices[current].data);

        // For each white node v adjacent to u:
        for (int v = 0; v < G->V; v++)
        {
            if (G->adjacency_matrix[current][v] == 1 && G->vertices[v].c == WHITE)
            {
                G->vertices[v].c = GREY;
                // Mark v as grey

                // Enqueue v
                enqueue(Q, v);
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
    bfs(G, 0);

    return 0;
}