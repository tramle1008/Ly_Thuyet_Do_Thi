#include <stdio.h>
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
// Tạo danh sách rỗng
void make_null(List *pL)
{
    pL->size = 0;
}

// Thêm một phần tử vào cuối danh sách
void push_back(List *pL, ElementType x)
{
    pL->data[pL->size] = x;
    pL->size++;
}
// Lấy phần tử thứ i, phần tử bắt đầu có vị trí 1
ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}
// Trả về số phần tử của danh sách
int count_list(List *pL)
{
    return pL->size;
}

#define MAX_N 100
typedef struct
{
    int n;
    List adj[MAX_N];
} Graph;
// khởi tạo đồ thị có n đỉnh và 0 cung
void init_graph(Graph *pG, int n)
{
    int u;
    pG->n = n;
    for (u = 1; u <= n; u++)
        make_null(&pG->adj[u]);
}
// thêm cung (u,v) vào đồ thị có hướng *pG
void add_edge(Graph *pG, int u, int v)
{

    push_back(&pG->adj[u], v); // v là kề của u
    push_back(&pG->adj[v], u); // u là kề của v
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
        printf("adj[%d] = [ ", u);
        for (int v = 1; v <= G.n; v++)
            if (element_at(&G.adj[u], v) != 0)
                printf("%d ", element_at(&G.adj[u], v));
        printf("]\n");
    }
}