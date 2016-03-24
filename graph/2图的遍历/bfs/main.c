#include "graph.h"
#include "queue.h"
#include "bfs.h"
#include <stdio.h>




int main()
{

    LGraph graph;
	int nv,ne;
	scanf("%d %d",&nv,&ne);
    graph = BuildGraph(nv,ne);
    BFS(graph,0,Visit);
    return 0;
}
