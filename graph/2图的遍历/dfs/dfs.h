/*
    邻接表图-DFS
*/


#ifndef DFS_H_
#define DFS_H_
#include "graph.h"

extern int VisitedDFS[MaxVertexNum];
void Visit(Vertex v);
void DFS(LGraph Graph,Vertex V, void (*Visit)(Vertex) );


#endif
