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

int Prim(Graph *pG, Graph *pT, int s)
{
    int u, v, i, x;
    for (u = 1; u <= pG->n; u++)
    {
        pi[u] = oo;
        mark[u] = 0;
        p[u] = -1;
    }

    pi[s] = 0;

    for (i = 1; i < pG->n; i++)
    {
        int min_pi = oo;
        for (x = 1; x <= pG->n; x++)
            if (mark[x] == 0 && pi[x] < min_pi)
            {
                min_pi = pi[x];
                u = x;
            }

        mark[u] = 1;

        for (v = 1; v <= pG->n; v++)
            if (pG->W[u][v] != NO_EDGE)
                if (pG->W[u][v] < pi[v] && mark[v] == 0)
                {
                    pi[v] = pG->W[u][v];
                    p[v] = u;
                }
    }
    init_graph(pT, pG->n);
    int sum = 0;
    for (u = 1; u <= pG->n; u++)
    {
        if (p[u] != -1)
        {
            int w = pG->W[p[u]][u];
            add_edge(pT, p[u], u, w);
            sum += w;
        }
    }
    return sum;
}

int main()
{
    freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G, T;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int t = Prim(&G, &T, 1);

    printf("%d\n", t);
    u = 1;
    for (u = 1; u <= T.n; u++)
    {
        for (v = u + 1; v <= T.n; v++)
        {
            if (T.W[u][v] != NO_EDGE)
                printf("%d %d %d\n", u, v, T.W[u][v]);
        }
    }
    return 0;
}