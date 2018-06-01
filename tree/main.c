#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct data
{
    int data;
    struct data* left;
    struct data* right;
};

typedef struct data node;

node* createNode(int n)
{
    node* nnode;
    nnode=(node*)malloc(sizeof(node));
    nnode->data=n;
    nnode->left=nnode->right=NULL;
    return nnode;
}

node* insert(node* root, int n)
{
    if(root==NULL)
    {
        root=createNode(n);
    }
    else if(n<=root->data)
    {
        root->left=insert(root->left,n);
    }
    else
    {
        root->right=insert(root->right,n);
    }
    return root;
}

int search(node* root,int number)
{
    if(root==NULL)
        return 0;
    else if(number==root->data)
        return 1;
    else if (number<=root->data)
        return search(root->left,number);
    else
        return search(root->right,number);

}
void print(node * tree)
{
	if (tree){
		print(tree->left);
		printf("%d ",tree->data);
		print(tree->right);
	}
}

int main()
{
    struct data* root=NULL;
    int n,i=-1;
    do
    {
        printf("\nPlease enter a number:\n");
        scanf("%d",&n);
        root=insert(root,n);
        while(i!=1&&i!=0)
        {
            printf("\nDo you want to insert more(1/0)?\n");
            scanf("%d",&i);
        }
        if(i==1)i=-1;
        system("cls");
    }
    while(i==-1);
    do
    {
        i=-1;
        printf("\nThe numbers in the tree you currently have:\n");
        print(root);
        printf("\nEnter a number to be searched:\n");
        scanf("%d",&n);
        if (search(root,n)==1)
            printf("\nThe number %d was found\n\n",n);
        else
            printf("\nThe number %d was not found\n\n",n);
        while(i!=1&&i!=0)
        {
            printf("\n\nDo you want to search for other numbers(1/0)?\n\n");
            scanf("%d",&i);
        }
        if(i==1)i=-1;
        system("cls");
    }
    while(i==-1);
    return 0;
}
