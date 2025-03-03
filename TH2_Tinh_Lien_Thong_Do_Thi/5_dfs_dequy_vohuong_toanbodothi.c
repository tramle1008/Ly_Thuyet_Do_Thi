#include <stdio.h>
#define max_vertices 20
#define max_lenght 20
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
        if (G->A[i][x] == 1)
            push_back(&L, i);
    }
    return L;
}

// duyet dfs bang de quy
int mark[max_vertices];
void dfs_dequy(Graph *G, int u)
{
    if (mark[u] == 1)
        return;
    printf("%d\n", u);
    mark[u] = 1;
    List list = neighbors(G, u);
    int i;
    for (i = 1; i <= list.size; i++)
    {
        int v = element_at(&list, i);
        dfs_dequy(G, v);
    }
}
int main()
{
    Graph G;
    int n, m;

    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    int u, v, i;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_adge(&G, u, v);
    }
    for (i = 1; i <= n; i++)
    {
        mark[i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
            dfs_dequy(&G, i);
    }

    return 0;
}