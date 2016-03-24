

#include <stdio.h>
#include "graph.h"
#include "dfs.h"


int main()
{
	LGraph graph;
	int ne,nv;
	scanf("%d %d",&ne,&nv);
	graph = BuildGraph(ne,nv);
	DFS(graph,0,Visit);
	return 0;
	
}
