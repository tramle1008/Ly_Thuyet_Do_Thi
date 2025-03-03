// CTDL Graph
#include <stdio.h>
#define max_n 20
#define max_lenght 20
#define max_e 40

typedef struct
{
    int A[max_n][max_n];
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
    if (x == y)
    {
        G->A[x][y] += 1;
    }
    else
    {
        G->A[x][y] += 1;
        G->A[y][x] += 1;
    }
}

// CTDL List
typedef struct
{
    int date[max_lenght];
    int size;
} List;
// khoi tao List rong
void make_null_list(List *list)
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
// ham tim lang gieng
List neighbors(Graph *G, int x)
{
    List L;
    make_null_list(&L);
    for (int i = 1; i <= G->n; i++)
    {
        if (G->A[i][x] == 1)
            push_back(&L, i);
    }
    return L;
}

// CTDL Stack
typedef struct
{
    int data[max_e];
    int size;
} Stack;
void make_null_stack(Stack *s)
{
    s->size = 0;
}
void push_stack(Stack *s, int x)
{
    s->data[s->size] = x;
    s->size++;
}
int top(Stack *s)
{
    return (s->data[s->size - 1]);
}
void pop(Stack *s)
{
    s->size--;
}
int empty(Stack *s)
{
    return (s->size == 0);
}

// Thuat toan DFS
int mark[max_n];
void depth_first_search(Graph *G, int mark[])
{
    Stack S;
    make_null_stack(&S);
    push_stack(&S, 1);
    int i;

    while (!empty(&S))
    {
        int u = top(&S);
        pop(&S);
        if (mark[u] == 1)
            continue;
        mark[u] = 1;
        List list_nb = neighbors(G, u);
        for (i = 1; i <= list_nb.size; i++)
        {
            int v = element_at(&list_nb, i);
            if (mark[v] == 0)
                push_stack(&S, v);
        }
    }
}
int kiemtra(Graph *G, int mark[])
{
    for (int i = 1; i <= G->n; i++)
    {
        if (mark[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    Graph G;
    int m, n;
    //  freopen("DFS.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int e, u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_adge(&G, u, v);
    }
    int i;
    for (i = 1; i <= G.n; i++)
    {
        mark[i] = 0;
    }
    depth_first_search(&G, mark);
    if (kiemtra(&G, mark))
        printf("DUOC");
    else
        printf("KHONG");
    return 0;
}