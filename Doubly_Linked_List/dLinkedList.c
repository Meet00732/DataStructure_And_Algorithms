/*
Name : Patel Kshitij A.
Roll no : 18BCP055

>>Output of InserAtFront and end
Enter data :2
Enter data :6
Enter data :8
Enter data :9
9
2
6
8

>>Output of Insertion before
Enter data :1
Enter data :2
Enter data :3
Enter data :4
Enter data before which data is to be added :2
1
4
2
3

>>Output of Delete at front
Enter data :1
Enter data :2
Enter data :3
2
3

>>Output of Delete at end
Enter data :1
Enter data :2
Enter data :3
1
2

>>Output of Deletion Of Specific data
Enter data :1
Enter data :2
Enter data :3
Enter data :4
Enter data to be deleted :2
1
3
4

>>Output of Insertion in order
Enter data :9
Enter data :8
Enter data :7
Enter data :6
6
7
8
9
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};


struct node* InsertAtEnd(struct node *root);
void display(struct node *root);
struct node* InsertAtFront(struct node *root);
struct node* InsertBefore(struct node* root);
struct node* InsertInOrder(struct node* root);
struct node* deletionAtFront(struct node *root);
struct node* deletionAtEnd(struct node *root);
struct node* deleteData(struct node *root);

void main()
{
    struct node* head;
    head = NULL;

    /*head = InsertAtEnd(head);
    head = InsertAtEnd(head);
    head = InsertAtEnd(head);
    head = InsertAtEnd(head);*/
    //head = InsertAtFront(head);
    //head = InsertBefore(head);
    head = InsertInOrder(head);
    head = InsertInOrder(head);
    head = InsertInOrder(head);
    head = InsertInOrder(head);
    //head = deletionAtFront(head);
    //head = deletionAtEnd(head);
    //head = deleteData(head);
    display(head);

}

struct node* InsertAtEnd(struct node *root)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->lptr=NULL;
    temp->rptr=NULL;
    printf("Enter data :");
    scanf("%d", &temp->data);
    if(root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->rptr != NULL)
        {
            p=p->rptr;
        }
        p->rptr=temp;
        temp->lptr=p;
        return root;
    }
}

struct node* InsertAtFront(struct node *root)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &temp->data);
    temp->lptr = NULL;
    temp->rptr = NULL;
    if(root == NULL)
    {
        root=temp;
        return root;
    }
    else
    {
        temp->rptr = root;
        root->lptr = temp;
        root = temp;
        return root;
    }
}

struct node* InsertBefore(struct node* root)
{
    struct node *temp;
    int a;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &temp->data);
    temp->lptr = NULL;
    temp->rptr = NULL;
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        printf("Enter data before which data is to be added :");
        scanf("%d", &a);
        struct node *p;
        p=root;
        while(p->rptr->data != a)
        {
            p=p->rptr;
        }
        temp->rptr=p->rptr;
        p->rptr->lptr=temp;
        temp->lptr=p;
        p->rptr=temp;
        return root;
    }
}

struct node* InsertInOrder(struct node* root)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &temp->data);
    temp->lptr = temp->rptr = NULL;
    if (root == NULL)
    {
        root=temp;
        return root;
    }
    else if(root->data > temp->data)
    {
        temp->rptr = root;
        root->lptr = temp;
        root=temp;
        return root;
    }
    else if(root->data < temp->data)
    {
        root->rptr = temp;
        temp->lptr = root;
        return root;
    }

    else
    {
        struct node *p;
        p=root;
        while(root != NULL && p->rptr->data > temp->data)
        {
            p=p->rptr;
        }
        temp->rptr = p->rptr;
        p->rptr->lptr=temp;
        temp->lptr = p;
        p->rptr = temp;
        return root;
    }

}

struct node* deletionAtFront(struct node *root)
{
    struct node *temp;
    if (root == NULL)
    {
        printf("Empty List.");
        return root;
    }
    else if((root->lptr == NULL) && (root->rptr == NULL))
    {
        temp=root;
        //printf("Empty.");
        free(temp);
        return 0;
    }

    else
    {
        temp = root;
        root=temp->rptr;
        temp->rptr->lptr=NULL;
        free(temp);
        return root;
    }

}

struct node* deletionAtEnd(struct node *root)
{
    struct node *temp, *p;
    if(root == NULL)
    {
        printf("Empty List.");
        return root;
    }
    else if((root->lptr == NULL) && (root->rptr == NULL))
    {
        temp=root;
        //printf("Empty.");
        free(temp);
        return 0;
    }
    else
    {
        p=root;
        while(p->rptr->rptr != NULL)
        {
            p=p->rptr;
        }
        temp=p->rptr;
        p->rptr=NULL;
        temp->lptr = NULL;
        return root;
    }
}

struct node* deleteData(struct node *root)
{
    struct node *p, *q, *r;
    int a;
    printf("Enter data to be deleted :");
    scanf("%d", &a);
    p=root;
    do
    {
        if(p->data == a)
            break;
        else{
            p=p->rptr;
        }
    }while(p != NULL);
    if(p==NULL){
        printf("data not found.");
    return root;}
    q=p->lptr;
    r=p->rptr;
    if(q==NULL)
    {
        deletionAtFront(root);
    }
    else if(r==NULL)
    {
        deletionAtEnd(root);
    }
    else
    {
        q->rptr=r;
        r->lptr=q;
        p->lptr=NULL;
        p->rptr=NULL;
        free(p);
        return root;

    }
}

void display(struct node *root)
{
    struct node *temp;
    temp=root;
    if(root == NULL)
    {
        printf("Empty list.");
    }
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->rptr;
    }
}
