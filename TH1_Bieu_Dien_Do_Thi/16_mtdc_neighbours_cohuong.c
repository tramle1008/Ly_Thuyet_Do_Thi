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
    if (u == v)
    {
        pG->A[u][e] += 2;
    }
    pG->A[u][e] += 1;
    pG->A[v][e] -= 1;
}
int adjacent(Graph *pG, int u, int v)
{
    int e;

    for (e = 1; e <= pG->m; e++)
    {
        if (u == v && (pG->A[u][e] == 2))
        {
            return 1;
        }
        else if ((pG->A[u][e] == 1) && (pG->A[v][e] == -1))
            return 1;
    }
    return 0;
}
void neighbours(Graph *pG, int u)
{
    int e;
    for (e = 1; e <= pG->n; e++)
    {
        if (adjacent(pG, u, e) == 1)
        {
            printf("%d ", e);
        }
    }
}
int main()
{
    Graph G;
    int n, m, u, v;
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
    for (int u = 1; u <= G.n; u++)
    {
        for (int v = 1; v <= G.m; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        printf("neighbours(%d) = ", i);
        neighbours(&G, i);
        printf("\n");
    }
}
