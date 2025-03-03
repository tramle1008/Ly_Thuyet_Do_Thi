#include <stdio.h>
#define MAX_N 100
typedef struct
{
    int n, m;
    int W[MAXN][MAXN];
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
// đơn đồ thị vô hướng
// Viết mã lệnh của bạn ở đây
void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}
// Hết phần mã lệnh của bạn
