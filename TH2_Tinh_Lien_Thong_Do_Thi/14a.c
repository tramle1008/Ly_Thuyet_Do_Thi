// CTDL Graph
// phan chia doi bong thanh 2 nhom
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
void add_adge2(Graph *G, int x, int y)
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
void add_adge1(Graph *G, int x, int y)
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
// thuật toán Tarjan tìm các BPLT mạnh từ đỉnh u
// các biến hỗ trợ
int num[max_n], min_num[max_n];
int k;
Stack S;
int on_stack[max_n];
int kt;
int min(int x, int y)
{
    if (x > y)
        return y;
    else
        return x;
}
// duyệt đồ thị bắt đầu từ đỉnh u
void SCC(Graph *pG, int u)
{
    num[u] = min_num[u] = k;
    k++;
    push_stack(&S, u);
    on_stack[u] = 1;

    for (int v = 1; v <= pG->n; v++)
    {
        if (adjacent(pG, u, v))
        {
            if (num[v] < 0)
            {
                SCC(pG, v);
                min_num[u] = min(min_num[u], min_num[v]);
            }
            else if (on_stack[v])
                min_num[u] = min(min_num[u], num[v]);
        }
    }

    if (num[u] == min_num[u])
    {
        // printf("Tim duoc BPLT manh, %d la dinh khop.\n", u);
        kt++;
        // printf("%d\t", kt);
        int w;
        do
        {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
        } while (w != u);
    }
}
int main()
{
    Graph G;
    int m, n;
    //  freopen("DFS.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    int e, u, v, p;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d%d", &u, &v, &p);
        if (p == 1)
            add_adge1(&G, u, v);
        else
            add_adge2(&G, u, v);
    }
    for (u = 1; u <= G.n; u++)
        num[u] = -1;
    k = 1;
    make_null_stack(&S);
    kt = 0;
    for (u = 1; u <= G.n; u++)
        if (num[u] == -1)
            SCC(&G, u);
    if (kt == 1)
        printf("OKIE");
    else
        printf("NO");
}