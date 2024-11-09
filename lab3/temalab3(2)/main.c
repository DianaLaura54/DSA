#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_type
{
    char key[100];
    int number;
    struct node_type *next;
    struct node_type *prev;
} NodeT;
typedef struct
{
    int count;
    NodeT *first;
    NodeT *last;
} ListT;
ListT *createEmptyDLL()
{
    ListT *listPtr = (ListT*)malloc(sizeof(ListT));
    if (listPtr)
    {
        listPtr->count = 0;
        listPtr->first = listPtr->last = NULL;
    }
    return listPtr;
}
NodeT *createDLLNode(char key[],int cont)
{
NodeT *p = (NodeT *)malloc(sizeof(NodeT));
if (p)
{

strcpy(p->key,key);
p->number=cont;
p->next = p->prev = NULL;
}
return p;
}
int insertAtFront(ListT *listPtr, NodeT *p)
{
    if (listPtr)
    {
        if (listPtr->count!=0)
        {

            listPtr->first = listPtr->last = p;
            p->prev = p->next = NULL;
        }
        else
        {
            p->next = listPtr->first;
            listPtr->first->prev = p;
            p->prev = NULL;
        }
        listPtr->count++;

    }

}

int main(int argc,char *argv[])
{
    FILE *pFile=fopen(argv[1],"r");
    FILE *pFile2=fopen(argv[2],"w");
    ListT *lista=createEmptyDLL();
    char line[100];
    char a[100][100];
    int i=0;
    while(fgets(line,sizeof(line),pFile)!=NULL)
    {
        strcpy(a[i],line);
        i++;
    }
    char aux[100];
    for(int j=0; j<i-1; j++)
    {
        for(int l=j+1; l<i; l++)
        {
            if(a[j]>a[l])
            {
                strcpy(aux,a[j]);
                strcpy(a[j],a[l]);
                strcpy(a[l],aux);
            }
        }
    }
    int x=0,cont[100];
    for(int j=1; j<i; j++)
    {
        if(strcmp(a[j],a[j-1])!=0)
        {
            cont[x]++;
            for(int y=j-1; y<i; y++)
            {
                strcpy(a[y],a[y+1]);

            }

            i--;
            j--;
        }
        else
        {
            x++;
        }


    }
    NodeT *cuvant;
    for(int j=0;j<x;j++)
{NodeT *cuvant=createDLLNode(a[j],cont[j]);
insertAtFront(lista,cuvant);

}

    return 0;
}
