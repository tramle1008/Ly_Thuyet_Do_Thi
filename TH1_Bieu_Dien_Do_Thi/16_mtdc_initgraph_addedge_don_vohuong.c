#include <stdio.h>
typedef struct
{
    int A[100][500];
    int n, m;
} Graph;
void init_graph(Graph *pG, int n, int m)
{
    int u, e;
    pG->n = n;
    pG->m = m;
    for (u = 1; u <= n; u++)
        for (e = 1; e <= m; e++)
            pG->A[u][e] = 0;
}
void add_edge(Graph *pG, int e, int u, int v)
{
    pG->A[u][e] = 1;
    pG->A[v][e] = 1;
}

int main()
{

    Graph G;
    int e, n, m, i;

    // freopen("dothi.txt", "r", stdin);
    // 4 4
    // 1 2
    // 1 3
    // 1 4
    // 3 4
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    int u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, e, u, v);
    }
    for (int i = 1; i <= G.n; i++)
    {
        for (int j = 1; j <= G.m; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
    // 1 1 1 0
    // 1 0 0 0
    // 0 1 0 1
    // 0 0 1 1
}