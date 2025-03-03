#include <stdio.h>
#define max_vertices 20
typedef struct
{
    int A[max_vertices][max_vertices];
    int n;
} Graph;
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            G->A[i][j] = 0;
    }
}

// them cung vao do thi
void add_adge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}
// kiem tra x,y co la lang gieng kh
int adjacent(Graph *G, int x, int y)
{
    return (G->A[x][y] != 0);
}
// bac cua dinh x
int degree(Graph *G, int x)
{
    int i, deg = 0;
    for (i = 1; i <= G->n; i++)
    {
        if (G->A[i][x] == 1)
            deg++;
    }
    return deg;
}
int main()
{

    Graph G;
    int e, n, m;

    FILE *file = fopen("dothi.txt", "r");
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n);
    int u, v;
    for (e = 1; e <= m; e++)
    {
        fscanf(file, "%d%d", &u, &v);
        add_adge(&G, u, v);
    }
    fclose(file);
    int i;
    for (i = 1; i <= G.n; i++)
    {
        printf("deg(%d) = %d\n", i, degree(&G, i));
    }
}