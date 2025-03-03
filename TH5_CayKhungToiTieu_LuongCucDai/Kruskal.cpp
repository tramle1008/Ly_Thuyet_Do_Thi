#include <stdio.h>
#define MAX 100
typedef struct
{
    int u, v;
    int w;
} Edge;
typedef struct
{
    int m, n;
    Edge edges[MAX];
} Graph;
void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}
void add_edge(Graph *pG, int u, int v, int w)
{
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].w = w;
    pG->m++;
}
int parent[20];
int findRoot(int u)
{
    while (parent[u] != u)
        u = parent[u];
    return u;
}

int Kruskal(Graph *pG, Graph *pT)
{
    int j, i, e, sum = 0;
    for (i = 0; i < pG->m; i++)
        for (j = i + 1; j < pG->m; j++)
            if (pG->edges[i].w > pG->edges[j].w)
            {
                Edge temp = pG->edges[i];
                pG->edges[i] = pG->edges[j];
                pG->edges[j] = temp;
            }

    init_graph(pT, pG->n);
    for (int u = 1; u <= pG->n; u++)
        parent[u] = u;

    for (e = 0; e < pG->m; e++)
    {
        int u = pG->edges[e].u;
        int v = pG->edges[e].v;
        int w = pG->edges[e].w;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u != root_v)
        {
            add_edge(pT, u, v, w);
            parent[root_v] = root_u;
            sum += w;
        }
    }
    return sum;
}
int main()
{
    Graph G, T;
    int n, m, u, v, w, e;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int s = Kruskal(&G, &T);
    printf("%d\n", s);
    for (e = 0; e < T.m; e++)
    {
        if (T.edges[e].u > T.edges[e].v)
            printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
        else
            printf("%d %d %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
    }
}