/*
Name - Patel Kshitij A.
Roll No - 18BCP055

>>Output of insert at front and end
30
20
10
40
50

>>Output of insertion after a specific node
30
20
27
10

>>Output of Deletion At Head
20
10

>>Output of Deletion of a specific node with value v
30
20

>>Output of Deletion at End
30
20

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* ptr;
};

struct node* InsertAtFront(struct node* h,int v);
struct node* InsertAtEnd(struct node* h,int value);
struct node* InsertInOrder(struct node *root, int a);
struct node* deleteAtFront(struct node *root);
struct node* deleteFromFront(struct node* h);
struct node* deletevalue(struct node* h,int val);
struct node* deleteFromEnd(struct node* h);
struct node * insertAfter(struct node* H,int x,int y);
void traverse(struct node* h);

void main()
{
    struct node* head = NULL;

    head = InsertAtFront(head,10);
    head = InsertAtFront(head,20);
    head = InsertAtFront(head,30);
    //head = InsertAtEnd(head,40);
    //head = InsertAtEnd(head,50);

    //head = InsertInOrder(head,30);
    //head = InsertInOrder(head,50);
    //head = InsertInOrder(head,40);
    //head = deleteFromFront(head);
    //head = deleteFromEnd(head);
    head = deletevalue(head,10);
    //head = insertAfter(head,20,27);
    traverse(head);

}

struct node* InsertAtFront(struct node* h,int v)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode -> val = v;
    newnode -> ptr = h;
    return newnode;

}
struct node* InsertAtEnd(struct node* h,int value)
{

    struct node* newnode,*temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> val = value;
    newnode -> ptr = NULL;

    if(h==NULL)
    {
        return newnode;
    }
    temp=h;
    while(temp -> ptr != NULL)
    {
        temp=temp->ptr;
    }
    temp->ptr = newnode;
    return h;
}



struct node* InsertInOrder(struct node *root, int a)
{
    struct node *temp, *p;

    temp = (struct node*)malloc(sizeof(struct node));

    temp -> val=a;
    if (root == NULL || a < root -> val)
    {
        temp->ptr = root;
        root = temp;
        return root;
    }
    p=root;
    while (p -> ptr != NULL && p->ptr->val < a)
    {
        p=p->ptr;
    }
    temp->ptr = p->ptr;
    p->ptr = temp;
    return root;
}

struct node* deleteAtFront(struct node *root)
{
    struct node *temp;
    if(root == NULL)
    {
        printf("List is Empty.");
        return root;
    }
    else
    {
        temp = root;
        root = temp->ptr;
        temp->ptr = NULL;
        free(temp);
        return root;
    }
}


struct node* deleteFromFront(struct node* h)
{
    struct node* temp;

    if(h==NULL)
    {
        printf("The list is already empty.");
        return h;
    }
    temp = h;
    h = h->ptr;
    free(temp);
    return h;
}

struct node* deletevalue(struct node* h,int val)
{
    struct node* temp1;
     struct node* temp2;
    int value;
    value = val;

    if(h==NULL)
    {
        printf("The list is already empty.");
        return h;
    }
    if(h->val==value)
    {
        temp1= h->ptr;
        free(h);
        return temp1;
    }
    temp1=h;
    while(temp1->ptr->val != value)
    {
        temp1=temp1->ptr;
    }
    temp2=temp1->ptr->ptr;
    free(temp1->ptr);
    temp1->ptr = temp2;
    return h;
}

struct node* deleteFromEnd(struct node* h)
{
    struct node * temp;
    if(h==NULL)
    {
        printf("The list is already empty.");
        return h;
    }
    if(h->ptr==NULL)
    {
        free(h);
        return NULL;
    }

    temp=h;
    while(temp->ptr->ptr !=NULL)
    {
        temp = temp->ptr;
    }

    free(temp->ptr);
    temp->ptr=NULL;
    return h;

}


struct node * insertAfter(struct node* H,int x,int y)

{
	struct node* newnode,*temp;

	newnode = (struct node*)malloc(sizeof(struct node));

	if(newnode==NULL)

	{
		perror("malloc");
		exit(-1);
	}

	newnode->val=y;

	if(H==NULL)
	{
		printf("empty");
		return H;
	}

	temp=H;

	while(temp->val != x)
	{
		temp=temp->ptr;
     }
     newnode->ptr=temp->ptr;
	temp->ptr=newnode;

	return H;

}
void traverse(struct node* h)
{
    struct node* temp;
    temp = h;
    while(temp != NULL)
    {
        printf("%d\n",temp->val);
        temp=temp->ptr;
    }
}


