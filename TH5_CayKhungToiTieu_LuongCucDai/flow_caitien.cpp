#include <stdio.h>
#define MAXN 100
#define NO_EDGE -1
#define oo 999999
typedef struct
{
    int C[MAXN][MAXN];
    int F[MAXN][MAXN];
    int n;
} Graph;
typedef struct
{
    int dir;
    int p;
    int sigma;
} Label;

Label label[MAXN];
void init_graph(Graph *pG, int n)
{
    pG->n = n;
    for (int u = 1; u <= pG->n; u++)
    {
        for (int v = 1; v <= pG->n; v++)
        {
            pG->F[u][v] = 0;
        }
    }
}
// khai bao hang doi
typedef struct
{
    int data[MAXN];
    int front; // chi so dau hang doi _ lay data
    int rear;  // chi so cuoi hang doi _ them data
} Queue;
// khoi tao hang doi rong
void make_null_queue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}
// them mot phan tu
void push_queue(Queue *q, int x)
{
    q->rear++;
    q->data[q->rear] = x;
}
// kiem tra hang doi co rong khong
int empty_queue(Queue *q)
{
    return (q->front > q->rear);
}
// lay mot phan tu o dau hang doi
int top_queue(Queue *q)
{
    return (q->data[q->front]);
}
void pop_queue(Queue *q)
{
    q->front++;
}
int min(int a, int b)
{
    return (a < b ? a : b);
}
void init_flow(Graph *pG)
{
    for (int u = 1; u <= pG->n; u++)
    {
        for (int v = 1; v <= pG->n; v++)
        {
            pG->F[u][v] = 0;
        }
    }
}
int FordFullkerson(Graph *pG, int s, int t)
{
    int u;
    init_flow(pG);
    int max_flow = 0;
    Queue Q;
    do
    {
        for (u = 1; u <= pG->n; u++)
        {
            label[u].dir = 0;
        }

        label[s].dir = +1;
        label[s].p = s;
        label[s].sigma = oo;

        make_null_queue(&Q);
        push_queue(&Q, s);

        int found = 0;
        while (!empty_queue(&Q))
        {
            int u = top_queue(&Q);
            pop_queue(&Q);

            for (int v = 1; v <= pG->n; v++)
            {
                if (pG->C[u][v] != NO_EDGE && label[v].dir == 0 && pG->F[u][v] < pG->C[u][v])
                {
                    label[v].dir = +1;
                    label[v].p = u;
                    label[v].sigma = min(label[u].sigma, pG->C[u][v] - pG->F[u][v]);
                    push_queue(&Q, v);
                }
            }

            //
            for (int x = 1; x <= pG->n; x++)
            {
                if (pG->C[x][u] != NO_EDGE && label[x].dir == 0 && pG->F[x][u] > 0)
                {
                    label[x].dir = -1;
                    label[x].p = u;
                    label[x].sigma = min(label[u].sigma, pG->F[x][u]);
                    push_queue(&Q, x);
                }
            }

            if (label[t].dir != 0)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            int sigma = label[t].sigma;
            int u = t;
            while (u != s)
            {
                int p = label[u].p;
                if (label[u].dir > 0)
                    pG->F[p][u] += sigma;
                else
                    pG->F[u][p] -= sigma;
                u = p;
            }
            max_flow += sigma;
        }
        else
            break;

    } while (1);

    return max_flow;
}
int main()
{
    Graph G;
    int n, m, u, v, e, c;
    freopen("dt.txt", "r", stdin);

    scanf("%d%d", &n, &m);

    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &c);
        G.C[u][v] = c;
        // printf("%d %d %d\n", u, v, G.C[u][v]);
    }
    int max_flow = FordFullkerson(&G, 1, n);
    printf("Max flow: %d\n", max_flow);
    printf("S: ");
    for (int u = 1; u <= G.n; u++)
    {
        if (label[u].dir != 0)
            printf("%d ", u);
    }
    printf("\nT: ");
    for (int u = 1; u <= G.n; u++)
    {
        if (label[u].dir == 0)
            printf("%d ", u);
    }
    return 0;
}
