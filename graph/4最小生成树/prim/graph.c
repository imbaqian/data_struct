/*
	无向图，无权重,图的建立
*/
#include "graph.h"
#include <malloc.h>
#include <stdio.h>

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
	newAdjV1->weight = E->weight;

	/*头插还是方便点的哦～*/	
	newAdjV1->next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = newAdjV1;
	
}

LGraph BuildGraph()
{
	int i;
	int nv,ne;
	LGraph newGraph;
	Edge newEdge;
	printf("input Nv,Ne:");
	scanf("%d %d",&nv,&ne);
	newGraph = CreateGraph(nv);
	newGraph->ne = ne; 
	for(i = 0; i< ne; i++){
		newEdge = (Edge)malloc(sizeof(struct ENode));
		printf("input <v1,v2>");	
		scanf("%d %d %d",&newEdge->v1,&newEdge->v2,&newEdge->weight);/*有权重就读权重呗*/
		InsertEdge(newGraph,newEdge);	
	}
	return newGraph;
}

