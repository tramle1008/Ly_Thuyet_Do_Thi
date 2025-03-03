#include <stdio.h>
#define MAXN 500
#define NO_EDGE -1
#define oo 999999

typedef struct
{
    int n;
    int W[MAXN][MAXN];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            pG->W[u][v] = NO_EDGE;
        }
    }
}

void add_edge(Graph *pG, int u, int v, int w)
{
    pG->W[u][v] = w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void MooreDijkstra(Graph *pG, int s)
{
    for (int u = 1; u <= pG->n; u++)
    {
        pi[u] = oo;
        mark[u] = 0;
    }
    pi[s] = 0;
    p[s] = -1;

    for (int it = 1; it < pG->n; it++)
    {
        int min_pi = oo, u;
        for (int j = 1; j <= pG->n; j++)
        {
            if (!mark[j] && pi[j] < min_pi)
            {
                min_pi = pi[j];
                u = j;
            }
        }

        mark[u] = 1;
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->W[u][v] != NO_EDGE && !mark[v])
            {
                if (pi[u] + pG->W[u][v] < pi[v])
                {
                    pi[v] = pi[u] + pG->W[u][v];
                    p[v] = u;
                }
            }
        }
    }
}

int main()
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    freopen("mcs.txt", "r", stdin);
    int row, col;
    scanf("%d %d", &row, &col);

    int matran[MAXN][MAXN];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matran[i][j]);
        }
    }

    // Tổng số đỉnh trong đồ thị (mỗi ô là một đỉnh)
    Graph G;
    init_graph(&G, row * col);

    // Tạo các cạnh dựa trên ma trận số
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int u = i * col + j + 1;

            // Cạnh tới ô bên phải
            if (j + 1 < col)
            {
                int v = i * col + (j + 1) + 1;
                add_edge(&G, u, v, matran[i][j + 1]);
                add_edge(&G, v, u, matran[i][j]); // Thêm cạnh ngược chiều
            }

            // Cạnh tới ô bên dưới
            if (i + 1 < row)
            {
                int v = (i + 1) * col + j + 1;
                add_edge(&G, u, v, matran[i + 1][j]);
                add_edge(&G, v, u, matran[i][j]); // Thêm cạnh ngược chiều
            }
        }
    }

    // Áp dụng thuật toán Moore-Dijkstra từ đỉnh 1 (tương ứng với ô (0,0))
    MooreDijkstra(&G, 1);

    // Đỉnh cuối cùng là ô (row-1, col-1) tương ứng với đỉnh row*col
    int destination = row * col;
    printf("%d", pi[destination]);

    return 0;
}
