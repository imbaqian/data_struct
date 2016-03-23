/*
    邻接矩阵建图的实现
    无相无权重图
*/

#include "graph.h"
#include <stdio.h>
#include <malloc.h>
/*初始化一个有VertexNum个顶点但没有边的图*/
MGraph CreateGraph(int VertexNum)
{
    MGraph newGraph = (MGraph)malloc(sizeof(struct GNode));
    newGraph->nv = VertexNum;
    newGraph->ne = 0;
    return newGraph;
}
 
/*向图中插入一条边*/
void InsertEdge(MGraph Graph,Edge E)
{
    Graph->G[E->v1][E->v2] = E->weight;
    Graph->G[E->v2][E->v1] = E->weight; 
}
/*建图*/
MGraph BuildGraph(int Nv,int Ne)
{
    int i;
    Edge newEdge;
    MGraph newGraph = CreateGraph(Nv);
    for( i = 0;i < Ne;i++ ){
        newEdge = (Edge)malloc(sizeof(struct GNode));
        scanf("%d %d",&newEdge->v1,&newEdge->v2);
        InsertEdge(newGraph,newEdge);
    }
    return newGraph;
}    

