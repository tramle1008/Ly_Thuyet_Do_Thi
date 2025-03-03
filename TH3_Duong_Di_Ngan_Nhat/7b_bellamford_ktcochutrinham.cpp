#include <stdio.h>
#define M 100
typedef struct
{
    int u, v;
    int w;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[M];
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

#define oo 999999

int pi[M];
int p[M];
void BellamFord(Graph *pG, int s)
{
    int u, v, w, it, k;
    for (u = 1; u <= pG->n; u++)
        pi[u] = oo;
    pi[s] = 0;
    p[s] = -1;

    for (it = 1; it < pG->n; it++)
    {
        for (k = 0; k < pG->m; k++)
        {
            u = pG->edges[k].u;
            v = pG->edges[k].v;
            w = pG->edges[k].w;
            if (pi[u] == oo)
                continue;
            if (pi[u] + w < pi[v])
            {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}
int main()
{
    freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.

    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    BellamFord(&G, 1);
    int negative = 0;
    for (int k = 0; k < G.m; k++)
    {
        u = G.edges[k].u;
        v = G.edges[k].v;
        w = G.edges[k].w;

        if (pi[u] + w < pi[v])
        {
            negative = 1;
            break;
        }
    }
    if (!negative)
        printf("ok");
    else
        printf("negative cycle");
    return 0;
}
