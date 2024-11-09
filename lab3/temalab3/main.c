#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_FOUND -1;
typedef struct node
{
    char key[100];
    int next;
} NodeT;

typedef struct
{
    unsigned int capacity;
    int available;
    int first;
    int count;
    NodeT *data;
} ArrListT;

ArrListT *createCSLL(int size)
{
    ArrListT *listPtr = (ArrListT *) malloc(sizeof(ArrListT));
    if (listPtr)
    {
        listPtr->data = (NodeT *) calloc(size, sizeof(NodeT));
        if (listPtr->data)
        {
            listPtr->capacity = size;
            listPtr->first = -1;
            listPtr->count = 0;
            listPtr->available = 0;
            for (int i = 0; i < listPtr->capacity - 1; i++)
            {
                listPtr->data[i].next = i + 1;
            }

            listPtr->data[listPtr->capacity - 1].next = NOT_FOUND;
        }
        else
        {
            free(listPtr);
            listPtr = NULL;
        }
    }
    return listPtr;
}
void purge(ArrListT *listPtr)
{
    listPtr->first = -1;
    listPtr->count = 0;
    listPtr->available = 0;
    for (int i = 0; i < listPtr->capacity ; i++)
    {
        listPtr->data[i].next = i + 1;
    }

    listPtr->data[listPtr->capacity].next = NOT_FOUND;
}
void deletenode(ArrListT *listPtr,char key[])
{

    for(int i=0; i<listPtr->count; i++)

    {
        if ( strcmp(listPtr->data[i].key,key)==0)
        {
            listPtr->data[i-1].next = listPtr->data[i].next;

            listPtr->data[i].next = listPtr->available;
            listPtr->available = i;

            listPtr->first =i-1;
        }
    }
        (listPtr->count)--;
        if (listPtr->count == 0)
            purge(listPtr);

}

int main(int argc,char *argv[])
{
    FILE *pFile=fopen(argv[1],"r");
    FILE *pFile2=fopen(argv[2],"w");
    int x;
    fscanf(pFile,"%d",&x);
    int n;
    fscanf(pFile,"%d",&n);
    ArrListT *lista=createCSLL(n);
    for(int i=0;i<lista->capacity;i++)
        {fscanf(pFile,"%s",lista->data[i].key);
        (lista->count)++;}



deletenode(lista,lista->data[lista->count-1].key);

while(lista->count-1!=1)
{
    deletenode(lista,lista->data[n-lista->count].key);
}
    for(int i=0; i<lista->count; i++)
        {fprintf(pFile2,"%s ",lista->data[i].key);}


    return 0;
}
