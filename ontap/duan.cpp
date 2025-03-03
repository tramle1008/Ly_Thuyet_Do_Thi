#include <stdio.h>
#define MAX 100
#define oo 999999
typedef struct
{
    int n;
    int A[MAX][MAX];
} Graph;

void init_graph(Graph *G, int n)
{
    int i;
    G->n = n;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            G->A[i][j] = 0;
    }
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
}

typedef struct
{
    int date[MAX];
    int size;
} List;
// khoi tao List rong
void make_null(List *list)
{
    list->size = 0;
}
// them vao mot phan tu
void push_back(List *list, int x)
{
    list->date[list->size] = x;
    list->size++;
}
// lay mot phan tu trong list tai di tri i
int element_at(List *list, int i)
{
    return (list->date[i - 1]);
}

typedef struct
{
    int data[MAX];
    int front; // chi so dau hang doi _ lay data
    int rear;  // chi so cuoi hang doi _ them data
} Queue;
// khoi tao hang doi rong
void make_null_queue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}
// them mot phan tu
void push_queue(Queue *q, int x)
{
    q->rear++;
    q->data[q->rear] = x;
}
// kiem tra hang doi co rong khong
int empty_queue(Queue *q)
{
    return (q->front > q->rear);
}
// lay mot phan tu o dau hang doi
int top_queue(Queue *q)
{
    return (q->data[q->front]);
}
void pop_queue(Queue *q)
{
    q->front++;
}
void topo(Graph *pG, List *L)
{
    int u, v, d[MAX];

    Queue Q;
    make_null_queue(&Q);
    for (u = 1; u <= pG->n; u++)
    {
        d[u] = 0;
    }
    for (u = 1; u <= pG->n; u++)
        for (v = 1; v <= pG->n; v++)
            if (pG->A[u][v] == 1)
                d[v]++;

    for (u = 1; u <= pG->n; u++)
        if (d[u] == 0)
            push_queue(&Q, u);

    while (!empty_queue(&Q))
    {
        u = top_queue(&Q);
        pop_queue(&Q);
        push_back(L, u);
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
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
int d[MAX];
int main()
{
    Graph G;
    int n, u, x, v, j;
    freopen("duan.txt", "r", stdin);
    scanf("%d", &n);
    init_graph(&G, n + 2);
    int alpha = n + 1, beta = n + 2;
    d[alpha] = 0;

    for (u = 1; u <= n; u++)
    {
        scanf("%d", &d[u]);
        do
        {
            scanf("%d", &x);
            if (x > 0)
                add_edge(&G, x, u);
        } while (x > 0);
    }

    for (u = 1; u <= n; u++)
    {
        int deg_neg = 0;
        for (x = 1; x <= n; x++)
        {
            if (G.A[x][u] > 0)
                deg_neg++;
        }

        if (deg_neg == 0)
            add_edge(&G, alpha, u);
    }

    for (u = 1; u <= n; u++)
    {
        int deg_pos = 0;
        for (v = 1; v <= n; v++)
        {
            if (G.A[u][v] > 0)
                deg_pos++;
        }
        if (deg_pos == 0)
            add_edge(&G, u, beta);
    }

    List L;
    topo(&G, &L);
    int t[MAX];
    t[alpha] = 0;
    for (j = 2; j <= L.size; j++)
    {
        int u = element_at(&L, j);
        t[u] = -oo;
        for (x = 1; x <= G.n; x++)
            if (G.A[x][u] > 0)
                t[u] = max(t[u], t[x] + d[x]);
    }
    int T[MAX];
    T[beta] = t[beta];

    for (j = L.size - 1; j >= 1; j--)
    {
        int u = element_at(&L, j);
        T[u] = +oo;
        for (v = 1; v <= G.n; v++)
            if (G.A[u][v] > 0)
                T[u] = min(T[u], T[v] - d[u]);
    }
    printf("%d\n", T[beta]);

    for (u = 1; u <= G.n; u++)
    {
        printf("%d-%d\n", t[u], T[u]);
    }
    return 0;
}