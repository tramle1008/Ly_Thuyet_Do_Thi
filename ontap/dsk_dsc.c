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
    if (u < 1 || v < 1 || u > pG->n || v > pG->n)
    {
        return;
    }
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

void print_edges(Graph *pG)
{
    for (int i = 0; i < pG->m; i++)
    {
        printf("(%d, %d)\n", pG->edges[i].u, pG->edges[i].v);
    }
}

int main()
{
    int n;
    freopen("dt.txt", "r", stdin);
    scanf("%d", &n); // Nhập số đỉnh

    Graph G;
    init_graph(&G, n); // Khởi tạo đồ thị với n đỉnh

    // Nhập danh sách kề
    for (int u = 1; u <= n; u++)
    {
        while (1)
        {
            int v;
            scanf("%d", &v);
            if (v == 0)
                break; // Kết thúc danh sách kề của đỉnh u
            add_edge(&G, u, v);
        }
    }

    // In ra danh sách cung
    print_edges(&G);

    return 0;
}
