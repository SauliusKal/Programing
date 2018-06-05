struct list
{
    int data;
    struct list *next;
};

typedef struct list Listas;
typedef Listas* ListPtr;

ListPtr head;

void PrintList(int currnr)
{
    int i=1,a=0;
    ListPtr current;
    current = head;

    if(head != NULL)
    {

        do
        {
            printf ("[%d] - %d \n",i, current->data);
            if(current->next!=NULL)
            current = current->next;
            else
            {a=1;}
            i++;
        }
        while (a!=1);
    }
    else
        printf ("The list is empty \n");
    printf("Error);");
}

Listas* AddToEnd(int **currnr, int **maxnr)
{
    ListPtr tmp;
    int value,a=0;

    if(head==NULL)
    {
        value=rand()%3+1;
        head = (ListPtr)malloc(sizeof(Listas));
        head->data=value;
        head->next=NULL;
        a=1;
        (**currnr)++;
    }
    tmp=head;
    do
    {
        value=rand()%2+1;
        a=0;
        while(tmp->next!=NULL)
        tmp=tmp->next;
        tmp->next=(ListPtr)malloc(sizeof(Listas));
        tmp=tmp->next;
        tmp->data=value;
        tmp->next=NULL;
        (**currnr)++;
//        if(a==1)
//        {
//            printf("[%d] - ",(**currnr));
//            printf("%d\n",head->data);
//        }
//        else
//        {
//            printf("[%d] - ",(**currnr));
//            printf("%d\n",tmp->data);
//        }
    }
    while((**currnr)<(**maxnr));
    PrintList(currnr);
    printf("Error);");
}

int destroy()
{
    ListPtr current;
    ListPtr tmp;
    tmp=head;
    if(head==NULL)
    {
        printf("List not created");
    }
    else
    {
        current=tmp->next;
        tmp->next=NULL;
        while(current!=NULL)
        {
            tmp=current->next;
            free(current);
            current=tmp;
        }
        free(tmp);
        tmp=NULL;
    }

}


Listas* UseItem(int ***hp, int ***mp, int ***dmg, int ***currnr, int ***maxnr)
{
    ListPtr tmp;
    ListPtr current;
    int counter=1,value,itemid,i=1;
    int deleted=0;
    current=head;

    tmp=head;
    PrintList(currnr);
    printf("Error[%d]\n",(***currnr));
    if(current != NULL)
    {

    }
    else
        printf ("The list is empty \n");
    printf ("\n");

    printf("Which item do you want to use?\n(-1 to back)\n\n");
    do
    {
        scanf("%d",&value);
    }
    while(value<0 && value>9);

    if(value==-1);
    else if(value==1)
    {
        itemid=tmp->data;
        head=tmp->next;
        free(tmp);
    }
    else
    {

        if(tmp != NULL)
        {
            while (tmp!=NULL&&deleted!=1)
            {
                itemid=tmp->data;
                current=tmp;
                tmp=tmp->next;
                counter++;
                if(value==counter)
                    {
                        current->next=tmp->next;
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
    (***currnr)--;

//    if(itemid==1)Player->HP+=rand()%100+500;
//    else if(itemid==2)Player->MP+=rand()%25+75;
//    else if(itemid==3)Player->DMG=rand()%300+300
}

int ItemsPage(int **hp, int **mp, int **dmg, int **currnr, int **maxnr)
{
    int choice;
    ListPtr current;
    head=NULL;

    int a = 1,i=1,value=0,where=0;

    while(a == 1)
    {
        system("cls");
        PrintList(currnr);
        printf("What do you want to do?\n\n\n");
        printf("[1] - Use an item;\n");
        printf("[0] - Back to the fight;\n");
        do
        {
            scanf("%d", &choice);
            if(choice==0)break;
        }
        while(choice!=1);
        printf("\n");
        if(choice==0)break;
        else if(choice == 1)
        {
            ListPtr current;
            current = head;
            if((*currnr)>0)
            {
            printf ("\n");
            system("cls");
            head=UseItem(&**hp,&**dmg,&**mp,&**currnr,&**maxnr);
            }
            else
            {
                printf("\n\nThe bag is emty.[%d]\n\n",**currnr);
                system("pause");
            }
        }
        printf("\n");
    }
}

int itemstart(int id,int *hp, int *mp, int *dmg, int *currnr, int *maxnr)
{
    ListPtr head;
    if(id==1)ItemsPage(&(*hp),&(*mp),&(*dmg),&(*currnr),&(*maxnr));
    if(id==2)AddToEnd(&*currnr,&*maxnr);
    return currnr;
}

int TheEnd()
{
    destroy();
    head=NULL;
}
