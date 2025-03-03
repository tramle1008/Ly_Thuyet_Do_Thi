#include <stdio.h>
#define max_vertices 20
#define max_lenght 20
#define max_element 40
typedef struct
{
    int A[max_vertices][max_vertices];
    int n;
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

// them cung vao do thi
void add_adge(Graph *G, int x, int y)
{
    G->A[x][y] += 1;
}

// khai bao cau truc danh sach List
typedef struct
{
    int date[max_lenght];
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
List neighbors(Graph *G, int x)
{
    List L;
    make_null(&L);
    for (int i = 1; i <= G->n; i++)
    {
        if (G->A[x][i] == 1)
            push_back(&L, i);
    }
    return L;
}
// khai bao hang doi
typedef struct
{
    int data[max_element];
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
// ham duyet theo chieu sau

List bfs(Graph *G, int x, int mark[], int parent[])
{
    Queue Q;
    make_null_queue(&Q);
    push_queue(&Q, x);
    //  parent[x] = -1;
    List L_bfs;
    make_null(&L_bfs);
    while (!empty_queue(&Q))
    {
        int u = top_queue(&Q);
        pop_queue(&Q);
        if (mark[u] == 1)
            continue;
        push_back(&L_bfs, u);
        mark[u] = 1;
        List list;
        make_null(&list);
        list = neighbors(G, u);
        int i;
        for (i = 1; i <= list.size; i++)
        {
            int v = element_at(&list, i);
            if (mark[v] == 0)
            {
                push_queue(&Q, v);
                if (parent[v] == -1)
                    parent[v] = u;
            }
        }
    }
    return L_bfs;
}
int main()
{

    Graph G;
    int e, n, m;
    freopen("DFS.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_adge(&G, u, v);
    }
    int i;
    int mark_bfs[max_vertices], parent[max_vertices];
    for (int t = 1; t <= G.n; t++)
    {
        mark_bfs[t] = 0;
        parent[t] = -1;
    }
    for (u = 1; u <= G.n; u++)
    {
        if (mark_bfs[u] == 0)
        {
            List L = bfs(&G, u, mark_bfs, parent);
            for (i = 1; i <= L.size; i++)
            {
                v = element_at(&L, i);
                mark_bfs[v] = 1;
                printf("%d %d\n", v, parent[v]);
            }
        }
    }
    // for (v = 1; v <= n; v++)
    // {
    // }
    return 0;
}