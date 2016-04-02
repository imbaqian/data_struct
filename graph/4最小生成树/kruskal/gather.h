/*
	并查集的实现
 */	

#ifndef GATHER_H_
#define GATHER_H_
#include "graph.h"
#define MAXN 1000		/*集合最大元素个数*/
typedef Vertex ElementType;/*默认元素可以用非负整数表示*/
typedef ElementType SetName;	/*默认用根节点的下表作为集合名称*/
typedef struct SetNode{
	ElementType Data;
	int parent; /*父亲结点的下标，-n表示该集合的元素个数*/
}SetType;

/*并操作，这里默认Root1和Root2是不同集合的根节点，保证小集合并入大集合*/
void SetUnion(SetType S[],ElementType X1,ElementType X2);
/*查找元素X属于哪个集合，返回根的值，默认集合元素全部初始化为-1*/
SetName SetFind(SetType S[],ElementType X);

#endif
