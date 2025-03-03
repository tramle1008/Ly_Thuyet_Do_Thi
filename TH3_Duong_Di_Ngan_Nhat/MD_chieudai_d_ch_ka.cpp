#include <stdio.h>
#define MAXN 100
#define NO_EDGE -1
typedef struct
{
    int n;
    int W[MAXN][MAXN];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;

    int u, v;
    for (u = 1; u <= n; u++)
    {
        for (v = 1; v <= n; v++)
        {
            pG->W[u][v] = NO_EDGE;
        }
    }
}
void add_edge(Graph *pG, int u, int v, int w)
{
    pG->W[u][v] = w;
}
#define oo 999999

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void MooreDijkstra(Graph *pG, int s)
{
    int u, v, it;
    for (u = 1; u <= pG->n; u++)
    {
        pi[u] = oo;
        mark[u] = 0;
    }

    pi[s] = 0;
    p[s] = -1;

    for (it = 1; it < pG->n; it++)
    {
        int j, min_pi = oo;
        for (j = 1; j <= pG->n; j++)
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                u = j;
            }

        mark[u] = 1;

        for (v = 1; v <= pG->n; v++)
            if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
                if (pi[u] + pG->W[u][v] < pi[v])
                {
                    pi[v] = pi[u] + pG->W[u][v];
                    p[v] = u;
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
    MooreDijkstra(&G, 1);

    if (pi[n] != oo)
        printf("%d", pi[n]);
    else
        printf("-1");
    return 0;
}