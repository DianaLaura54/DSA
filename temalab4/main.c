#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} nodeT;

nodeT *create()
{
    nodeT *p;
    char x;
    scanf("%c",&x);
    if(x=='*')
        return NULL;

    else
    {
        p=(nodeT*)malloc(sizeof(nodeT));
        if(p==NULL)
            printf("error");

        p->data=x;

        p->left=create();


        p->right=create();

    }
    return p;

}



void preorder( nodeT *p, int level )
{
    if ( p != NULL )
    {
        for ( int i = 0; i <= level; i++ ) printf( " " );
        printf( "%c", p->data );
        preorder( p->left, level + 1 );
        preorder( p->right, level + 1 );
    }
}
void inorder( nodeT *p, int level )
{
    if ( p != NULL )
    {
        inorder( p->left, level + 1 );
        for (int i = 0; i <= level; i++ )
            printf( " " );
        printf( "%c ", p->data );
        inorder( p->right, level + 1 );
    }
}
void postorder( nodeT *p, int level )
{
    if ( p != NULL )
    {
        postorder( p->left, level + 1 );
        postorder( p->right, level + 1 );
        for ( int i = 0; i <= level; i++ )
            printf( " " );
        printf( "%c ", p->data);
    }
}
void Swap( nodeT **a , nodeT **b)
{
    nodeT * temp = *a;
    *a = *b;
    *b = temp;
}


void swapEveryKLevelUtil( nodeT *root, int level, int k)
{
    if (root== NULL ||
            (root->left==NULL && root->right==NULL) )
        return ;

    if ( (level + 1) % k == 0)
        Swap(&root->left, &root->right);


    swapEveryKLevelUtil(root->left, level+1, k);
    swapEveryKLevelUtil(root->right, level+1, k);
}


void swapEveryKLevel(nodeT *root, int k)
{
    swapEveryKLevelUtil(root, 1, k);
}
int maxDepth(nodeT* node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);


        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
int getLeafCount(struct node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left)+getLeafCount(node->right);
}
int main()
{

    nodeT *root;
    root=create();
 preorder(root,0);
 printf("\n");
 inorder(root,0);
 printf("\n");
 postorder(root,0);
 printf("\n");
 int k=2;
 swapEveryKLevel(root,k);
 preorder(root,0);
 printf("\n");
printf("%d",maxDepth(root));
printf("\n");
printf("%d",getLeafCount(root));



    return 0;
}
