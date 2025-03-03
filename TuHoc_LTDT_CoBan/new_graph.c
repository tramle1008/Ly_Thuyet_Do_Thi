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
    init_graph(&G, 6);

    add_adge(&G, 2, 6);
    add_adge(&G, 6, 4);
    add_adge(&G, 5, 6);
    add_adge(&G, 1, 4);
    add_adge(&G, 1, 5);
    add_adge(&G, 2, 3);
    add_adge(&G, 2, 4);
    add_adge(&G, 4, 5);

    // printf("%d", adjacent(&G, 2, 3));
    // printf("\n%d", adjacent(&G, 3, 4));

    // printf("%d", degree(&G, 2));

    // in ra tat ca cac bac cua cac dinh
    int i;
    for (i = 1; i <= G.n; i++)
    {
        printf("deg(%d) = %d\n", i, degree(&G, i));
    }

    // int i, j;
    // printf("%d\n", G.n);
    // for (i = 1; i <= G.n; i++)
    // {
    //     for (j = 1; j <= G.n; j++)
    //     {
    //         printf("%d ", G.A[i][j]);
    //     }
    //     printf("\n");
    // }
    // return 0;
}