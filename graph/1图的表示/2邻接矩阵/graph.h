/*
    图的邻接矩阵表示法
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#define MaxVertexNum 100
#define INFINITY 65535
typedef int WeightType;
typedef int Vertex;
typedef char DataType;

/*边的定义*/
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex v1,v2; 
    WeightType weight;
};
typedef PtrToENode Edge;

/*图结点的定义*/
typedef struct GNode* PtrToGNode;
struct GNode{
    int nv;     /*顶点数*/
    int ne;     /*边数*/
    WeightType G[MaxVertexNum][MaxVertexNum];/*邻接矩阵*/
    DataType Data[MaxVertexNum]; /*顶点数据*/
};
typedef PtrToGNode MGraph;

/*初始化一个有VertexNum个顶点但没有边的图*/
MGraph CreateGraph(int VertexNum);
/*向图中插入一条边*/
void InsertEdge(MGraph Graph,Edge E);
/*建图*/
MGraph BuildGraph(int Nv,int Ne);




#endif
