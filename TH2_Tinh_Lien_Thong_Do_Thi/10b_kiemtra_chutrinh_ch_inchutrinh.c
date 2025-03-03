// CTDL Graph
// kiem tra chu trinh co huong va in chu trinh
#include <stdio.h>
#define max_n 20
#define max_lenght 20
#define max_s 40

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

    G->A[x][y] += 1;
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
int adjacent(Graph *pG, int u, int v)
{
    return ((pG->A[u][v] == 1));
}
// ham tim lang gieng
List neighbors(Graph *G, int x)
{
    List L;
    make_null_list(&L);
    for (int i = 1; i <= G->n; i++)
    {
        if (G->A[x][i] == 1)
            push_back(&L, i);
    }
    return L;
}

// CTDL Stack
typedef struct
{
    int data[max_s];
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
/*Kiểm tra đồ thị chứa chu trình*/
#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[max_n];
int has_circle;
int parent[max_n], st = 0, en = 0;
void DFS(Graph *pG, int u, int p)
{
    color[u] = GRAY;

    for (int v = 1; v <= pG->n; v++)
    {

        if (adjacent(pG, u, v))
        {
            if (v == p)
                continue;
            if (color[v] == WHITE)
            {

                DFS(pG, v, u);
            }
            else if (color[v] == GRAY)
            {
                has_circle = 1;
                en = u;
                st = v;
            }
        }
    }
    parent[u] = p;
    color[u] = BLACK;
}
int main()
{
    Graph G;
    int m, n;
    freopen("DFS.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int e, u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_adge(&G, u, v);
    }

    for (u = 1; u <= G.n; u++)
    {
        color[u] = WHITE;
        parent[u] = -1;
    }

    has_circle = 0;

    for (u = 1; u <= G.n; u++)
    {
        if (color[u] == WHITE)
            DFS(&G, u, -1);
    }
    if (has_circle)
    {
        List lp;
        make_null_list(&lp);
        push_back(&lp, st);
        while (st != en)
        {
            push_back(&lp, en);
            en = parent[en];
        }
        push_back(&lp, st);

        for (int a = lp.size; a >= 1; a--)
        {
            printf("%d ", element_at(&lp, a));
        }
        // int v;
        // v = en;
        // printf("%d ", st);
        // while (v != st)
        // {
        //     printf("%d ", v);
        //     v = parent[v];
        // }
        // printf("%d\n", st);
    }
    else
        printf("-1");

    return 0;
}