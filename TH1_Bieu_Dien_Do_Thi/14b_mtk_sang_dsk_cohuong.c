#include <stdio.h>
#define max_m 50
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
// thêm cung (u,v) vào đồ thị vô hướng *pG
void add_edge(Graph *pG, int u, int v)
{
    push_back(&pG->adj[u], v); // v là kề của u
}
void nhapMaTranKe(int n, int maTranKe[max_m][max_m])
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &maTranKe[i][j]);
        }
    }
}
void mtk_sang_dsk(Graph *pG, int matranke[max_m][max_m])
{
    for (int i = 1; i <= pG->n; i++)
    {
        for (int j = 1; j <= pG->n; j++)
        {
            for (int k = 1; k <= matranke[i][j]; k++)
            {
                add_edge(pG, i, j);
            }
        }
    }
}
int main()
{
    Graph G;
    int n;

    scanf("%d", &n);
    init_graph(&G, n);

    int matranke[max_m][max_m];
    nhapMaTranKe(n, matranke);
    mtk_sang_dsk(&G, matranke);
    for (int u = 1; u <= G.n; u++)
    {
        for (int v = 1; v <= max_m; v++)
            if (element_at(&G.adj[u], v) != 0)
                printf("%d ", element_at(&G.adj[u], v));
            else
            {
                printf("0");
                break;
            }
        printf("\n");
    }
    return 0;
}