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