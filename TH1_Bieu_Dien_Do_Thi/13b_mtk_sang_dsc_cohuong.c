#include <stdio.h>
#define max_m 50
typedef struct
{
    int u, v;
} Edge;
typedef struct
{
    int n, m;
    Edge edge[max_m];
} Graph;

// định nghĩa hàm init_graph
void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}
// Định nghĩa hàm add_edge
void add_edge(Graph *pG, int u, int v)
{
    pG->edge[pG->m].u = u;
    pG->edge[pG->m].v = v;
    pG->m++;
}
void nhapMaTranKe(int n, int maTranKe[max_m][max_m])
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &maTranKe[i][j]);
        }
    }
}
int main()
{
    Graph G;
    int n;

    scanf("%d", &n);
    init_graph(&G, n);

    int matranke[max_m][max_m];
    nhapMaTranKe(n, matranke);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= matranke[i][j]; k++)
            {
                add_edge(&G, i, j);
            }
        }
    }

    for (int e = 0; e < G.m; e++)
        printf("%d %d\n", G.edge[e].u, G.edge[e].v);
    return 0;
}