/*
Name - Patel Kshitij A.
Roll No - 18BCP055

>>Output of insert at front and end
Enter data :1
Enter data :2
Enter data :3
Enter data :4
4
1
2
3


>>Output of insertion after a specific node
Enter data :1
Enter data :2
Enter data :3
Enter data after which new data is to be added :2
Enter number to be added :5
1
2
5
3

>>Output of Deletion At Head
Enter data :1
Enter data :2
Enter data :3
2
3

>>Output of Deletion of a specific node with value v
Enter data :1
Enter data :2
Enter data :3
Enter data to be deleted :2
1
3

>>Output of Deletion at End
Enter data :1
Enter data :2
Enter data :3
1
2

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

struct node* append(struct node* r);
void  display(struct node *root);
struct node* addAtFront(struct node* root);
struct node* addAfter(struct node *root);
int length(struct node *root);
struct node* insertionInOrder(struct node *root);
struct node* deleteAtFront(struct node *root);
struct node* deleteData(struct node *root);
struct node* deleteAtEnd(struct node *root);

void main()
{
    struct node *Head;
    Head=NULL;
    Head = append(Head);
    Head = append(Head);
    Head = append(Head);
    //Head = deleteAtFront(Head);
    //Head = addAtFront(Head);
    //Head = addAfter(Head);
    Head = deleteAtEnd(Head);
    display(Head);
    printf("\n\n\n");


    /*Head=NULL;
    Head = append(Head);
    Head = append(Head);
    Head = append(Head);
    Head = addAtFront(Head);
    Head = addAfter(Head);
    Head = deleteAtFront(Head);
    display(Head);*/

    /*Head = insertionInOrder(Head);
    Head = insertionInOrder(Head);
    Head = insertionInOrder(Head);
    display(Head);*/
}

struct node* append(struct node *root)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &temp->data);
    temp -> ptr = NULL;
    if(root == NULL){
        return temp;
    }
    struct node *p;
    p = root;
    while(p -> ptr != NULL)
    {
        p = p -> ptr;
    }
    p -> ptr = temp;
    return root;
}

struct node* addAtFront(struct node* root)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &temp->data);
    temp->ptr=NULL;
    if(root == NULL)
    {
        root=temp;
        return root;
    }
    else
    {
        temp->ptr = root;
        root = temp;
        return root;
    }
}

struct node* addAfter(struct node *root)
{
    struct node *temp, *p;
    p = (struct node*)malloc(sizeof(struct node));
    p=root;
    temp = (struct node*)malloc(sizeof(struct node));
    int loc, i=1, a;
    loc = length(root);
    printf("Enter data after which new data is to be added :");
    scanf("%d", &a);
    while(p->data != a)
    {
        p = p->ptr;
    }
    if(p->data == a)
    {
        printf("Enter number to be added :");
        scanf("%d", &temp->data );
        temp->ptr = p->ptr;
        p->ptr = temp;
        return root;
    }
    /*else
    {
        printf("Data doesn't exist.");
        return 0;
    }*/
}

int length(struct node *root)
{
    struct node *temp;
    temp=root;
    int count=0;
    if (root == NULL)
    {
        printf("List is Empty.");
        return 0;

    }
    else
    {
        while(temp != NULL)
        {
            count++;
            temp = temp->ptr;
        }
        return count;

    }

}

struct node* insertionInOrder(struct node *root)
{
    struct node *temp, *p;
    int a;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter a Number at be added :");
    scanf("%d", &a);
    temp -> data = a;
    if (root == NULL || a < root -> data)
    {
        temp->ptr = root;
        root = temp;
        return root;
    }
    p=root;
    while (p -> ptr != NULL && p->ptr->data < a)
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

struct node* deleteData(struct node *root)
{
    struct node *temp, *p;
    int a;
    printf("Enter data to be deleted :");
    scanf("%d", &a);
    if (root == NULL)
    {
        printf("List is Empty.");
        return root;

    }
    else
    {
        p=root;
        while (p->ptr->data != a)
        {
            p=p->ptr;
        }
        temp = p->ptr;
        p->ptr=temp->ptr;
        temp->ptr = NULL;
        free(temp);
        return root;
    }
}

struct node* deleteAtEnd(struct node *root)
{
    struct node *temp, *p;
    p=root;
    if(root == NULL)
    {
        printf("List is empty.");
        return root;
    }
    while (p->ptr->ptr != NULL)
    {
        p=p->ptr;
    }
    temp = p->ptr;
    p->ptr = temp->ptr;
    temp->ptr = NULL;
    free(temp);
    return root;

}


void  display(struct node *root)
{
    struct node *temp;
    temp=root;
    if(temp == NULL)
    {
        printf("List is Empty.\n");
    }
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->ptr;
    }
}
