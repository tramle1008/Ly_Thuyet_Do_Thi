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
//đa đồ thị vô hướng có thể có khuyên
void add_edge(Graph *pG, int u, int v)
{
    if (u == v)
    {
        pG->A[u][v] += 1;
    }
    else
    {
        pG->A[u][v] += 1;
        pG->A[v][u] += 1;
    }

    pG->m++;
}
// Hết phần mã lệnh của bạn
int main()
{
    Graph G;
    int n, m, u, v;
    // Đọc số đỉnh và số cung và khởi tạo đồ thị n đỉnh 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (int u = 1; u <= G.n; u++)
    {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
}
