#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{

    char a;
    struct node_type *left,*right;
} BSTNodeT;
BSTNodeT *createNode(char b)
{
    BSTNodeT *p=(BSTNodeT*) malloc(sizeof(BSTNodeT));
    if(p)
    {
        p->a=b;
        p->left=p->right=NULL;
    }
    return p;
}
BSTNodeT *insertNode(BSTNodeT *root,char b)
{
    if(root==NULL)
    {
        root=createNode(b);
    }
    else
    {
        if(b<root->a)
            root->left=insertNode(root->left,b);
        else if(b>root->a)
            root->right=insertNode(root->right,b);

    }
    return root;
}

BSTNodeT *findMin(BSTNodeT *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->left)
        return findMin(node->left);
    else return node;
}
BSTNodeT *findMax(BSTNodeT *node)
{
    if(node == NULL)
    {
        return NULL;
    }
    if(node->right)
        return findMax(node->right);
    else
        return node;
}
BSTNodeT *delNode(BSTNodeT *node,char b)
{
    if(node==NULL)
    {
        printf("element not found");
    }
    else if(b<node->a)
    {
        node->left=delNode(node->left,b);
    }
    else if(b>node->a)
    {
        node->right=delNode(node->right,b);
    }
    else
    {
        if(node->right && node->left)
        {
            BSTNodeT *temp=findMin(node->right);
            node->a=temp->a;
            node->right=delNode(node->right,temp->a);
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
BSTNodeT *find(BSTNodeT *root,char a)
{
    if(root==NULL)
        return NULL;
    for(BSTNodeT *p=root; p!=NULL;)
    {
        if(a==p->a)
            return p;
        else if(a<p->a)
            p=p->left;
        else p=p->right;

    }
    return NULL;

}
void preorder(BSTNodeT *p)
{
    if (p != NULL)
    {
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(BSTNodeT *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        inorder(p->right);
    }
}
void postorder(BSTNodeT *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
    }
}
int main()
{
    FILE *pFile=fopen("data.txt","r");
    struct node_type *root=NULL;

    if(pFile==NULL)
        printf("error");
    char line[10];
    while(fgets(line,sizeof(line),pFile))
    {
        if(line[0]=='i')
        {
            root=insertNode(root,line[1]);
        }
        if(line[0]=='d')
        {
            root=delNode(root,line[1]);
        }
        if(line[0]=='f')
        {
            if(find(root,line[1])!=NULL)
                printf("node found");
        }
        if(line[0]=='t')
        {
            if(line[1]=='p')
                preorder(root);
            if(line[1]=='P')
                postorder(root);
            if(line[1]=='i')
                inorder(root);
        }
        if(line[0]=='g')
        {
            if(line[1]=='m')
                {BSTNodeT *nod=findMin(root);
            printf("%c",nod->a);}
            if(line[1]=='M')
                {BSTNodeT *nod=findMax(root);
                printf("%c",nod->a);}
        }

    }

    return 0;
}

