/*
Name      : Alberto Plata
Student ID: 1291980
Assignment: pa4

*/
#include<stdio.h>
#include"List.h"

int main(int argc, char* argv[])
{
    int i;
    ListRef A = newList();
    ListRef B = newList();
	ListRef ACopy = NULL;
	ListRef AB_Cat = NULL;
	insertBack(A, 10);
	insertBack(A, 20);
	insertBack(A, 30);
	insertBack(A, 40);
	insertBack(A, 50);
	insertBack(A, 60);
	printf("equals(A,B)		: %d\n", equals(A, B));
	insertBack(B, 10);
	insertBack(B, 20);
	insertBack(B, 30);
	insertBack(B, 40);
	insertBack(B, 50);
	insertBack(B, 60);
	AB_Cat = catList(A, B);
	printf("printLIST(AB_Cat)	: ");
	printLIST(AB_Cat);
	ACopy = copyList(A);
	printf("printLIST(A)		: ");
	printLIST(A);
	printf("printLIST(ACopy)	: ");
	printLIST(ACopy);
	printf("equals(A,ACopy)		: %d\n", equals(A, ACopy));
	printf("equals(A,B)		: %d\n", equals(A, B));
	printf("printLIST(A)		: ");
	printLIST(A);
	moveTo(A, getLength(A));
	printf("offEnd(A)		: %d\n", offEnd(A));
	moveTo(A, 3);
	insertBeforeCurrent(A, 35);
	insertAfterCurrent(A, 45);
	printf("printLIST(A)		: ");
	printLIST(A);
	printf("getCurrent(A)		: %d\n", getCurrent(A));
	movePrev(A);
	printf("getCurrent(A)		: %d\n", getCurrent(A));
	deleteCurrent(A);
	printf("printLIST(A)		: ");
	printLIST(A);
	makeEmpty(B);
	deleteFront(A);
	printf("printLIST(A)		: ");
	printLIST(A);
	printf("getLength(A)		: %d\n", getLength(A));
	printf("isEmpty(A)		: %d\n", isEmpty(A));
	makeEmpty(A);
	printf("isEmpty(A)		: %d\n", isEmpty(A));
	printf("getLength(A)		: %d\n", getLength(A));
	/* printf("printLIST(A)		: ");
	printLIST(A); */
	insertFront(B, 50);
	insertBack(B, 60);
	insertFront(B, 40);
	insertBack(B, 70);
	insertFront(B, 30);
	insertBack(B, 80);
	insertFront(B, 20);
	insertBack(B, 90);
	insertFront(B, 10);
	printf("printLIST(B)		: ");
	printLIST(B);
	printf("offEnd(B)		: %d\n", offEnd(B));
	moveTo(B, 5);
	printf("offEnd(B)		: %d\n", offEnd(B));
	printf("getCurrent(B)		: %d\n", getCurrent(B));
	deleteCurrent(B);
	printf("printLIST(B)		: ");
	printLIST(B);
	/* printf("getCurrent(B) 	: %d\n", getCurrent(B));*/
	moveTo(B, 0);
	printf("getFront(B)		: %d\n", getFront(B));
	printf("getCurrent(B)		: %d\n", getCurrent(B));
	deleteFront(B);
	printf("printLIST(B)		: ");
	printLIST(B);
	printf("getFront(B)		: %d\n", getFront(B));
	/* printf("getCurrent(B)		: %d\n", getCurrent(B)); */
	moveTo(B, (getLength(B)-1));
	printf("getCurrent(B)		: %d\n", getCurrent(B));
	printf("getBack(B)		: %d\n", getBack(B));
	deleteBack(B);
	printf("getBack(B)		: %d\n", getBack(B));
	/* printf("getCurrent(B)		: %d\n", getCurrent(B)); */
	moveTo(B, (getLength(B)-1));
	printf("getCurrent(B)		: %d\n", getCurrent(B));
	printf("getBack(B)		: %d\n", getBack(B));
	deleteBack(B);
	printf("getBack(B)		: %d\n", getBack(B));
	printf("getCurrent(B)		: %d\n", getCurrent(B)); 
	
	
	
    return(0);
}
