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

int degree(Graph *pG, int x)
{
    int e, deg = 0;
    for (e = 0; e < pG->m; e++)
    {
        if (pG->edge[e].u == x)
            deg++;
        if (pG->edge[e].v == x)
            deg++;
    }
    return deg;
}
// Kiểm tra 2 đỉnh có kề nhau không - vô hướng
int adjacent(Graph *pG, int u, int v)
{
    int e;
    for (e = 0; e < pG->m; e++)
        if ((pG->edge[e].u == u && pG->edge[e].v == v) || (pG->edge[e].u == v && pG->edge[e].v == u))
            return 1;
    return 0;
}
// Liệt kê các đỉnh kề với đỉnh u
void neighbours(Graph *pG, int u)
{
    int v;
    for (v = 0; v <= pG->n; v++)
    {
        if (adjacent(pG, v, u) != 0)
            printf("%d ", v);
    }
}
int main()
{
    Graph G;
    int n, m, e, u, v, i;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (i = 1; i <= n; i++)
    {
        printf("neighbours(%d) = ", i);
        neighbours(&G, i);
        printf("\n");
    }
    return 0;
}