/*
Name      : Alberto Plata
Student ID: 1291980
Assignment: pa4

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"Graph.h"



int main(int argc, char* argv[]){
	GraphRef G = newGraph(6);
	GraphRef GArc = newGraph(6);
	GraphRef GDis = newGraph(7);
	ListRef L = newList();
	printf("getDist   = %d\n", getDist(G, 6));
	printf("getOrder  = %d\n", getOrder(G));
	printf("getSize   = %d\n", getSize(G));
	printf("getSource = %d\n", getSource(G));
	printf("getParent = %d\n", getParent(G, 6));
	addEdge(G, 1, 2);
	addEdge(G, 1, 3);
	addEdge(G, 2, 4);
	addEdge(G, 2, 5);
	addEdge(G, 2, 6);
	addEdge(G, 3, 4);
	addEdge(G, 4, 5);
	addEdge(G, 5, 6);
	
	printG(G);
	
	BFS(G, 3);
	getPath(L, G, 6);
	printf("getDist   = %d\n", getDist(G, 6));
	printf("getOrder  = %d\n", getOrder(G));
	printf("getSize   = %d\n", getSize(G));
	printf("getSource = %d\n", getSource(G));
	printf("getParent = %d\n", getParent(G, 6));
	printLIST(L);
	
	printG(G);
	
	BFS(G, 1);
	getPath(L, G, 5);
	printf("distance = %d\n", getDist(G, 5));
	printLIST(L); 
	makeNull(G);
	printf("getDist   = %d\n", getDist(G, 6));
	printf("getOrder  = %d\n", getOrder(G));
	printf("getSize   = %d\n", getSize(G));
	printf("getSource = %d\n", getSource(G));
	printf("getParent = %d\n", getParent(G, 6));
	printG(G);
	printf("\n\n\nnow for addArc\n\n");
	printf("getDist   = %d\n", getDist(GArc, 6));
	printf("getOrder  = %d\n", getOrder(GArc));
	printf("getSize   = %d\n", getSize(GArc));
	printf("getSource = %d\n", getSource(GArc));
	printf("getParent = %d\n", getParent(GArc, 6));
	addArc(GArc, 1, 2);
	addArc(GArc, 1, 3);
	addArc(GArc, 2, 4);
	addArc(GArc, 2, 5);
	addArc(GArc, 2, 6);
	addArc(GArc, 3, 4);
	addArc(GArc, 4, 5);
	addArc(GArc, 5, 6);
	printf("getDist   = %d\n", getDist(GArc, 6));
	printf("getOrder  = %d\n", getOrder(GArc));
	printf("getSize   = %d\n", getSize(GArc));
	printf("getSource = %d\n", getSource(GArc));
	printf("getParent = %d\n", getParent(GArc, 6));
	printG(GArc);
	BFS(GArc, 1);
	printf("getDist   = %d\n", getDist(GArc, 6));
	printf("getOrder  = %d\n", getOrder(GArc));
	printf("getSize   = %d\n", getSize(GArc));
	printf("getSource = %d\n", getSource(GArc));
	printf("getParent = %d\n", getParent(GArc, 6));
	printf("\n\n\nnow for a disconnected graph\n\n");
	
	
	printf("getDist   = %d\n", getDist(GDis, 6));
	printf("getOrder  = %d\n", getOrder(GDis));
	printf("getSize   = %d\n", getSize(GDis));
	printf("getSource = %d\n", getSource(GDis));
	printf("getParent = %d\n", getParent(GDis, 6));
	addEdge(GDis, 1, 4);
	addEdge(GDis, 1, 5);
	addEdge(GDis, 2, 3);
	addEdge(GDis, 3, 7);
	addEdge(GDis, 4, 5);
	addEdge(GDis, 2, 6);
	addEdge(GDis, 6, 7);
	printf("getDist   = %d\n", getDist(GDis, 6));
	printf("getOrder  = %d\n", getOrder(GDis));
	printf("getSize   = %d\n", getSize(GDis));
	printf("getSource = %d\n", getSource(GDis));
	printf("getParent = %d\n", getParent(GDis, 6));
	BFS(GDis, 1);
	getPath(L, GDis, 7);
	printf("\n\ngetDist   = %d\n", getDist(GDis, 6));
	printf("getOrder  = %d\n", getOrder(GDis));
	printf("getSize   = %d\n", getSize(GDis));
	printf("getSource = %d\n", getSource(GDis));
	printf("getParent = %d\n", getParent(GDis, 6));
	printf("\n\ngetDist   = %d\n", getDist(GDis, 5));
	printf("getParent = %d\n", getParent(GDis, 5));
   return(0);
}
	