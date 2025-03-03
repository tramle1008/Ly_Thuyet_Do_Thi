#include "stdio.h"
typedef struct
{
    int n;
    int A[100][100];
} Graph;
void init_graph(Graph *pG, int n)
{
    pG->n = n;
    for (int i = 0; i < pG->n; i++)
    {
        for (int j = 0; j < pG->n; j++)
        {
            pG->A[i][j] = 0;
        }
    }
}
void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
}
typedef struct
{
    int size;
    int data[100];
} List;
void make_null_list(List *L)
{
    L->size = 0;
}
void push_back(List *L, int u)
{
    L->data[L->size] = u;
    L->size++;
}
int element_at(List *L, int u)
{
    return (L->data[u - 1]);
}

typedef struct
{
    int data[100];
    int front;
    int rear;
} Queue;
void make_null_queue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}
void push_queue(Queue *q, int u)
{
    q->rear++;
    q->data[q->rear] = u;
}
int top(Queue *q)
{
    return (q->data[q->front]);
}
void pop(Queue *q)
{
    q->front++;
}
int empty_queue(Queue *q)
{
    return (q->front > q->rear);
}
void topo(Graph *pG, List *pL)
{
    int d[100], u, v;
    for (int u = 1; u <= pG->n; u++)
    {
        d[u] = 0;
        for (int x = 1; x <= pG->n; x++)
        {
            if (pG->A[x][u] != 0)
                d[u]++;
        }
    }
    Queue Q;
    make_null_queue(&Q);
    for (int u = 1; u <= pG->n; u++)
        if (d[u] == 0)
            push_queue(&Q, u);

    while ((!empty_queue(&Q)))
    {
        u = top(&Q);
        pop(&Q);
        push_back(pL, u);
        for (v = 1; v <= pG->n; v++)
        {
            if (pG->A[u][v] != 0)
            {
                d[v]--;
                if (d[v] == 0)
                    push_queue(&Q, v);
            }
        }
    }
}
int main()
{
    Graph G;
    int e, n, m;

    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    List l;
    topo(&G, &l);
    for (int i = 1; i <= l.size; i++)
    {
        printf("%d\n", element_at(&l, i));
    }
}