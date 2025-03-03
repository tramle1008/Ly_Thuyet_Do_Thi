#include <stdio.h>
#define MAX_N 100
typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n)
{
    int u, v;
    pG->n = n;
    pG->m = 0;
    for (u = 1; u <= n; u++)
        for (v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    if (u == v)
    {
        pG->A[u][v] += 1;
    }
    else
    {
        pG->A[u][v] += 1;
        pG->A[v][u] += 1;
    }

    pG->m++;
}
void neighbours(Graph *pG, int u)
{
    int v, j;
    for (v = 1; v <= pG->n; v++)
        for (j = 1; j <= pG->A[u][v]; j++)
        {
            printf("%d ", v);
        }
    printf("\n");
}

int main()
{
    Graph G;
    int n, m, u, v, e, i;
    // Đọc số đỉnh và số cung và khởi tạo đồ thị n đỉnh 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (i = 1; i <= G.n; i++)
    {
        printf("neighbours(%d) = ", i);
        neighbours(&G, i);
    }
}
