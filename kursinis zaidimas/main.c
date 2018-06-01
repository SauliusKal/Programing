#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct charinfo
{
    int HP;
    int MaxHP;
    int DMG;
    int MP;
    int MaxMP;
}Enemy,Player;

#include "list gen.c"

void Delay(int number_of_seconds)
{
    int milli_seconds = 0 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int attack()
{
    Player.DMG=rand() % 30 + 70;
    Player.DMG=Player.DMG * (rand() % 6 + 4);
}

int magic(int *currnr, int *maxnr)
{
    int choice;
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
        case 4: itemstart(2,&Player.HP,&Player.MP,&Player.DMG,&currnr,&maxnr);Player.MP-=10;break;
        case 0: break;
    }
}

int defend()
{

}

//int intro()
//{
//    printf("You are a Red mage - a fighter who can use some magic.\n");
//    Delay(3);
//    printf("You stumbled across a dungeon, and decided to loot it.\n");
//    printf("According to your intuition about three hours have passed since you entered, but knowing that you are wrong most of the time, its possible that somewhere from 10 min to a couple of days has passed.\n");
//    Delay(3);
//    printf("Finally, you are standing in front of a giant door, but suddenly you are smacked from the back and smash in too the door.\n");
//    Delay(3);
//    printf("Once you manage to stand up, you see a huge troll running towards you.\n");
//    Delay(3);
//    printf("You doge the huge monster and a fight begins.\n");
//    printf("\n");
//    Delay(3);
//
//    system("pause");
//    system("cls");
//
//    printf("A simple tutorial:\n");
//    printf("\n");
//    Delay(3);
//    printf("Attack - use your sword to slash at the troll. Has a chance to do multiple hits, up to 10\n");
//    Delay(3);
//    printf("Magic:\n");
//    printf("Fire - deals consistent\n");
//    printf("Lightning - can deal some huge damage, but is inconsistent\n");
//    printf("Cure - restores health\n");
//    printf("Magic bag - fills your bag with 9 random items\n\n");
//    printf("Defense: lovers the damage taken\nItem: use an item from your bag\n");
//    printf("\n");
//    Delay(3);
//
//    system("pause");
//    system("cls");
//}

int main()
{
    int choice=0,currnr=0,maxnr=5;
    time_t t;
    srand((unsigned) time(&t));
    Enemy.HP=Enemy.MaxHP=35241;
    Enemy.DMG=0;
    Enemy.MP=400;
    Player.HP=2027;
    Player.MaxHP=3500;
    Player.DMG=0;
    Player.MP=347;
    Player.MaxMP=500;
//    intro();

    do
    {
        printf("Troll - %d/%d\n",Enemy.HP,Enemy.MaxHP);
        printf("You - HP%d/%d MP%d/%d",Player.HP,Player.MaxHP,Player.MP,Player.MaxMP);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("[1] Attack\n[2] Magic\n[3] Defense\n[4] Items\n\n[0] Exit\n");
        do
        {
            scanf("%d",&choice);
        }
        while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=0);
        switch(choice)
        {
            case 0:exit(1);
            case 1:system("cls");attack();break;
            case 2:system("cls");magic(&currnr,&maxnr);break;
            case 3:system("cls");defend();break;
            case 4:system("cls");itemstart(1,&Player.HP,&Player.MP,&Player.DMG,&currnr,&maxnr);break;
        }
        Player.HP-=Enemy.DMG;
        Enemy.HP-=Player.DMG;
        printf("You dealt %d points of damage.\n\nTroll hit you for %d points of damage.\n\n",Player.DMG,Enemy.DMG);
        system("pause");
        system("cls");
    }
    while(Enemy.HP>0&&Player.HP>0&&choice!=-1);
    TheEnd();

    return 0;
}
