/* CIRCULAR QUEUE

NAME: Kshitij Patel
ROLL NO: 18BCP055
*/

#include<stdio.h>
#include<stdlib.h>
#define n 4

void qinsert(int q[], int* f, int* r, int v)
{
	if(((*r)+1)%n == *f)
	{
		printf("QUEUE IS FULL");
		return;
	}
	(*r)=((*r)+1)%n;
	q[*r]=v;

	if (*f == -1)
		(*f) = 0;
}

void qdisplay(int q[], int f, int r)
{
	int i;
	if(f == -1)
		return;
	else
	for(i=f; i<=r; i++)
	printf("%d\n", q[i]);
}

void qdelete(int q[], int *f, int *r)
{
	int a;
	if (*f==-1)
	{
		printf("QUEUE IS EMPTY");
		return -1;
	}
	else if (*f == *r)
	{
		a = q[*r];
		(*r)=-1;
		(*f)=-1;
	}
	else
	{
		a = q[*f];
		*f = (*f+1)%n;
	}
	return a;
}

int main()
{
	int queue[n];
	int front, rear;
	int val;
	front = -1;
	rear = -1;
	qinsert(queue, &front, &rear, 10);
	qdelete(queue, &front, &rear);
	qinsert(queue, &front, &rear, 20);
	qinsert(queue, &front, &rear, 30);
	qdelete(queue, &front, &rear);
	qdelete(queue, &front, &rear);
	qinsert(queue, &front, &rear, 40);
	qinsert(queue, &front, &rear, 50);
	qdisplay(queue, front, rear);
}

/*
40
50
*/


