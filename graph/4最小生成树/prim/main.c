/*
   Prim 算法
 */


#include <stdio.h>
#include "graph.h"


Vertex FindMinDist(int dist[],int MST[])
{
	Vertex MinV = -1;
	int MinDist = 65535;
	int i;
	for(i=0;i<3;i++){
		if(MST[i] == -1)
			if(dist[i] < MinDist){
				MinDist = dist[i];
				MinV = i;
			}
	}
	return MinV;

}
void Init(int MST[],int dist[],int parent[])
{
	int i;
	for(i=0;i<MaxVertexNum;i++){
		MST[i] = -1;
		dist[i] = 65535;
		parent[i] = -1;
	}

}


void Prim(LGraph Graph)
{
	Vertex v;
	PtrToAdjVNode w;
	int i;
	int MST[MaxVertexNum];/*记录是否被收录*/
	int dist[MaxVertexNum];/*记录顶点到MST的距离*/
	int parent[MaxVertexNum];/*记录顶点的父结点*/
	Init(MST,dist,parent);
	/*初始化源点*/
	dist[0] = 0;	

	while(1){
		v = FindMinDist(dist,MST);
		if(v == -1)
			break;
		MST[v] = 1;
		dist[v] = 0;
		for(w = Graph->G[v].FirstEdge; NULL != w;w=w->next){
			if(MST[w->AdjV] == -1){
				if(w->weight < dist[w->AdjV])
					dist[w->AdjV] = w->weight;
				parent[w->AdjV] = v;
			}
		}
	}
	for(i=0;i<Graph->nv;i++)
	{
		printf("%d ",MST[i]);
	}
	printf("\n");
	for(i=0;i<Graph->nv;i++)
	{
		printf("%d ",dist[i]);
	}
	printf("\n");
	for(i=0;i<Graph->nv;i++)
	{
		printf("%d ",parent[i]);
	}
	printf("\n");

}	



int main()
{
	LGraph graph;
	graph = BuildGraph();
	Prim(graph);	
}
