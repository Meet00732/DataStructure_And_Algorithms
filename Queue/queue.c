/*NAME: Kshitij Patel
ROLL NO: 18BCP055*/
#include <stdio.h>
#include <stdlib.h>
#define N 10
void qInsert(int Q[], int *f, int *r, int val);
void display(int queue[], int front, int rear);
int qDelete(int Q[], int *f, int *r);
void main()
{
	// ini queue
	int queue[N];
	int front, rear;
	int val;
	/*front = first element in queue
	  rear = last element in queue*/
	front =-1;
	rear =-1;
	qInsert(queue,&front,&rear,10);
	qInsert(queue,&front,&rear,20);
	qInsert(queue,&front,&rear,30);
	display(queue,front,rear);
	printf("\n\n\n");
	qDelete(queue,&front,&rear);
	/*qDelete(queue,&front,&rear);
	qDelete(queue,&front,&rear);
	qDelete(queue,&front,&rear);*/
	display(queue,front,rear);
}

void qInsert(int Q[], int *f, int *r, int val)
{
	if (*r==N-1)
	{
		printf("Queue full.\n");
		return;
	}
	(*r)++;
	Q[*r] = val;

	if(*f==-1){
		(*f)=0;}
	return;
}

void display(int queue[], int front, int rear)
{
	int i;
	if (front==-1){
		printf("\n");}
	else{
	for (i=front; i<=rear;i++)
	{
		printf("%d\n", queue[i]);
	}}
}

int qDelete(int Q[], int *f, int *r)
{
	if (*f == -1)
	{
		printf("Queue Empty.\n");
		return 0;
	}
	int val;
	val= Q[*f];
	if (*f==*r)
	{
		*f=*r=-1;
	}
	else{
	(*f)+=1;}
	return val;

}
/*10
20
30



20
30

Process returned 3 (0x3)   execution time : 0.069 s
Press any key to continue.*/

