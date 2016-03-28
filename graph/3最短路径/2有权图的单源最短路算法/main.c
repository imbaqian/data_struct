/*
	邻接表-有权图-单向-单源最短路算法
	Dijkstra
*/

#include "graph.h"
#include <stdio.h>


// dist[v]  s 到 v 的最短路径长度
// collected[v] 记录顶点v有没有被收录
// path[v] 记录v的前面的顶点


/*返回未被收录顶点中dist最小者*/
Vertex FindMinDist( LGraph Graph,Vertex V,int dist[], int collected[])
{
	Vertex minV;/*待返回的值*/
	PtrToAdjVNode w;
	int MinDist = INFINITY;
	for(w = Graph->G[V].FirstEdge; NULL != w; w=w->next)
		if( collected[w->AdjV] == -1) /*未被收录*/
			if(w->weight < MinDist){
				MinDist = w->weight;
				minV = w->AdjV;
			}
	if(MinDist < INFINITY)
		return minV;
	else
		return -1;//错误	
}

int Dijkstra(LGraph Graph, int dist[],int path[],Vertex S)
{
	int i;
	int collected[MaxVertexNum];
	Vertex v;
	PtrToAdjVNode w;
	/*初始化collected[]*/
	for(v = 0;v<Graph->nv;v++)
	{
		collected[v] = -1;
	}
	for(w=Graph->G[S].FirstEdge;w!=NULL;w=w->next){
		dist[w->AdjV] = w->weight;
		path[w->AdjV] = S;
	}
	
	/*收录S*/
	dist[S] = 0;
	collected[S] = 1;
	v = S;
	while(1){
		v = FindMinDist(Graph,v,dist,collected);
		if( -1 == v )
			break;
		collected[v] = 1;

		for(w = Graph->G[v].FirstEdge; NULL != w; w=w->next){
				if(dist[v] + w->weight < dist[w->AdjV] ){ // 
					dist[w->AdjV] = dist[v] + w->weight;
					path[w->AdjV] = v;
				}
			}
	}
	for(i=0;i<Graph->nv;i++){
		printf("%d ",collected[i]);
	}
	printf("\n");

	return 1;/*算法执行完毕。返回正确标记*/	
}

void Init(int dist[],int path[])
{
	int i;
	for(i = 0;i<MaxVertexNum;i++){
		dist[i] = INFINITY;
		path[i] = -1;
	}
}


int main()
{
	int i;
	int dist[MaxVertexNum];
	int path[MaxVertexNum];
	LGraph graph;
	graph = BuildGraph();
	Init(dist,path);
	Dijkstra(graph,dist,path,0);	
	for(i=0;i<graph->nv;i++){
		printf("%d ",path[i]);
	}
	printf("\n");
	for(i=0;i<graph->nv;i++){
		printf("%d ",dist[i]);
	}	
	return 0;
}
