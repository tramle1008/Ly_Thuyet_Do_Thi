#include <stdio.h>
#define MAX 100

typedef struct
{
    int n;           // Số đỉnh
    int A[MAX][MAX]; // Ma trận kề
} Graph;

// Hàm khởi tạo đồ thị
void init_graph(Graph *G, int n)
{
    G->n = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            G->A[i][j] = 0; // Ban đầu chưa có cạnh nào
        }
    }
}

// Hàm thêm cạnh vào đồ thị
void add_edge(Graph *G, int u, int v)
{
    G->A[v][u] = 1; // Cạnh từ u đến v
}

typedef struct
{
    int data[MAX];
    int size;
} List;

// Hàm khởi tạo danh sách rỗng
void make_null(List *list)
{
    list->size = 0;
}

// Hàm thêm phần tử vào danh sách
void push_back(List *list, int x)
{
    list->data[list->size] = x;
    list->size++;
}

// Hàm lấy phần tử ở vị trí thứ i trong danh sách (chỉ số bắt đầu từ 1)
int element_at(List *list, int i)
{
    return list->data[i - 1];
}

// Hàm sao chép danh sách
void copy_list(List *dest, List *src)
{
    make_null(dest);
    for (int i = 1; i <= src->size; i++)
    {
        push_back(dest, element_at(src, i));
    }
}

int r[MAX]; // Mảng lưu thứ hạng các đỉnh

// Hàm tính hạng các đỉnh
void rank(Graph *G)
{
    int d[MAX]; // Mảng lưu bậc vào của các đỉnh
    for (int u = 1; u <= G->n; u++)
    {
        d[u] = 0;
        for (int v = 1; v <= G->n; v++)
        {
            if (G->A[v][u] == 1)
            {
                d[u]++;
            }
        }
    }

    List S1, S2; // Hai danh sách để thực hiện quá trình xếp hạng
    make_null(&S1);

    // Đưa các đỉnh có bậc vào bằng 0 vào danh sách S1
    for (int u = 1; u <= G->n; u++)
    {
        if (d[u] == 0)
        {
            push_back(&S1, u);
        }
    }

    int k = 0; // Biến lưu thứ hạng hiện tại
    while (S1.size > 0)
    {
        make_null(&S2);
        for (int i = 1; i <= S1.size; i++)
        {
            int u = element_at(&S1, i);
            r[u] = k; // Gán thứ hạng cho đỉnh u

            // Giảm bậc vào của các đỉnh kề với u
            for (int v = 1; v <= G->n; v++)
            {
                if (G->A[u][v] == 1)
                {
                    d[v]--;
                    if (d[v] == 0)
                    {
                        push_back(&S2, v);
                    }
                }
            }
        }
        copy_list(&S1, &S2); // S1 sẽ chứa các đỉnh của S2 để xét tiếp
        k++;                 // Tăng thứ hạng cho vòng tiếp theo
    }
}

int main()
{
    Graph G;
    int n, m;
    freopen("dt.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v); // Thêm cạnh u -> v
    }

    // Tính hạng các đỉnh
    rank(&G);
    int t = 0;
    // In hạng của các đỉnh
    for (int u = 1; u <= G.n; u++)
    {

        printf("%d\n", r[u] + 1);
        t += r[u] + 1;
    }
    printf("%d", t);
    return 0;
}
