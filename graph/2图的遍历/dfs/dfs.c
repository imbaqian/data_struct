#include "dfs.h"
#include <stdio.h>
int VisitedDFS[MaxVertexNum];

void Visit(Vertex V)
{
    printf("%d ",V);
}

void DFS(LGraph Graph,Vertex V,void (*Visit)(Vertex) )
{
    PtrToAdjVNode w;
    Visit(V); /*访问第V个顶点*/
    VisitedDFS[V] = 1;/*标记第V个顶点被访问*/
    for(w = Graph->G[V].FirstEdge;w != NULL ; w = w->next){/*对V的每个邻接点访问*/
        if(0 == VisitedDFS[w->AdjV])   /*若邻接点没有被访问*/
            DFS(Graph,w->AdjV,Visit);   /*则递归访问该邻接点*/
    }

}
