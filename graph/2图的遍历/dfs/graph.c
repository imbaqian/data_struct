/*
	无向图，无权重,图的建立
*/
#include "graph.h"
#include <malloc.h>

LGraph CreateGraph(int VertexNum)
{
	int i;
	LGraph newGraph = (LGraph)malloc(sizeof(struct GNode));
	newGraph->nv = VertexNum;
	newGraph->ne = 0;
	/*一定要初始化每个顶点表头的FirstEdge*/
	for(i = 0;i < VertexNum;i++){
		newGraph->G[i].FirstEdge = NULL;
	}
	return newGraph;
}

void InsertEdge(LGraph Graph,Edge E)
{	

	PtrToAdjVNode newAdjV1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); 	
	newAdjV1->AdjV = E->v2;
	/*需要权重的时候添加下一行代码*/
	//newAdjV1->weight = E->weight;

	/*头插还是方便点的哦～*/	
	newAdjV1->next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = newAdjV1;
	


	/*无向图既要<v1,v2> 也要 <v2,v1>*/
	PtrToAdjVNode newAdjV2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	newAdjV1->AdjV = E->v1;

	/*同样，需要权重在这里添加 ↓ */
	//newAdjV2->weight = E->weight;
	
	newAdjV2->next = Graph->G[E->v2].FirstEdge;
	Graph->G[E->v2].FirstEdge = newAdjV2;
	
	
}

LGraph BuildGraph(int nv , int ne)
{
	int i;
	LGraph newGraph;
	Edge newEdge;
	newGraph = CreateGraph(nv);
	for(i = 0; i< ne; i++){
		newEdge = (Edge)malloc(sizeof(struct ENode));	
		scanf("%d %d",newEdge->v1,newEdge->v2);/*有权重就读权重呗*/
		InsertEdge(newGraph,newEdge);	
	}
	return newGraph;
}

