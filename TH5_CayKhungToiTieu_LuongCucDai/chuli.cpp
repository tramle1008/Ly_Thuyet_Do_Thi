#include <stdio.h>
#define MAXN 100
#define MAXM 500
#define INF 999999

typedef struct
{
    int u, v;
    int w;
    int link;
} Edge;

typedef struct
{
    int n, m;
    Edge edges[MAXM];
} Graph;

typedef struct
{
    int n;
    int parent[MAXN];
    int weight[MAXN];
    int link[MAXM];
} Tree;
void init_graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
}

void init_tree(Tree *T, int n)
{
    T->n = n;
    int i;
    for (i = 1; i <= n; i++)
    {
        T->parent[i] = -1;
        T->weight[i] = INF;
        T->link[i] = -1;
    }
}

void add_edge(Graph *G, int u, int v, int w, int link)
{
    int m = G->m;
    G->edges[m].u = u;
    G->edges[m].v = v;
    G->edges[m].w = w;
    G->edges[m].link = link;
    G->m++;
}

void buildH(Graph *G, int root, Tree *H)
{
    init_tree(H, G->n);
    int e;
    for (e = 0; e < G->m; e++)
    {
        int u = G->edges[e].u;
        int v = G->edges[e].v;
        int w = G->edges[e].w;
        int link = G->edges[e].link;
        if (w < H->weight[v])
        {
            H->parent[v] = u;
            H->weight[v] = w;
            H->link[v] = link;
        }
    }
    H->parent[root] = -1;
    H->weight[root] = 0;
}
int id[MAXN];
int find_cycles(Tree *H, int root)
{
    int i, u, no = 0;
    int color[MAXN];
    for (i = 1; i <= H->n; i++)
    {
        id[i] = -1;
        color[i] = -1;
    }
    for (i = 1; i <= H->n; i++)
    {
        int u = i;
        while (u != root && id[u] == -1 && color[u] != i)
        {
            color[u] = i;
            u = H->parent[u];
        }
        if (color[u] == i)
        {
            no++;
            int v = H->parent[u];
            while (v != u)
            {
                id[v] = no;
                v = H->parent[v];
            }
            id[u] = no;
        }
    }
    return no;
}
void contract(Graph *G, Tree *H, int no, Graph *G1)
{
    init_graph(G1, no);
    int e;
    for (e = 0; e < G->m; e++)
    {
        int u = G->edges[e].u;
        int v = G->edges[e].v;
        int w = G->edges[e].w;
        if (id[u] != id[v])
            add_edge(G1, id[u], id[v], w - H->weight[v], e);
    }
}
void expand(Tree *H, Graph *G1, Tree *H1)
{
    int i;
    for (i = 1; i <= H->n; i++)
        if (H->parent[i] != -1)
        {
            Edge pe = G1->edges[H->link[i]];
            H1->parent[pe.v] = pe.u;
            H1->weight[pe.v] += H->weight[i];
            H1->link[pe.v] = pe.link;
        }
}

#define MAXIT 10
void ChuLiu(Graph *G0, int s, Tree *T)
{
    Graph G[MAXIT];
    Tree H[MAXIT];
    int i, e;

    int t = 0;
    int root = s;
    G[0] = *G0;
    while (1)
    {
        buildH(&G[t], root, &H[t]);
        int no = find_cycles(&H[t], root);
        if (no == 0)
            break;
        for (i = 1; i <= H[t].n; i++)
        {
            if (id[i] == -1)
                id[i] = ++no;
        }
        contract(&G[t], &H[t], no, &G[t + 1]);
        root = id[root];
        t++;
    }
    int k;
    for (k = t; k > 0; k--)
        expand(&H[k], &G[k - 1], &H[k - 1]);

    *T = H[0];
}
int main()
{
    Graph G;
    int n, m, i, e, u, v, w;

    freopen("chuli.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w, -1);
    }

    Tree T;
    ChuLiu(&G, 1, &T);

    for (i = 1; i <= T.n; i++)
        if (T.parent[i] != -1)
            printf("(%d, %d) %d \n", T.parent[i], i, T.weight[i]);

    return 0;
}