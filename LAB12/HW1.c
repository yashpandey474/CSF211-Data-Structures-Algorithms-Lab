//USING BOTH REPRESENTATIONS OF GRAPH;
//CALCULATE IN-DEGREE AND OUT-DEGREE OF ALL THE NODES (VERTICES)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list_node
{
    int data;
    struct linked_list_node *next;
} ll_node;

struct Graph
{
    int V;
    int E;
    int **adjacency_matrix;
    ll_node **adjacency_list;
};

struct Graph *get_graph(int V, int E)
{
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    G->V = V;
    G->E = E;
    // Allocate memory for the adjacency matrix (V x V int array)
    G->adjacency_matrix = (int **)malloc(sizeof(int *) * G->V);

    // Allocate memory for each row of the adjacency matrix
    for (int i = 0; i < V; i++)
    {
        G->adjacency_matrix[i] = (int *)malloc(sizeof(int *) * G->V);

        // Initialize the allocated row to 0 (Do not visit all elements. Use the <string.h> function bzero or memset)
        memset(G->adjacency_matrix[i], 0, sizeof(int) * G->V);
    }

    // Allocate memory for the adjacency list  (V linked lists of type ll_node)
    G->adjacency_list = (ll_node **)malloc(sizeof(ll_node *) * V);

    for (int i = 0; i < V; i++)
    {
        G->adjacency_list[i] = NULL;
    }
    // Initialize all the linked lists to NULL (Will bzero or memset work here? Why or why not?)

    return G;
}

void add_edge_adj_matrix(struct Graph *G, int u, int v)
{
    // IN THE UTH ARRAY; CHANGE THE VTH ENTRY
    G->adjacency_matrix[u][v] = 1;
    // Add an edge from u to v in the adjacency matrix
}

void add_edge_adj_list(struct Graph *G, int u, int v)
{
    ll_node *node = (ll_node *)malloc(sizeof(ll_node));

    node->data = v;
    node->next = G->adjacency_list[u];
    G->adjacency_list[u] = node;
    // Add an edge from u to v in the adjacency list. Use the ll_node structure defined above
}


//HW1: CALCULATE OUT DEGREE OF A VERTEX
int calculateOutDegreeMatrix(struct Graph* G, int v){
    //GO TO UTH ROW AND CHECK 1S
    int count = 0;
    for(int i = 0; i<G->V; i++){
        if(G->adjacency_matrix[v][i] == 1){
            count++;
        }
    }
    return count;
}

int calculateOutDegreeList(struct Graph* G, int v){
    //COUNT NON-NULL ENTRIES IN UTH LIST
    int count = 0;

    ll_node* current = G->adjacency_list[v];
    while(current != NULL){
        count++;
        current = current->next;
    }
    
    return count;
}


//HW1: CALCULATE IN DEGREE OF A VERTEX
int calculateInDegreeMatrix(struct Graph* G, int v){
    int count = 0;
    for(int i = 0; i<G->V; i++){
        if(G->adjacency_matrix[i][v] == 1){
            count++;
        }
    }
    return count;
}

int calculateInDegreeList(struct Graph* G, int v){
    int count = 0;
    ll_node* current = NULL;
    for(int i = 0; i<G->V; i++){
        current = G->adjacency_list[i];

        while(current!=NULL){
            if(current->data == v){
                count++;
                break;
            }
            current = current->next;
        }
    }
    return count;
}


//HW1: VERIFY SUM(INDEGREE) = SUM(OUTDEGREE)
void printSumDegrees(struct Graph* G){
    int sum_in_degree = 0;
    int sum_out_degree = 0;

    for(int i = 0; i<G->V; i++){
        sum_in_degree += calculateInDegreeList(G, i);
        sum_out_degree += calculateOutDegreeList(G,i);
    }
    printf("SUM OF IN DEGREE = %d\n SUM OF OUT DEGREE = %d\n", sum_in_degree, sum_out_degree);
}

void print_adj_matrix(struct Graph *G)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < G->V; i++)
    {
        for (int j = 0; j < G->V; j++)
        {
            printf("%d ", G->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void print_adj_list(struct Graph *G)
{
    printf("Adjacency List:\n");
    for (int i = 0; i < G->V; i++)
    {
        printf("%d: ", i);
        ll_node *temp = G->adjacency_list[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    // You can change the file name to input1.txt or input2.txt to test your code for different graphs
    FILE *fp = fopen("input0.txt", "r");
    int V, E;
    fscanf(fp, "%d", &V);
    fscanf(fp, "%d", &E);
    struct Graph *G = get_graph(V, E);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        add_edge_adj_matrix(G, u, v);
        add_edge_adj_list(G, u, v);
    }
    print_adj_matrix(G);
    print_adj_list(G);

    printSumDegrees(G);
    return 0;
}