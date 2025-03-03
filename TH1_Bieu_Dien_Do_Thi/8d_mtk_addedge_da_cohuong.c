#include <stdio.h>
#define MAX_N 100
typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;
// Viết mã lệnh của bạn ở đây
void init_graph(Graph *pG, int n)
{
    int u, v;
    pG->n = n;
    pG->m = 0;
    for (u = 1; u <= n; u++)
        for (v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}
//đa có hướng

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v] += 1;
    pG->m++;
}
// Hết phần mã lệnh của bạn
