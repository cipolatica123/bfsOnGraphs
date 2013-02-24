/*
Name      : Alberto Plata
Student ID: 1291980
Assignment: pa4

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "Graph.h"

#define INF -1
#define NIL 0

typedef struct Graph{
   ListRef* adj;
   int* color;
   int* parent;
   int* dist;
   int order; /* number of vertices*/  
   int size;  /* number of edges */
   int source;
} Graph;

/*** Constructors-Destructors ***/
GraphRef newGraph(int n){
	int i;
	GraphRef G = malloc(sizeof(Graph));
	G->color = calloc(n+1, sizeof(int));
	G->dist = calloc(n+1, sizeof(int));
	G->parent = calloc(n+1, sizeof(int));
	G->adj = calloc(n+1, sizeof(ListRef));
	G->order = n;
	G->size = 0;
	G->source = NIL;
	for(i = 1; i <= n; i++){
		G->color[i] = 0;
		G->dist[i] = INF;
		G->parent[i] = NIL;
		G->adj[i] = newList();
	}
	return(G);
}

void freeGraph(GraphRef* pG){
	int i;
	if(pG == NULL || *pG == NULL)	return;
	for(i = 1; i <= getOrder(*pG); i++){
		freeList(&(*pG)->adj[i]);
	}
	free((*pG)->adj);
	free((*pG)->color);
	free((*pG)->parent);
	free((*pG)->dist);
	*pG = NULL;
}


/*** Access functions ***/
int getOrder(GraphRef G) { return(G->order); }

int getSize(GraphRef G) { return(G->size); }

int getSource(GraphRef G){ return(G->source); }

int getParent(GraphRef G, int u){ 
	if(u < 1 || u > getOrder(G)){
		printf("Called getParent with u < 1 || u > getOrder(G)\n");
		exit(1);
	}
	return(G->parent[u]); 
}

int getDist(GraphRef G, int u){ 
	if(u < 1 || u > getOrder(G)){
		printf("Called getDist with u < 1 || u > getOrder(G)\n");
		exit(1);
	}
	return(G->dist[u]);  
}

void getPath(ListRef L, GraphRef G, int u){
	int s;
	int temp;
	if (!isEmpty(L)){
		makeEmpty(L);
	}
	if(u < 1 || u > getOrder(G)){
		printf("Called getPath with u < 1 || u > getOrder(G)\n");
		exit(1);
	}
	if(getSource(G) == NIL || getDist(G,u) == INF){
		insertBack(L, NIL);
		return;
	}
	s = G->source;
	insertBack(L,u);
	temp = u;
	while(temp != s){
		temp = getParent(G, temp);
		insertFront(L, temp);
	}
	/* printf("A shortest %d-%d path is: ", G->source, u);  */
}


/*** Manipulation procedures ***/


void makeNull(GraphRef G){
	int i;
	for(i = 1; i <= getOrder(G); i++){
		makeEmpty((G)->adj[i]);
		G->color[i] = 0;
		G->parent[i] = NIL;
		G->dist[i] = INF;
	}
	G->size = 0;
	G->source = NIL;
}
void addEdge(GraphRef G, int u, int v){
	if(u < 1 || u > getOrder(G)){
		printf("Called addEdge with u < 1 || u > getOrder(G)\n");
		exit(1);
	}
	if(v < 1 || v > getOrder(G)){
		printf("Called addEdge with v < 1 || v > getOrder(G)\n");
		exit(1);
	}
	insertBack(G->adj[u], v);
	insertBack(G->adj[v], u);
	G->size++;
}
void addArc(GraphRef G, int u, int v){
	if(u < 1 || u > getOrder(G)){
		printf("Called addArc with u < 1 || u > getOrder(G)\n");
		exit(1);
	}
	if(v < 1 || v > getOrder(G)){
		printf("Called addArc with v < 1 || v > getOrder(G)\n");
		exit(1);
	}
	insertBack(G->adj[u], v);
	G->size++;
}


void BFS(GraphRef G, int s){
	int i;
	int v;
	int u;
	ListRef Q = newList();
	if(s < 1 || s > getOrder(G)){
		printf("Called BFS  with s < 1 || s > getOrder(G)\n");
		exit(1);
	}
	G->source = s;
	for(i = 1; i <= getOrder(G); i++){
		if(i != s){
			G->color[i] = 0;
			G->parent[i] = NIL;
			G->dist[i] = INF;
		}
	}
	G->color[s] = 1;
	G->parent[s] = NIL;
	G->dist[s] = 0;
	insertBack(Q, s);
	while(!isEmpty(Q)){
		u = getFront(Q);
		deleteFront(Q);
		for(i = 0; i < getLength(G->adj[u]); i++){
			moveTo(G->adj[u], i);
			v = getCurrent(G->adj[u]);
			if(G->color[v] == 0){
				G->color[v] = 1;
				G->dist[v] = G->dist[u] + 1;
				G->parent[v] = u;
				insertBack(Q,v);
			}
		}
		G->color[u] = 2;
	}
	freeList(&Q); 
}

/*** Other operations ***/
void printGraph(FILE* out, GraphRef G){
	int i;
	if( out==NULL ){
		printf("Graph Error: calling printGraph() on closed file\n");
		exit(1);
    }
	if( G==NULL ){
		printf("Graph Error: calling printGraph() on NULL GraphRef\n");
		exit(1);
    }
	for(i = 1; i <= getOrder(G); i++){
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
	}
	fprintf(out, "\n");
}

void printG(GraphRef G){
	int i;
	for(i = 1; i <= getOrder(G); i++){
		if (getLength(G->adj[i]) != 0){
			printf("%d: ",i);
			moveTo(G->adj[i], 0);
			while(!offEnd(G->adj[i])){
				printf("%d", getCurrent(G->adj[i]));
				moveNext(G->adj[i]);
				if(!offEnd(G->adj[i])){
					printf(" ");
				}
			}
			printf("\n");
		}	
	}
}



