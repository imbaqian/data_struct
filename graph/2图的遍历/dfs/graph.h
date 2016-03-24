/*
	图的邻接表表示法	
	
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#define	MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

/*边的定义*/
typedef struct ENode* PtrToENode;
struct ENode{
	Vertex v1,v2;/*有向边 < v1 , v2 >*/
	WeightType weight;/*边权重*/		
};
 typedef PtrToENode Edge;
/*邻接点的定义*/
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;	/*邻接点下标*/
	WeightType weight;/*边权重*/
	PtrToAdjVNode next;/*指向下一个邻接点的指针*/	
};

/*顶点表头结点的定义*/
typedef struct VNode{
	PtrToAdjVNode FirstEdge;/*边表头指针*/
	DataType data;	/*顶点数据*/
}AdjList[MaxVertexNum];	/*AdjList是邻接表类型*/

/*图结点定义*/
typedef struct GNode* PtrToGNode;
struct GNode {
	int nv;	/*顶点数*/
	int ne;	/*边数*/
	AdjList G;/*邻接表*/
};

typedef PtrToGNode LGraph;

/*初始化一个有VertexNum个顶点蛋没有边的图*/
LGraph CreateGraph(int VertexNum);
/*向图中插入一个边*/
void InsertEdge(LGraph Graph , Edge E);
/*建表哦*/
LGraph BuildGraph(int nv , int ne);




#endif
