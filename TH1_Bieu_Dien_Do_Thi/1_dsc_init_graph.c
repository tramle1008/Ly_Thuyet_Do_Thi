#include <stdio.h>
#define MAX_M 500
typedef struct
{
    int u, v;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[MAX_M];
} Graph;
/*Viết mã lệnh của bạn*/
void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}

/*Hết phần mã lệnh của bạn*/
int main()
{
    Graph G;
    init_graph(&G, 5);
    printf("Do thi co %d dinh va %d cung.", G.n, G.m);
    return 0;
}
