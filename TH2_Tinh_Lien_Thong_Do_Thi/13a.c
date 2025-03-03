// Duyet theo chieu sau + danh so cac dinh => BPLT manh cua do thi CO HUONG
#include <stdio.h>
#define MAX_N 20

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *G, int k)
{
    G->n = k;
    G->m = 0;
    int u, v;
    for (u = 1; u <= G->n; u++)
    {
        for (v = 1; v <= G->n; v++)
        {
            G->A[u][v] = 0;
        }
    }
}

// DO THI CO HUONG
void add_edge(Graph *G, int u, int v)
{
    if (u < 1 || u > G->n || v < 1 || v > G->n)
        return;
    G->A[u][v]++;
    G->m++;
}

int adjacent(Graph *G, int u, int v)
{
    return (G->A[u][v] > 0);
}

typedef struct
{
    int data[MAX_N];
    int top_idx;
} Stack;

void make_null_stack(Stack *S)
{
    S->top_idx = -1;
}

int empty(Stack *S)
{
    return (S->top_idx == -1);
}

void push(Stack *S, int u)
{
    S->top_idx++;
    S->data[S->top_idx] = u;
}

int top(Stack *S)
{
    return (S->data[S->top_idx]);
}

void pop(Stack *S)
{
    S->top_idx--;
}

int num[MAX_N], min_num[MAX_N];
int k;
Stack S;
int on_stack[MAX_N];

int min(int a, int b)
{
    return a < b ? a : b;
}

// Duyet do thi tu dinh u
void SCC(Graph *G, int u)
{
    // Danh so u, dua u vao ngan xep S
    num[u] = min_num[u] = k;
    k++;
    push(&S, u);
    on_stack[u] = 1;

    // Xet cac dinh ke cua u
    int v;
    for (v = 1; v <= G->n; v++)
    {
        if (adjacent(G, u, v))
        {
            if (num[v] < 0)
            {
                SCC(G, v);
                min_num[u] = min(min_num[u], min_num[v]);
            }
            else if (on_stack[v])
                min_num[u] = min(min_num[u], num[v]);
        }
    }

    // Kiem tra u co phai la dinh khop ko?
    if (num[u] == min_num[u])
    {
        printf("\n");
        // printf("Tim duoc BPLT manh, %d la dinh khop.\n", u);
        int w;
        do
        { // Lay cac dinh trong S ra cho den khi gap u
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
            printf("Lay %d", w);
        } while (w != u);
    }
}

// Dung thuat toan Tarjan de duyet toan bo do thi
int main()
{
    Graph G;
    int n, m, e, u, v;
    freopen("DFS.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (u = 1; u <= G.n; u++)
    { // Tat ca deu chua duyet
        num[u] = -1;
        // on_stack[i] = 0;
    }

    k = 1; // Tat ca deu chua duyet
    make_null_stack(&S);

    // Duyet toan bo do thi tim BPLT manh
    for (u = 1; u <= G.n; u++)
    {
        if (num[u] == -1)
        {               // u chua duyet
            SCC(&G, u); // duyet u
        }
    }
    // for (u = 1; u <= n; u++)
    //     printf("%d %d\n", num[u], min_num[u]); // hien thi cac gia tri num[] va min_num[] tung dinh

    return 0;
}