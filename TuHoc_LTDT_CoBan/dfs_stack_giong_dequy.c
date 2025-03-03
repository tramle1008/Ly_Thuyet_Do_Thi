#include <stdio.h>
#define max_vertices 20
#define max_lenght 20
#define max_e 40

typedef struct
{
    int A[max_vertices][max_vertices];
    int n;
} Graph;
void init_graph(Graph *G, int n)
{
    int i, j;
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
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}
// kiem tra x,y co la lang gieng kh
int adjacent(Graph *G, int x, int y)
{
    return (G->A[x][y] != 0);
}
// bac cua dinh x
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->n; i++)
    {
        if (G->A[i][x] == 1)
            deg++;
    }
    return deg;
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
// ham tim lang gieng
List neighbors(Graph *G, int x)
{
    List L;
    make_null(&L);
    for (int i = 1; i <= G->n; i++)
    {
        if (G->A[i][x] == 1)
            push_back(&L, i);
    }
    return L;
}
// duyet theo chieu sau - THUAT TOAN DFS
// ngan sep
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
// thuat toan dfs
List dfs(Graph *G, int x)
{
    Stack S;
    make_null_stack(&S);
    push_stack(&S, x);
    List list_dfs;
    make_null(&list_dfs);
    int mark[max_vertices];
    // khoi tao tat ca cac dinh chua duoc duyet
    int i;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = 0;
    }
    while (!empty(&S))
    {
        int u = top(&S);
        pop(&S);
        if (mark[u] == 1)
        {
            continue;
        }
        // duyet
        push_back(&list_dfs, u);
        mark[u] = 1;
        List L = neighbors(G, u);
        // ta duyet trong so lon vao ngan xep truoc
        for (i = L.size; i >= 1; i--)
        {
            int v = element_at(&L, i);
            if (mark[v] == 0)
                push_stack(&S, v);
        }
    }
    return list_dfs;
}
int main()
{
    Graph G;
    int n, m;
    int i, j;
    freopen("dfs_dequy.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int e, u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_adge(&G, u, v);
    }
    int mark_dfs[max_vertices];
    for (i = 1; i <= G.n; i++)
    {
        mark_dfs[i] = 0;
    }
    for (i = 1; i <= G.n; i++)
    {
        if (mark_dfs[i] == 0)
        {
            List l_dfs = dfs(&G, i);
            for (j = 1; j <= l_dfs.size; j++)
            {
                int k = element_at(&l_dfs, j); // duyet dinh k
                printf("%d\n", k);
                mark_dfs[k] = 1; // danh dau da duyet dinh k
            }
        }
    }

    return 0;
}