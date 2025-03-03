#include <stdio.h>

#define MAXN 100

typedef struct
{
    int C[MAXN][MAXN]; // Khả năng thông qua của các cung
    int F[MAXN][MAXN]; // Luồng khởi tạo của các cung
    int n;             // Số đỉnh
} Graph;

int check_valid_flow(Graph *pG, int s, int t)
{
    // Kiểm tra điều kiện 0 <= F[u][v] <= C[u][v] với mọi cung (u, v)
    for (int u = 1; u <= pG->n; u++)
    {
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->F[u][v] < 0 || pG->F[u][v] > pG->C[u][v])
            {
                return 0; // Điều kiện không hợp lệ
            }
        }
    }

    // Kiểm tra bảo toàn luồng tại các đỉnh
    int flow_out_s = 0, flow_in_t = 0;
    int flow_in[MAXN] = {0}, flow_out[MAXN] = {0};

    for (int u = 1; u <= pG->n; u++)
    {
        for (int v = 1; v <= pG->n; v++)
        {
            flow_out[u] += pG->F[u][v];
            flow_in[v] += pG->F[u][v];
        }
    }

    // Tổng luồng ra từ s
    flow_out_s = flow_out[s];
    // Tổng luồng vào t
    flow_in_t = flow_in[t];

    // Kiểm tra điều kiện bảo toàn luồng
    if (flow_out_s != flow_in_t)
    {
        return 0; // Không bảo toàn luồng tại s và t
    }

    // Kiểm tra các đỉnh trung gian
    for (int u = 1; u <= pG->n; u++)
    {
        if (u != s && u != t && flow_in[u] != flow_out[u])
        {
            return 0; // Không bảo toàn luồng tại đỉnh trung gian
        }
    }

    return 1; // Luồng hợp lệ
}

int main()
{
    Graph G;
    int m, u, v, c, f;
    freopen("dthl.txt", "r", stdin);
    // Đọc dữ liệu đầu vào
    scanf("%d %d", &G.n, &m);

    // Khởi tạo đồ thị và lưu khả năng thông qua, luồng khởi tạo
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &u, &v, &c, &f);
        G.C[u][v] = c;
        G.F[u][v] = f;
    }

    // Kiểm tra luồng khởi tạo hợp lệ từ đỉnh 1 đến đỉnh n
    if (check_valid_flow(&G, 1, G.n))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
