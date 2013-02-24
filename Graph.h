/*
Name      : Alberto Plata
Student ID: 1291980
Assignment: pa4

*/
#if !defined(_GRAPH_H_INCLUDE_)
#define _GRAPH_H_INCLUDE_

#include "List.h"

/***************************** Exported Types *************************************/
typedef struct Graph * GraphRef;


/*** Constructors-Destructors ***/
GraphRef newGraph(int n);
void freeGraph(GraphRef* pG);


/*** Access functions ***/
int getOrder(GraphRef G);
int getSize(GraphRef G);
int getSource(GraphRef G);
int getParent(GraphRef G, int u);
int getDist(GraphRef G, int u);
void getPath(ListRef L, GraphRef G, int u);


/*** Manipulation procedures ***/
void makeNull(GraphRef G);
void addEdge(GraphRef G, int u, int v);
void addArc(GraphRef G, int u, int v);
void BFS(GraphRef G, int s);


/*** Other operations ***/
void printGraph(FILE* out, GraphRef G);
void printG(GraphRef G);

#endif
