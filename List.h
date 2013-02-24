/*
Name      : Alberto Plata
Student ID: 1291980
Assignment: pa4

*/
#if !defined(_LIST_H_INCLUDE_)
#define _LIST_H_INCLUDE_


/***************************** Exported Types *************************************/

typedef struct List * ListRef;

/************** Constructors-Destructors ******************************************/

ListRef newList(void);
void freeList(ListRef* pL);

/***************** Access functions ***********************************************/

int getLength(ListRef L);
int isEmpty(ListRef L);
int offEnd(ListRef L);
int getIndex(ListRef L);
int getFront(ListRef L);
int getBack(ListRef L);
int getCurrent(ListRef L);
int equals(ListRef A, ListRef B);

/****************************** Manipulation procedures ***************************/

void makeEmpty(ListRef L);
void moveTo(ListRef L, int i);
void movePrev(ListRef L);
void moveNext(ListRef L);
void insertFront(ListRef L, int data);
void insertBack(ListRef L, int data);
void insertBeforeCurrent(ListRef L, int data);
void insertAfterCurrent(ListRef L, int data);
void deleteFront(ListRef L);
void printLIST(ListRef L); /*8888888888888888888888888888888888888*/
void deleteBack(ListRef L);
void deleteCurrent(ListRef L);

/*************** Other Functions *************************************************/

void printList(FILE* out, ListRef L);
ListRef copyList(ListRef L);
ListRef catList(ListRef A, ListRef B);


#endif










