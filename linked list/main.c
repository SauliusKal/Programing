#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

typedef struct list Listas;
typedef Listas * ListPtr;

Listas* AddToEnd(ListPtr head, int value)
{
    ListPtr tmp;
    printf("entered add to end\n");

    if(head==NULL)
{
    printf("entered 1st if\n");
    head = (ListPtr)malloc(sizeof(Listas));
    head->data=value;
    head->next=NULL;

    if(head==NULL)
    {
        printf("Error assigning memory.");
        exit(0);
    }
}
else
{
    printf("entered else\n");
    tmp=head;
    while(tmp->next!=NULL)
    tmp=tmp->next;

    tmp->next=(ListPtr)malloc(sizeof(Listas));
    if(tmp->next==NULL)
    {
    printf("Error");
    exit(0);
    }
    tmp=tmp->next;
    tmp->data=value;
    tmp->next=NULL;
}
return head;
}

void destroy(struct list *head)
{
struct list *current, *tmp;
if(head==NULL)
{
    printf("List not created");
}
else{
current=head->next;
head->next=NULL;
while(current!=NULL){
tmp=current->next;
free(current);
current=tmp;
}
free(head);
head=NULL;
}

}

void AddToCurrent(ListPtr head, int value, int where)
{
    //Done !!!
    ListPtr newNode;
    ListPtr current;
    int length = 1;
    int inserted = 0;

    current = head;

    if(current != NULL)
    {
        while (current!=NULL)
        {
            length++;
            if(length == where)
            {
                newNode = (ListPtr)malloc(sizeof(Listas));
                newNode->data = value;
                newNode->next = current->next;
                current->next = newNode;
                inserted = 1;
            }
            current = current->next;
        }

        printf ("\n");

        if(inserted == 0)
        {
            printf ("Could not insert - list too short\n");
        }
    }
    else
    printf ("The list is empty \n");

}

Listas* AddToStart(Listas *head, int value)
{
    //done !!!
    ListPtr newNode;
    ListPtr tmp;

    if(head==NULL)
{
    head=(ListPtr)malloc(sizeof(Listas));
    head->data=value;
    head->next=NULL;

if(head==NULL)
{
printf("Error.");
exit(0);
}
}

else
    {
        tmp=head;
        newNode = (ListPtr)malloc(sizeof(Listas));
        newNode->data = value;
        newNode->next = tmp;
        head=newNode;
        if(head==NULL)
        {
        printf("Error missing head pointer");
        exit(0);
        }
    }
    return head;
}

void PrintList(ListPtr head)
{

    ListPtr current;
    current = head;

    if(current != NULL)
    {
        printf ("\n------------------\n");

        do
        {
            printf ("%d ", current->data);
            current = current->next;
        }
        while (current != NULL);

            printf ("\n");
    }
    else
        printf ("The list is empty \n");
}

Listas* del(ListPtr head, int value)
{
    ListPtr tmp;
    ListPtr curr;
    int counter=1;
    int deleted=0;

    tmp=head;

    if(value<1)
    {
        printf("Selected element does not exist\n");
    }
    else if(value==1)
    {
        head=tmp->next;
        free(tmp);
    }
    else
    {

        if(tmp != NULL)
    {
        while (tmp!=NULL&&deleted!=1)
        {
            curr=tmp;
            tmp=tmp->next;
            counter++;
            if(value==counter)
                {
                    curr->next=tmp->next;
                    free(tmp);
                    deleted = 1;
                }
        }

        printf ("\n");

        if(deleted == 0)
        {
            printf ("Could not insert - list too short\n");
        }
    }
    else
    printf ("The list is already empty \n");

    }

    return head;
}

void main()
{
    ListPtr head;
    head=NULL;

    int a = 1;
    int choice = 0;
    int value=0;
    int where=0;

    while(a == 1)
    {
        printf("- What do you want to do? -");
        printf("\nAdd to start -> 1");
        printf("\nAdd to selected field -> 2");
        printf("\nAdd to end -> 3");
        printf("\nPrint List -> 4");
        printf("\nQuit -> 5");
        printf("\nDelete list -> 6");
        printf("\nDelete element -> 7");
        printf("\n");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 5)
            break;

        if(choice == 1)
        {
            printf("Write a value to add\n");
            scanf("%d", &value);
           head=AddToStart(head,value);
        }
        else if(choice == 2)
        {
            if(head!=0)
            {
            PrintList(head);
            do{
            printf("Where to add?\n");
            scanf("%d", &where);
            if(where<=1)
                printf("Cannot insert there, select field in the middle or list.\n");

            }while(where<=1);
            printf("Write a value to add\n");
            scanf("%d", &value);
            AddToCurrent(head, value, where);
            }
            else
                printf("List is empty\n");
        }
        else if(choice == 3)
        {
            printf("Write a value to add\n");
            scanf("%d", &value);
            head = AddToEnd(head,value);
        }
        else if(choice == 4)
        {
            PrintList(head);
        }
        else if(choice == 6)
        {
            destroy(head);
            head=NULL;
        }
        else if(choice == 7)
        {
            printf("Write a position to delete\n");
            scanf("%d", &value);
            head=del(head,value);
        }
        printf("\n");
    }
}
