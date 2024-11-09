#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_type
{
    char name[100];
    float price,amount;
    double dateofM,dateofE;
    struct node_type *left, *right;
} BSTNodeT;
BSTNodeT *createNode(char name[],float price,float amount,double dateofM,double dateofE)
{
    BSTNodeT *p=(BSTNodeT*) malloc(sizeof(BSTNodeT));
    if(p)
    {
        strcpy(p->name,name);
        p->price=price;
        p->amount=amount;
        p->dateofM=dateofM;
        p->dateofE=dateofE;
        p->left=p->right=NULL;
    }
    return p;
}
BSTNodeT *insertNode(BSTNodeT *root,char name[],float price,float amount,double dateofM,double dateofE)
{
    if(root==NULL)
    {
        root=createNode(name,price,amount,dateofM,dateofE);
    }
    else
    {
        if(strcmp(name,root->name)<0)
            root->left=insertNode(root->left,name,price,amount,dateofM,dateofE);
        else if(strcmp(name,root->name)>0)
            root->right=insertNode(root->right,name,price,amount,dateofM,dateofE);

    }
    return root;
}
BSTNodeT *findMin(BSTNodeT *node)
{
if(node == NULL)
{
return NULL;
}
if(node->left)
return findMin(node->left);
else
return node;
}
BSTNodeT *delNode(BSTNodeT *node,char b[])
{
    if(node==NULL)
    {
        printf("element not found");
    }
    else if(strcmp(b,node->name)<0)
    {
        node->left=delNode(node->left,b);
    }
    else if(strcmp(b,node->name)>0)
    {
        node->right=delNode(node->right,b);
    }
    else
    {
        if(node->right && node->left)
        {
            BSTNodeT *temp=findMin(node->right);
        strcpy(node->name,temp->name);
            node->right=delNode(node->right,temp->name);
        }
        else
        {
            BSTNodeT *temp=node;
            if(node->left==NULL)
                node=node->right;
            else if(node->right==NULL)
                node=node->left;
            free(temp);
        }
    }
    return node;
}
BSTNodeT *find(BSTNodeT *root, char name[])
{
BSTNodeT *p;
if (root == NULL) return NULL;
p = root;
while (p != NULL)
{
if (strcmp(p->name,name)==0)
return p;
else
if (strcmp(name,p->name)<0)
p = p->left;
else
p = p->right;
}
return NULL;
}
void preorder(BSTNodeT *p,int e,BSTNodeT *ce)
{
if (p != NULL)
{
    if(p->dateofE<e)
    {insertNode(ce,p->name,p->price,p->amount,p->dateofM,p->dateofM);}

preorder(p->left,e,ce);
preorder(p->right,e,ce);
}
}

int main(int argc,char *argv[])
{
    FILE *pFile=fopen(argv[1],"r");
    FILE *pFile2=fopen(argv[2],"w");
    struct node_type *root=NULL;
    char line[1000];
    while(fgets(line,sizeof(line),pFile))
    {
        char x[1000];
        strcpy(x,line+1);
            char cuv[100][100];
             char *p;
             int i=0;
             strtok(x,",");
             while(p!=0)
             {
                 strcpy(cuv[i],p);
                 p=strtok(NULL,",");
                 i++;
             }
        if(line[0]=='i')
        {

             insertNode(root,cuv[0],atoi(cuv[1]),atoi(cuv[2]),atoi(cuv[3]),atoi(cuv[4]));

        }
        if(line[0]=='d')
        {
            root=delNode(root,cuv[0]);

        }
        if(line[0]=='u')
        {

        BSTNodeT *p=find(root,cuv[0]);
       strcpy(p->name,cuv[0]);
       p->price=atoi(cuv[1]);
       p->amount=atoi(cuv[2]);
       p->dateofM=atoi(cuv[3]);
       p->dateofE=atoi(cuv[4]);

        }

    }
 struct node_type *ce=NULL;
 double e=20220706;
 preorder(root,e,ce);





    return 0;
}
