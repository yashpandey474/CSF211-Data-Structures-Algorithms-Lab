/**
 * A topological sort of a DAG is a linear ordering of its vertices such that
 *  for every directed edge uv from vertex u to vertex v, u comes before v in the ordering
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TIME VARIABLE
int time = 0;
// Queue
typedef struct linked_list_node
{
    int data;
    struct linked_list_node *next;
} ll_node;


typedef struct CDC{
    char code[100];
    char name[100];
} CDC;


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

//QUICK SORTING
int part(int Ls[], int lo, int hi, int pInd){
    sqap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo+1;
    rt = hi;
    pv = Ls[lo];

    while(lt<rt){
        for(; lt<= hi && Ls[lt]<=pv; lt++);

        for(; Ls[rt] > pv; rt--);

        if(lt<rt){
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }

    if(Ls[lt]<pv && lt <= hi){
        pivPos = lt;
    }
    else{
        pivPos = lt-1;
    }
    swap(Ls, lo, pivPos);
    return pivPos;
}

void qs(int Ls[], int lo, int hi){
    if(lo<hi){
        int p = pivot(Ls, lo, hi);
         p = part(Ls, lo, hi, p);

         qs(Ls, lo, p-1);
         qs(Ls, p+1, hi);
    }
}


void push(stack *Q, int data)
{
    ll_node *temp = (ll_node *)malloc(sizeof(ll_node));
    temp->data = data;
    temp->next = Q->front;
    Q->front = temp;
}

int is_empty(stack *Q)
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
    CDC data;
    color c;
    int discovery_time;
    int finishing_time;
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
        G->vertices[i].c = WHITE;
        G->vertices[i].discovery_time = -1;
        G->vertices[i].finishing_time = -1;
        G->vertices[i].predecessor = -1;
    }

    return G;
}

void recDFSVisit(struct Graph *G, int vertex)
{
    time = time + 1;

    G->vertices[vertex].discovery_time = time;
    G->vertices[vertex].c = GREY;

    for (int i = 0; i < G->V; i++)
    {
        if (G->adjacency_matrix[vertex][i] >= 1 && G->vertices[i].c == WHITE)
        {
            G->vertices[i].predecessor = vertex;
            recDFSVisit(G, i);
        }
    }
    G->vertices[vertex].c = BLACK;
    time = time + 1;
    G->vertices[vertex].finishing_time = time;
}

void recDFS(struct Graph *G)
{
    for (int i = 0; i < G->V; i++)
    {
        if (G->vertices[i].c == WHITE)
        {
            recDFSVisit(G, i);
        }
    }
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

// T4: NO EXPLICIT STACK USED AND DISCOVERY TIME AND FINISHING TIME MARKED

void add_edge_adj_matrix(Graph *G, int u, int v)
{
    G->adjacency_matrix[u][v] = 1;
}

int main()
{
    // You can change the file name to input1.txt or input2.txt to test your code for different graphs
    FILE *fp = fopen("CDCs.csv", "r");
    int V, E;
    fscanf(fp, "%d", &V); //NUMBER OF CDCs
    fscanf(fp, "%d", &E); //NUMBER OF PREREQUISITES

    struct Graph *G = get_graph(V, E);
    

    //INPUT VERTICES: SET THE DATA
    for(int i = 0; i<V; i++){
        CDC cdc;
        fscanf("%s,%[^\n]", cdc.code, cdc.name);
        G->vertices[i].data = cdc;
    }
    
    for (int i = 0; i < E; i++)
    {
        char prereq[100];
        char cdc[100];
        fscanf(fp, "%s,%s", &prereq, &cdc);
        add_edge_adj_matrix(G, prereq, cdc);
    }


    fclose(fp);

    //ASSUME WE PERFORMED SUCCESSFUL DFS
    dfs(G, 0);

    //HOW TO DO TOPOLOGICAL SORT? SORT BASED ON FINISHING TIME: LHIGHER TO LOWER PRINTED
    

    //QUICK SORT VERTICES ON FINISHING TIME
    quickSort_vertices(G->vertices, 0, G->V);


    return 0;
}