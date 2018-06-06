#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct CharInfo
{
    int HP;
    int MaxHP;
    int MaxMP;
    int MP;
    int DMG;
}Enemy,Player;

struct ItemData
{
    int CurrentAmount;
    int MaxAmount;
    int ID;
}item;

struct list {
    int data;
    struct list *next;
};

typedef struct list Listas;
typedef Listas* ListPtr;


void Delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int intro()
{
    printf("You are a Red mage - a fighter who can use some magic.\n");
    Delay(3);
    printf("You stumbled across a dungeon, and decided to loot it.\n");
    Delay(3);
    printf("You guess that about three hours have passed since you entered, but knowing your sense of  time, probably much more ...\n");
    Delay(5);
    printf("Finally, you are standing in front of a giant door, but suddenly you are smacked from the back and smash in too it.\n");
    Delay(5);
    printf("Once you manage to stand up, you see a huge troll running towards you.\n");
    Delay(3);
    printf("You dodge the huge monster and a fight begins.\n");
    printf("\n");
    Delay(6);

    system("cls");

    printf("A simple tutorial:\n");
    printf("\n");
    Delay(4);
    printf("Attack - use your sword to slash at the troll. Has a chance to do multiple hits\n");
    Delay(2);
    printf("Magic:\n");
    Delay(2);
    printf("Fire - deals consistent\n");
    Delay(1);
    printf("Lightning - can deal some huge damage, but is inconsistent\n");
    Delay(1);
    printf("Cure - restores health\n");
    Delay(1);
    printf("Magic bag - fills your bag with 8 random items\n\n");
    Delay(2);
    printf("Defense: lovers the damage taken\n");
    Delay(2);
    printf("Item:\n");
    Delay(2);
    printf("Healing potion - heals you\n");
    Delay(1);
    printf("Mana potion - restores your mana\n");
    Delay(1);
    printf("A bomb - Deals huge damage to you enemys\n");
    printf("\n");
    Delay(20);
    system("cls");
    printf("Good luck...");
    system("pause");
    system("cls");
}

Listas* AddToEnd(ListPtr head)
{
    ListPtr tmp;
    if(item.CurrentAmount<item.MaxAmount)
    do
    if(head==NULL)
    {
        head = (ListPtr)malloc(sizeof(Listas));
        head->data=rand()%120+1;
        head->next=NULL;
        item.CurrentAmount++;
    }
    else
    {
        tmp=head;
        while(tmp->next!=NULL)
        tmp=tmp->next;

        tmp->next=(ListPtr)malloc(sizeof(Listas));
        if(tmp->next==NULL)
        {
        exit(0);
        }
        tmp=tmp->next;
        tmp->data=rand()%120+1;
        tmp->next=NULL;
        item.CurrentAmount++;
    }
    while(item.CurrentAmount<item.MaxAmount);
    item.CurrentAmount--;
    return head;
}

