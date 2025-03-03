// CTDL Graph
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
void push_list(List *list, int x)
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
        if (G->A[x][i] == 1)
            push_list(&L, i);
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
int mark[max_vertices];
List depth_first_search(Graph *G, int x, int mark[])
{
    Stack S;
    make_null_stack(&S);
    push_stack(&S, x);
    List ldfs;
    make_null_list(&ldfs);
    int i;
    while (!empty(&S))
    {
        int u = top(&S);
        pop(&S);
        if (mark[u] == 1)
            continue;
        // printf("Duyet %d\n", u);
        push_list(&ldfs, u);
        mark[u] = 1;
        List list_nb = neighbors(G, u);
        for (i = list_nb.size; i >= 1; i--)
        {
            int v = element_at(&list_nb, i);
            if (mark[v] == 0)
            {
                push_stack(&S, v);
            }
        }
    }
    return ldfs;
}

int main()
{
    Graph G;
    int m, n;
    // freopen("DFS.txt", "r", stdin);
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
    for (u = 1; u <= n; u++)
    {
        if (mark[u] == 0)
        {
            // kiem tra dinh duyet chua
            List L = depth_first_search(&G, u, mark);
            for (i = 1; i <= L.size; i++)
            {
                v = element_at(&L, i);
                printf("%d\n", v);
                mark[v] = 1; // danh dau da duyet
            }
        }
    }
    return 0;
}