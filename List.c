/*
Name      : Alberto Plata
Student ID: 1291980
Assignment: pa4

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

typedef struct Node{
   int data;
   struct Node* previous;
   struct Node* next;
} Node;

typedef Node* NodeRef;

typedef struct List{
   NodeRef front;
   NodeRef current;
   NodeRef back;
   int length;
} List;

/*** Constructors-Destructors ***/
NodeRef newNode(int node_data){
   NodeRef N = malloc(sizeof(Node));
   N->data = node_data;
   N->previous = NULL;
   N->next = NULL;
   return(N);
}
void freeNode(NodeRef* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

ListRef newList(void){
	ListRef L;
	L = malloc(sizeof(List));
	L->front = L->current = L->back = NULL;
	L->length = 0;
	return(L);
}

void freeList(ListRef* pL){
	if(pL == NULL || *pL==NULL) {return;}
	while ( !isEmpty(*pL) ) { deleteBack(*pL); } /*Why is it *pL??*/
	free(*pL);
	*pL = NULL;
}
/*******************8* Access functions *********************************************/
int getLength(ListRef L){
	return(L->length);
}
int isEmpty(ListRef L){
	return(L->length == 0);
}
int offEnd(ListRef L){
	return(L->current == NULL);
}
int getIndex(ListRef L){
	int tempIndex = 0;
	NodeRef temp = NULL;
	if( L==NULL ){
      printf("List Error: calling getIndex() on NULL ListRef\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling getIndex() on an empty List\n");
      exit(1);
   }
   if( offEnd(L) ){
      printf("List Error: calling getIndex() on an undefined current\n");
      exit(1);
   }
   temp = L->front;
   while(temp != NULL && temp != L->current){
		temp = temp->next;
		tempIndex++;
   }
   return(tempIndex);
}
int getFront(ListRef L){
	if( L==NULL ){
      printf("List Error: calling getFront() on NULL ListRef\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling getFront() on an empty List\n");
      exit(1);
   }
   return(L->front->data);
}
int getBack(ListRef L){
	if( L==NULL ){
      printf("List Error: calling getBack() on NULL ListRef\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling getBack() on an empty List\n");
      exit(1);
   }
   return(L->back->data);
}
int getCurrent(ListRef L){
	 if( L==NULL ){
      printf("List Error: calling getCurrent() on NULL ListRef\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling getCurrent() on an empty List\n");
      exit(1);
   }
   if( offEnd(L) ){
      printf("List Error: calling getCurrent() on an undefined current\n");
      exit(1);
   } 
   return(L->current->data);
}
int equals(ListRef A, ListRef B){
	int flag = 1;
    Node* N = NULL;
    Node* M = NULL;
    if( A==NULL || B==NULL ){
		printf("List Error: calling equals() on NULL ListRef\n");
		exit(1);
    }
    N = A->front;
    M = B->front;
    if( A->length != B->length ) { return 0; }
    while( flag && N!=NULL){
		flag = (N->data==M->data);
		N = N->next;
		M = M->next;
    }
    return flag;
}
/***************************** Manipulation procedures **********************/
void makeEmpty(ListRef L){
	if (L == NULL){
      printf("List Error: calling makeEmpty() on NULL ListRef\n");
      exit(1);
    }
	while(L->front != NULL){
		deleteBack(L);
	}
}
void moveTo(ListRef L, int i){
	if( L==NULL ){
		printf("List Error: calling moveTo() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling moveTo() on an empty List\n");
		exit(1);
    }
	if(i >= 0 && i < L->length){
		L->current = L->front;
		while(i>0){
			moveNext(L);
			i--;
		}
	}
	else{
		L->current = NULL;
	}
}
void movePrev(ListRef L){
	if( L==NULL ){
		printf("List Error: calling movePrev() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling movePrev() on an empty List\n");
		exit(1);
    }
    if( offEnd(L) ){
		printf("List Error: calling movePrev() on an undefined current\n");
		exit(1);
    }
	L->current = L->current->previous;
}
void moveNext(ListRef L){
	if( L==NULL ){
		printf("List Error: calling moveNext() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling moveNext() on an empty List\n");
		exit(1);
    }
    if( offEnd(L) ){
		printf("List Error: calling moveNext() on an undefined current\n");
		exit(1);
    }
	L->current = L->current->next;
}
void insertFront(ListRef L, int data){
	NodeRef newN = newNode(data);
	if (L == NULL){
		printf("List Error: calling insertFront() on NULL ListRef\n");
		exit(1);
    }
	if(L->length ==0) { L->front = L->back = newN; }
	else{
		newN->next = L->front;
		L->front->previous = newN;
		L->front = newN;
	}
	L->length++;
}

void insertBack(ListRef L, int data){
	NodeRef newN = newNode(data);
	if (L == NULL){
		printf("List Error: calling insertBack() on NULL ListRef\n");
		exit(1);
    }
    if (L->length == 0){
		L->front = L->back = newN;
    }
	else{
		newN->previous = L->back;
		L->back->next = newN;
		L->back = newN;
	}
	L->length++;
}
void insertBeforeCurrent(ListRef L, int data){
	NodeRef newN = newNode(data);
	if( L==NULL ){
		printf("List Error: calling insertBeforeCurrent() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling insertBeforeCurrent() on an empty List\n");
		exit(1);
    }
    if( offEnd(L) ){
		printf("List Error: calling insertBeforeCurrent() on an undefined current\n");
		exit(1);
    }
	if (getIndex(L) == 0){ insertFront(L,data); } 
	else if (getIndex(L) == (L->length-1)) { insertBack(L,data); } 
	else{
		newN->previous = L->current->previous;
		newN->next = L->current;
		L->current->previous->next = newN;
		L->current->previous = newN;
		L->length++;
	}
}
void insertAfterCurrent(ListRef L, int data){
	NodeRef newN = newNode(data);
	if( L==NULL ){
		printf("List Error: calling insertAfterCurrent() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling insertAfterCurrent() on an empty List\n");
		exit(1);
    }
    if( offEnd(L) ){
		printf("List Error: calling insertAfterCurrent() on an undefined current\n");
		exit(1);
    }
	if (getIndex(L) == 0){ insertFront(L,data); } 
	else if (getIndex(L) == (L->length-1)) { insertBack(L,data); } 
	else{
		newN->previous = L->current;
		newN->next = L->current->next;
		L->current->next->previous = newN;
		L->current->next = newN;
		L->length++;
	}
}
void deleteFront(ListRef L){
	NodeRef N = NULL;
    if( L==NULL ){
		printf("List Error: calling deleteFront() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling deleteFront() on an empty List\n");
		exit(1);
    }
    N = L->front;
	if(L->current == L->front) { L->current = NULL; }
    if( getLength(L)>1 ) { L->front = L->front->next; }
    else { L->front = L->current = L->back = NULL; }
    L->length--;
    freeNode(&N);
}
void printLIST(ListRef L){
	NodeRef temp = NULL;
	if( L==NULL ){
      printf("List Error: calling print() on NULL ListRef\n");
      exit(1);
   }
   if( isEmpty(L) ){
      printf("List Error: calling print() on an empty List\n");
      exit(1);
   }
   temp = L->front;
   while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
   }
   printf("\n");
}
void deleteBack(ListRef L){
	NodeRef temp = NULL;
	if( L==NULL ){
		printf("List Error: calling deleteBack() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling deleteBack() on an empty List\n");
		exit(1);
    }
	temp = L->back;
	if(L->current == L->back) { L->current = NULL; }
	if(L->length == 1) { L->front = L->current = L->back = NULL; }
	else{
		L->back = L->back->previous;
		L->back->next->previous = NULL;
		L->back->next = NULL;
	}
	L->length--;
	freeNode(&temp);
}
void deleteCurrent(ListRef L){
	NodeRef N = NULL;
	if( L==NULL ){
		printf("List Error: calling deleteCurrent() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling deleteCurrent() on an empty List\n");
		exit(1);
    }
    if( offEnd(L) ){
		printf("List Error: calling deleteCurrent() on an undefined current\n");
		exit(1);
    }
	if (getIndex(L) == 0){ deleteFront(L); } 
	else if (getIndex(L) == (L->length-1)) { deleteBack(L); }
	else{
		N = L->current;
		L->current->previous->next = L->current->next;
		L->current->next->previous = L->current->previous;
		L->current->next = L->current->previous = NULL;
		L->current = NULL;
		freeNode(&N);
		L->length--;
	}
	
}
/*** Other operations ***/
 void printList(FILE* out, ListRef L){
	NodeRef temp = NULL;
	if( out==NULL ){
		printf("List Error: calling printList() on closed file\n");
		exit(1);
    }
	if( L==NULL ){
		printf("List Error: calling printList() on NULL ListRef\n");
		exit(1);
    }
	temp = L->front;
	 while(temp != NULL){
		fprintf(out, "%d", temp->data);
		if (temp->next != NULL)	{ fprintf(out," "); }
		temp = temp->next;
	} 
	fprintf(out,"\n"); 
} 
ListRef copyList(ListRef L){
	NodeRef temp = NULL;
	ListRef newL = NULL;
	if( L==NULL ){
		printf("List Error: calling copyList() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(L) ){
		printf("List Error: calling copyList() on an empty List\n");
		exit(1);
    }
	newL = newList();
	temp = L->front;
	while(temp != NULL){
		insertBack(newL, temp->data);
		temp = temp->next;
	}
	return(newL); 
}
ListRef catList(ListRef A, ListRef B){
	ListRef newL = NULL;
	NodeRef temp = NULL;
	if( A==NULL || B==NULL){
		printf("List Error: calling catList() on NULL ListRef\n");
		exit(1);
    }
    if( isEmpty(A) ||  isEmpty(B)){
		printf("List Error: calling catList() on an empty List\n");
		exit(1);
    }
	newL = copyList(A);
	temp = B->front;
	while(temp != NULL){
		insertBack(newL, temp->data);
		temp = temp->next;
	}
	return(newL);
}

