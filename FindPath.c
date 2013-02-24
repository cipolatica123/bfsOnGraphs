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

#define MAX_LEN 250

int main(int argc, char* argv[]){
	GraphRef G = NULL; 
	ListRef L = newList();
	int u, v;
	int count=0;
	int numOfZero = 0;
	FILE *in, *out;
	char line[MAX_LEN];
	char tokenlist[MAX_LEN];
	char* token;
	
	/* check command line for correct number of arguments */
	if( argc != 3 ){
		printf("Usage: %s infile outfile\n", argv[0]);
		exit(1);
	}

	/* open files for reading and writing */
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if( in==NULL ){
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if( out==NULL ){
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}
	while( fgets(line, MAX_LEN, in) != NULL){
		count++;
		token = strtok(line, " \n");
		tokenlist[0] = '\0';
		while( token!=NULL ){
			if(count == 1){
				G = newGraph(atoi(token));
			}
			else if ((atoi(token)) == 0){
				numOfZero++;
				token = strtok(NULL, " \n"); 
				if (numOfZero == 1){
					printGraph(out, G);
				}
			}
			else if (numOfZero == 0){
				u = atoi(token);
				token = strtok(NULL, " \n"); 
				v = atoi(token);
				addEdge(G, u, v);
			}
			else if (numOfZero == 1){
				u = atoi(token);
				token = strtok(NULL, " \n");
				BFS(G, u);
				v = atoi(token);
				getPath(L, G, v);
				fprintf(out, "The distance from %d to %d is ", u, v);
				if (getDist(G, v) < 0){
					fprintf(out,"infinity\n");
					fprintf(out, "No %d-%d path exists\n\n", u, v);
				}
				else{
					fprintf(out, "%d\n", getDist(G, v));
					fprintf(out, "A shortest %d-%d path is: ", u, v);
					printList(out, L);
					fprintf(out,"\n");
				}
				
			}
			token = strtok(NULL, " \n"); 
		}
	}

   fclose(in);
   fclose(out);

   return(0);
}
	