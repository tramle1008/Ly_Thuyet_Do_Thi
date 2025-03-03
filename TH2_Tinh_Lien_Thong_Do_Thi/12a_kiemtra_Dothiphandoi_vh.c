// CTDL Graph
// kiem tra do thi phan doi vo huong
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
int adjacent(Graph *pG, int u, int v)
{
    return ((pG->A[u][v] == 1) || (pG->A[v][u] == 1));
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
#define NO_COLOR 0
#define BLUE 1
#define RED 2
int color[max_n];
int conflict;
int mark[max_n];
void colorize(Graph *pG, int u, int c)
{
    // 1.Tô màu c cho u
    color[u] = c;
    mark[u] = 1;
    // 2.Xét các đỉnh kề của u
    for (int v = 1; v <= pG->n; v++)
    {
        if (adjacent(pG, u, v))
        {
            if (color[v] == NO_COLOR)
                colorize(pG, v, 3 - c);
            else if (color[v] == color[u])
                conflict = 1;
        }
    }
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

    for (u = 1; u <= G.n; u++)
    {
        color[u] = NO_COLOR;
        mark[u] = 0;
    }

    for (u = 1; u <= G.n; u++)
    {
        if (mark[u] == 0)
            colorize(&G, u, BLUE);
    }
    if (conflict)
        printf("NO");
    else
        printf("YES");
    return 0;
}