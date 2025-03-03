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

int pi[MAXN][MAXN];
int next[MAXN][MAXN];

void floyWarshall(Graph *pG)
{
    int u, v, k;
    for (u = 1; u <= pG->n; u++)
    {
        for (v = 1; v <= pG->n; v++)
        {
            pi[u][v] = oo;
            next[u][v] = -1;
        }
    }

    for (u = 1; u <= pG->n; u++)
    {
        pi[u][u] = 0;
    }

    for (u = 1; u <= pG->n; u++)
        for (v = 1; v <= pG->n; v++)
            if (pG->W[u][v] != NO_EDGE)
            {
                pi[u][v] = pG->W[u][v];
                next[u][v] = v;
            }
    for (k = 1; k <= pG->n; k++)
    {
        for (u = 1; u <= pG->n; u++)
            for (v = 1; v <= pG->n; v++)
                if (pi[u][k] + pi[k][v] < pi[u][v])
                {

                    pi[u][v] = pi[u][k] + pi[k][v];
                    next[u][v] = next[u][k];
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
    floyWarshall(&G);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pi[i][j] < 1000)
                printf("%d -> %d: %d\n", i, j, pi[i][j]);
            else
                printf("%d -> %d: NO PATH\n", i, j);
        }
    }
}