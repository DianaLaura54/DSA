#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 50
int f(char *key)
{
    int sum, len;
    sum = 0;
    len = strlen(key);
    for (int i = 0; i < len; i++)
        sum += key[ i ];
    return(sum % B);
}
typedef struct cell
{
    char key[60];
    struct cell *next;
} NodeT;

NodeT * find(int *BucketTable[],char key[])
{
    for(int i=0; i<B; i++)
    {
        NodeT *p = BucketTable[i];
        while (p != NULL)
        {
            if (strcmp(key, p->key) == 0)
                return p;
            p = p->next;
        }
        return NULL;
    }
}
NodeT *traverseList(NodeT *p)
{ NodeT *q=NULL;
while(p!=NULL)
{
q=p;
p=p->next;
}
return q;}
void insert(char key,int BucketTable[])
{
NodeT *p=malloc(sizeof(NodeT));
strcpy(p->key,key);
p->next=NULL;
if(p)
{ int h=f(p->key);
if(BucketTable[h]==NULL)
{BucketTable[h]=p;

}
else
{NodeT *r=traverseList(BucketTable[h]);
r->next=p;

}}
}
void show(int *BucketTable[])
{
    for (int i = 0; i < B; i++)
        if (BucketTable[ i ] != NULL)
        {
            printf("Bucket for hash value %d\n", i);
            NodeT *p =BucketTable[ i ];
            while (p != NULL)
            {
                printf("%s",p->key);
                p = p->next;
            }
        }
}
int main()
{
    FILE *pFile=fopen("data.in","r");
    FILE *pFile2=fopen("data.out","w");
    char line[100];
    NodeT *BucketTable[B];
    for (int i = 0; i < B; i++)
        BucketTable[i] = NULL;
    int h=0;
    int ok=0;
    while(fgets(line,sizeof(line),pFile))
    {
        if(line[0]=='i')
        {
            strcpy(line,line+1);
            insert(line,BucketTable);

            ok++;


        }
        if(line[0]=='d')
        {
            if(ok==1)
            {
                struct cell *p=NULL;
                strcpy(line,line+1);
                p=find(BucketTable,line);

            }
        }

        if(line[0]=='f')
        {
            struct cell *p=NULL;
            strcpy(line,line+1);

            p=find(BucketTable,line);
            fprintf(pFile2,"%s",p->key);
        }
        if(line[0]=='l')
        {
            show(BucketTable);
        }
    }
    return 0;
}
