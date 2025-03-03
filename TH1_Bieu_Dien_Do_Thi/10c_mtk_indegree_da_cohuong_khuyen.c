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
// đa đồ thị có hướng có thể có khuyên
void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v] += 1;
    pG->m++;
}
// bậc vào của đỉnh u
int indegree(Graph *pG, int u)
{
    int v, deg_u = 0;
    for (v = 1; v <= pG->n; v++)
        deg_u += pG->A[v][u];
    return deg_u;
}
int main()
{
    Graph G;
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (int i = 1; i <= G.n; i++)
    {
        printf("indegree(%d) = %d\n", i, indegree(&G, i));
    }
}