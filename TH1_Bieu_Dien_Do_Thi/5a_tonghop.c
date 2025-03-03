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
    int n = 4, u;

    // Khởi tạo đồ thị
    init_graph(&G, n);
    // Thêm cung vào đồ thị
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 1, 4);

    // In bậc của các đỉnh
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}
