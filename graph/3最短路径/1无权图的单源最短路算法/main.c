/*
   无权图的单源最短路算法

 */
#include <stdio.h>
#include "graph.h"
#include "queue.h"

int dist[MaxVertexNum]; /*dist[i] 记录顶点i距离Source的距离*/ 
int path[MaxVertexNum]; /*path[i] 记录顶点i的前一个顶点*/

void Unweighted(LGraph Graph, Vertex S)
{
	Vertex v;
	Queue queue;
	PtrToAdjVNode w;
	queue = CreateQueue(20);
	dist[S] = 0;
	AddQueue(queue,S);
	while(queue->rear != queue->front){
		v = DeleteQueue(queue);
		for(w = Graph->G[v].FirstEdge ; NULL != w ; w = w->next )
			if(dist[w->AdjV] == -1){ /**/
				dist[w->AdjV] = dist[v] + 1;
				path[w->AdjV] = v;
				AddQueue(queue,w->AdjV);
			}
	}

}

void InitDistPath()
{
	int i;
	for(i=0;i<MaxVertexNum;i++){
		dist[i] = -1;
		path[i] = -1;
	} 
}

int main()
{
	int i;
	int Source,Destination;
	InitDistPath();
	LGraph graph;
	graph = BuildGraph();
	printf("input Source:");
	scanf("%d",&Source);
	Unweighted(graph,Source);
	printf("input Destination:");
	scanf("%d",&Destination);


	for(i =  Destination;i != -1; i = path[i])
		printf("%d<--",i);

}
