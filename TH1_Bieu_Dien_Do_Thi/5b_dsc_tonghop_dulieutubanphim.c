#include <stdio.h>
#define max_m 50
typedef struct
{
    int u, v;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[max_m];
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
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int degree(Graph *pG, int x)
{
    int e, deg = 0;
    for (e = 0; e < pG->m; e++)
    {
        if (pG->edges[e].u == x)
            deg++;
        if (pG->edges[e].v == x)
            deg++;
    }
    return deg;
}
int main()
{
    Graph G;
    int n, m, e, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    // In bậc của các đỉnh
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}