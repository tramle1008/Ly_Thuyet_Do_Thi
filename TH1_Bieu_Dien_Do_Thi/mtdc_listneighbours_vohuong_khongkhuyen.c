#include <stdio.h>
typedef struct
{
    int A[100][500];
    int n, m;
} Graph;
void init_graph(Graph *pG, int n, int m)
{
    int u, e;
    pG->n = n;
    pG->m = m;
    for (u = 1; u <= n; u++)
        for (e = 1; e <= m; e++)
            pG->A[u][e] = 0;
}
void add_edge(Graph *pG, int e, int u, int v)
{
    pG->A[u][e] = 1;
    pG->A[v][e] = 1;
}

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

/* Tạo danh sach rỗng */
void make_null(List *L)
{
    L->size = 0;
}

/* Thêm một phần tử vào cuối danh sách */
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}

/* Lấy phần tử tại vị trí i, vị trí tính từ 1 */
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}

/* Trả về số phần tử của danh sách */
int count_list(List *L)
{
    return L->size;
}
int adjacent(Graph *pG, int u, int v)
{
    int e;

    for (e = 1; e <= pG->m; e++)
    {
        if (u == v)
        {
            if (pG->A[u][e] == 2)
                return 1;
            else
                return 0;
        }
        if ((pG->A[u][e] == 1) && (pG->A[v][e] == 1))
            return 1;
    }
    return 0;
}
List neighbors(Graph *pG, int u)
{

    int i, e;
    List L;
    make_null(&L);
    for (i = 1; i <= pG->n; i++)
        for (e = 1; e <= pG->m; e++)
            if (pG->A[u][e] > 0 && pG->A[i][e] > 0 && u != i)
            {
                push_back(&L, i);
                break;
            }
    return L;
}

int main()
{

    Graph G;
    int e, n, m, i;

    freopen("dothi.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    int u, v;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, e, u, v);
    }
    for (i = 1; i <= G.n; i++)
    {
        List list = neighbors(&G, i);
        printf("Neighbours %d = [ ", i);
        for (int j = 1; j <= list.size; j++)
        {
            printf("%d ", element_at(&list, j));
        }
        printf("]\n");
    }
}