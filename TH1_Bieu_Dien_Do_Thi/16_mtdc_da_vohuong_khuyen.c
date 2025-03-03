#include <stdio.h>
#define MAX_N 100
#define MAX_M 500
typedef struct
{
    int n, m;
    int A[MAX_N][MAX_M];
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
// đa có hướng
void add_edge(Graph *pG, int e, int u, int v)
{
    pG->A[u][e] += 1;
    pG->A[v][e] += 1;
}
int main()
{
    Graph G;
    int n, m, u, v;
    // freopen("dothi.txt", "r", stdin);
    /*
    ue=1 neu lien thuoc, ue=2 neu la khuyen
    4 6
    1 2
    1 3
    1 3
    3 4
    1 4
    2 2
     */
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);

    for (int e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, e, u, v);
    }
    for (int u = 1; u <= G.n; u++)
    {
        for (int v = 1; v <= G.m; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    // 1 1 1 0 1 0
    // 1 0 0 0 0 2
    // 0 1 1 1 0 0
    // 0 0 0 1 1 0
}
