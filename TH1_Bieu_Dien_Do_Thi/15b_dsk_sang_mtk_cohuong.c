#include <stdio.h>
// danh sach ke
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
// đa đồ thị vô hướng có thể có khuyên
void add_edge(Graph *pG, int u, int v)
{
    // if (u == v)
    // {
    //     pG->A[u][v] += 1;
    // }
    // else
    // {
    //     pG->A[u][v] += 1;
    //     pG->A[v][u] += 1;
    // }
    pG->A[u][v] += 1;
    pG->m++;
}

int main()
{
    Graph G;
    int n, u, i, j, t;
    scanf("%d", &n);
    init_graph(&G, n);

    for (i = 1; i <= n; i++)
    {
        while (1)
        {
            scanf("%d", &u);
            if (u == 0)
                break;
            add_edge(&G, i, u);
        }
    }

    for (j = 1; j <= n; j++)
    {
        for (t = 1; t <= n; t++)
        {
            printf("%d ", G.A[j][t]);
        }
        printf("\n");
    }
}