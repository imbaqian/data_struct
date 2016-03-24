#include "bfs.h"
#include <stdio.h>


Vertex VisitedBFS[MaxVertexNum]; 

void Visit(Vertex V)
{
    printf("%d ",V);
}

void BFS(LGraph Graph ,Vertex V , void (*Visit)(Vertex) )
{
    Queue  queue;
    Vertex v;
    PtrToAdjVNode w;
    queue = CreateQueue(20);
    AddQueue(queue,V);
    VisitedBFS[V] = 1;/*标记已经访问*/
	Visit(V);
	while(queue->front != queue->rear){/*队列不为空*/
        v = DeleteQueue(queue);
        for(w = Graph->G[v].FirstEdge ; w != NULL ; w = w->next )
            if(VisitedBFS[w->AdjV] == 0){
				AddQueue(queue,w->AdjV);
				VisitedBFS[w->AdjV] = 1;
				Visit(w->AdjV);
			}
        
    }     
} 



