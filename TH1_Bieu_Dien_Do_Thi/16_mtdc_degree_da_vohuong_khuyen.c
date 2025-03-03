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
// đa vô hướng
void add_edge(Graph *pG, int e, int u, int v)
{
    pG->A[u][e] += 1;
    pG->A[v][e] += 1;
}
int degree(Graph *pG, int u)
{
    int e, deg = 0;
    for (e = 1; e <= pG->m; e++)
    {
        if (pG->A[u][e] > 0)
        {
            deg += 1;
        }
    }
    return deg;
}
int main()
{
    Graph G;
    int n, m, u, v, i;
    // freopen("dothi.txt", "r", stdin);
    /*
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
    for (i = 1; i <= G.n; i++)
    {
        printf("degree(%d) = %d\n", i, degree(&G, i));
    }
}