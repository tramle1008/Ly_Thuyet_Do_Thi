#include <stdio.h>
#define MAX_M 500
typedef struct
{
    int u, v;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[MAX_M];
} Graph;
void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    int i;
    for (i = 0; i < pG->m; i++)
        if ((pG->edges[i].u == u && pG->edges[i].v == v) || (pG->edges[i].u) == v && pG->edges[i].v == u)
        {
            return;
        }
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

/*Viết mã lệnh của bạn*/
int adjacent(Graph *pG, int u, int v)
{
    int e;
    for (e = 0; e < pG->m; e++)
        if ((pG->edges[e].u == u && pG->edges[e].v == v) || (pG->edges[e].u == v && pG->edges[e].v == u))
            return 1;
    return 0;
}
/*Hết phần mã lệnh của bạn*/
int main()
{
    Graph G;
    init_graph(&G, 3);
add_edge(&G, 1, 3);
add_edge(&G, 2, 3);
add_edge(&G, 2, 2);

    printf("n = %d , m = %d\n", G.n, G.m);

    int t = adjacent(&G, 3, 3);
    printf("%d", t);
    return 0;
}
