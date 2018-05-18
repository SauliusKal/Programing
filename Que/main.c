#include <stdio.h>
#include <stdlib.h>

void AddToQue(int *Que,int *start,int *end,int QueSize,int *ammount)
{
    int number;
    system("cls");
    if((*ammount)==QueSize)
    {
        printf("Que is full\n");
        system("pause");
    }
    else
    {
        printf("Write the number to add:\n\n");
        scanf("%d",&number);
        if((*start)==-1&&(*end)==-1)
        {
            (*start)=0;
            Que[(*start)]=number;
            (*end)=1;
            (*ammount)+=1;
        }
        else
        {
            if(*end<QueSize&&*start==0)
            {
                Que[(*end)]=number;
                (*end)++;
                (*ammount)+=1;
            }
            else
            if(((*end)+1)==QueSize)
            {
                Que[(*end)]=number;
                (*end)=0;
                (*ammount)+=1;
            }
        }
    }
}

void DeleteFromQue(int *Que,int *start,int *end,int QueSize,int *ammount)
{
    if(ammount==0)
    {
        (*end)=-1;
        (*start)=(*end);
    }
    else
        if((*start)<QueSize&&(*ammount)>0)
        {
            (*start)++;
            (*ammount)-=1;
        }
        else
        if(ammount>0&&(*start)==QueSize)
        {
            (*start)=0;
            (*ammount)-=1;
        }
}

void ShowQue(int *Que,int *start,int *end,int ammount,int QueSize)
{
    system("cls");
    int i=0;
    if(ammount==0)
    {
        printf("Que is empty.\n");
    }
    else
    for(i;i<ammount;i++)
    {
        if(*start==0)
        {
            printf("%d ",Que[i]);
        }
        else
        if((*start)<QueSize&&(*end)>(*start))
        printf("%d ",Que[i+(*start)]);
        else
        if((*start)<QueSize&&(*end)<(*start)||(*start)<QueSize&&(*end)==(*start))
        if((i+(*start))<=QueSize)
        printf("%d ",Que[i+(*start)]);
        else if((*end)!=0&&(i+(*start))<=QueSize)
        printf("%d ",Que[ammount-i]);
    }
    printf("\n");
    system("pause");
}

void printall(int *Que,int QueSize)
{
    int i=0;
    do
    {
        printf("\n--%d: %d--",i,Que[i]);
        i++;
    }
    while(i<QueSize);
}

void main()
{
    int choice,start=-1,end=-1,QueSize=5,ammount=0;
    int Que[QueSize];
    do
    {
        system("cls");
        printf("Que size - %d\n\nWhat do you want to do?:\n---------\n",ammount);
        printall(Que,ammount);
        printf("\n[1]-Add a digit.\n[2]-Remove a digit.\n[3]-Show the Que.\n[4]-Exit.\n\n");
        scanf("%d",&choice);
        printall(&Que,QueSize);
        switch(choice)
        {
        case 1:
            AddToQue(&Que,&start,&end,QueSize,&ammount);
            break;
        case 2:
            DeleteFromQue(&Que,&start,&end,QueSize,&ammount);
            break;
        case 3:
            ShowQue(Que,&start,&end,&ammount,QueSize);
            break;
        case 4:
            exit(1);
        default:
            break;
        }
    }
    while(1);
}