void destroy(struct list *head)
{
    struct list *current, *tmp;
    if(head==NULL)
    {
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

void PrintList(ListPtr head)
{
    system("cls");
    int i=1;
    ListPtr current;
    current = head;

    if(current != NULL)
    {

        do
        {
            if(current->data>0&&current->data<=40)
            printf ("[%d] - Healing potion \n",i);
            else if(current->data>40&&current->data<=80)
            printf ("[%d] - Mana potion \n",i);
            else
            printf ("[%d] - A bomb \n",i);
            current = current->next;
            i++;
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

    printf ("\n");
    if(value<1)
    {
        printf("Selected item does not exist\n");
    }
    else if(value==1)
    {
        item.ID=tmp->data;
        head=tmp->next;
        free(tmp);
        item.CurrentAmount--;
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
                    item.ID=tmp->data;
                    free(tmp);
                    deleted = 1;
                    item.CurrentAmount--;
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

int main()
{
    ListPtr head;
    item.MaxAmount=8;
    item.CurrentAmount=0;
    head=NULL;
    time_t t;
    srand((unsigned) time(&t));
    Enemy.HP=Enemy.MaxHP=35241;
    Enemy.MP=400;
    Player.HP=2027;
    Player.MaxHP=3500;
    Player.MP=347;
    Player.MaxMP=500;
    int huh;

    printf("Do you want an introduction?\nY-[1]\nN-[0]\n\n");
    scanf("%d",&huh);
    system("cls");
    if(huh==1)intro();

    int aformition = 1;
    int choice = 0;
    int rnd;
    int value=0;
    int where=0;
    int WTD=-1;
    do
    {
        Enemy.DMG=0;
        Player.DMG=0;
        Enemy.DMG+=rand()%150+200;
        system("cls");
        printf("Troll - %d/%d\n",Enemy.HP,Enemy.MaxHP);
        printf("You - HP%d/%d MP%d/%d",Player.HP,Player.MaxHP,Player.MP,Player.MaxMP);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("[1] Attack\n[2] Magic\n[3] Defense\n[4] Items\n\n[0] Exit\n");
        do
        {
            scanf("%d",&WTD);
        }
        while(WTD!=1&&WTD!=2&&WTD!=3&&WTD!=4&&WTD!=0);
        if(WTD==1)
        {
            rnd=rand()%5+2;
            for(int i=1;i<=rnd;i++)
            Player.DMG+=rand()%25+30;
        }
        else if(WTD==2)
        {
            system("cls");
            printf("[1] Fire - 20mp\n[2] Lightning - 40mp\n[3] Cure - 25mp\n[4] Magic bag - 10mp\n\n[0] <- Back\n");
            do
            {
                scanf("%d",&choice);
            }
            while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=0);

            switch(choice)
            {
                case 1: Player.DMG= rand() % 200 + 200;Player.MP-=20;break;
                case 2: Player.DMG= rand() % 600 + 100;Player.MP-=40;break;
                case 3: Player.HP+= rand() % 300 + 200;Player.MP-=25;break;
                case 4: system("cls");head=AddToEnd(head);PrintList(head);system("pause");break;
                case 0: break;
            }
            system("cls");
        }
        else if(WTD==3)
        {
            Enemy.DMG-=rand()%100+100;
        }
        else if(WTD==0)
        break;
        else if(WTD == 4)
        {
            system("cls");
            printf("What do you want to do?\n\n\n");
            printf("[1] - Use item\n");
            printf("[0] - Back\n\n");
            scanf("%d", &choice);
            printf("\n");

            if(choice == 0);
            else if(choice == 1)
            {
                ListPtr current;
                current = head;
                int i=1;
                if(head!=NULL)
                {
                    PrintList(head);
                    printf ("\n");
                    printf("Which item do you want to use?\n");
                    scanf("%d",&value);
                    head=del(head,value);
                    if(item.ID>0&&item.ID<=40)Player.HP+=rand()%200+200;
                    else if(item.ID>40&&item.ID<=80)Player.MP+=rand()%100+100;
                    else Player.DMG=rand()%500+500;
                }
                else
                {
                    printf("\n\nList does not exist.\n\n");
                    system("pause");
                }
            }
            printf("\n");
        }
        Player.HP-=Enemy.DMG;
        Enemy.HP-=Player.DMG;
        printf("You dealt %d points of damage.\n\nTroll hit you for %d points of damage.\n\n",Player.DMG,Enemy.DMG);
        system("pause");
        system("cls");
    }
    while(Enemy.HP>0&&Player.HP>0);
    if(Player.HP<=0)printf("You have met with a horrible faith, haven't you...\n\n");
    if(Enemy.HP<=0)printf("You have killed the monster, but still fell to the wounds that it did to you.\n\nBefore dying tho, you managed to walk trough the huge door... and what you found was a library... that seems to have been burned to the ground.\n\nCongratulations on Winning, kinda, in a way... look, i have no time to fully finish this little game -_-;\nI'm happy that i managed to do this much.\n\nTnx for playing ^^\n");
    destroy(head);
    head=NULL;

    return 0;
}
