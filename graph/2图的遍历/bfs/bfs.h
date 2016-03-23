#ifndef BFS_H_
#define BFS_H_

#include "graph.h"
#include "queue.h"


extern Vertex VisitedBFS[MaxVertexNum];
void Visit(Vertex V);

void BFS(LGraph Graph,Vertex V,void (*Visit)(Vertex) );





#endif
