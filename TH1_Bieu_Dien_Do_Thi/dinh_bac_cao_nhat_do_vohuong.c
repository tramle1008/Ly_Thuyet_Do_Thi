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
// đa đồ thị vô hướng có thể có khuyên
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
// bậc đồ thị
int degree(Graph *pG, int u)
{
    int v, deg_u = 0;
    for (v = 1; v <= pG->n; v++)
        deg_u += pG->A[u][v];
    // bậc chéo cộng hai lần
    return deg_u + pG->A[u][u];
}
int main()
{
    Graph G;
    int n, m, u, v, i, j;
    freopen("dothi.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    int a[MAX_N];
    for (i = 1; i <= G.n; i++)
    {
        a[i] = degree(&G, i);
    }
    int max = a[1], k = 1;
    for (j = 2; j <= G.n; j++)
    {
        if (a[j] > max)
        {
            max = a[j];
            k = j;
        }
    }
    printf("%d %d", k, max);
}