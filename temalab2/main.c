#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *next;

} NodeT;
typedef struct
{
    int count;
    NodeT *first;
    NodeT *last;
} ListT;

ListT *createEmptySLL()
{
    ListT *listPtr = (ListT*)malloc(sizeof(ListT));
    if(listPtr)
    {
        listPtr->count = 0;
        listPtr->first= listPtr->last= NULL;
    }
    return listPtr;
}

NodeT *createSLLNode(int key)
{
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    if (p)
    {
        p->key=key;
        p->next=NULL;
    }
    return p;


}

int insertAtFront(ListT*listPtr, NodeT*p)
{
    if(listPtr)
    {
        p->next = listPtr->first;

        if(listPtr->count==0)
        {
            listPtr->last=p;
        }
        listPtr->first=p;

        listPtr->count++;
        return 1;
    }
    return 0;
}

void deleteFirst(ListT *listPtr)
{
    if( listPtr->first != NULL)
        {listPtr->first= listPtr->first->next;

        listPtr->count--;}
        if( listPtr->first == NULL)
            {listPtr->last= NULL;}




}
int find(ListT *listPtr,int givenKey)
{
    NodeT *p;
    p=listPtr->first;
    while(p!=NULL)

    {
        if(p->key==givenKey)
        {
            return 1;
        }
        else p=p->next;
    }
    return 0;


}
void deleteLast(ListT*listPtr)
{
    NodeT *q,*q1;
    q1= NULL;

    q= listPtr->first;
    if(q != NULL)
    {

        while(q != listPtr->last)
        {

            q1=q;
            q=q->next;
        }
        if(q == listPtr->first)
        {

            listPtr->first= listPtr->last= NULL;
        }
        else
        {

            q1->next= NULL;
            listPtr->last= q1;
        }

    }

}
void insertAtRear(ListT *listPtr, NodeT *p)
{
    if(listPtr)
    {
        if(listPtr->count==0)
        {
            listPtr->first=p;
        }
        else
        {
            listPtr->last->next=p;
        }
        listPtr->last=p;
        listPtr->count++;
    }

}
void printList(ListT* listPtr)
{
    NodeT* p;
    p = listPtr->first;

    while(p!=NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}
void deleteByKey(ListT *listPtr, int givenKey)
{
    NodeT *q,*q1;
    q1=NULL;
    q=listPtr->first;
    while(q!=NULL)
    {
        if(q->key==givenKey)
            break;
        q1=q;
        q=q->next;
    }
    if(q!=NULL)
    {
        if(q==listPtr->first)
        {
            listPtr->first=listPtr->first->next;
            free(q);
            if(listPtr->first==NULL)
                listPtr->last=NULL;
        }
        else
        {
            q1->next=q->next;
            if(q==listPtr->last)
                listPtr->last=q1;
            free(q);
        }
    }

}
int main()
{
    FILE *pFile=fopen("r","data.txt");
    ListT *garage=createEmptySLL();
    ListT *road=createEmptySLL();
    char line[10];
    int t;
    fscanf(pFile,"%d",&t);
    if(t==1)
    {
        while(fgets(line,0,pFile)!=NULL)
        {
            if(strcmp(line,"R")!=0)
            {
                int y;
                fscanf(pFile,"%d",&y);
                NodeT *truck = createSLLNode(y);
                insertAtFront(road,truck);
            }
            if(strcmp(line,"E")!=0)
            {
                int y;
                fscanf(pFile,"%d",&y);
                if(find(road,y)!=0)
                {
                    deleteByKey(road,y);
                    {
                        NodeT *truck=createSLLNode(y);
                        insertAtRear(garage,truck);
                    }
                }
                else printf("not on road");
            }
            if(strcmp(line,"X")!=0)
            {
                int y;
                fscanf(pFile,"%d",&y);
                if(garage!=NULL)
                {
                    if(garage->first->key==y)
                    {
                        deleteFirst(garage);
                    }
                    else printf("can't move the truck from the garage");
                }
                else printf("not on garage");
            }
            if(strcmp(line,"S")!=0)
            {
                int x;
                fscanf(pFile,"%d",&x);
                if(x==1)
                    printList(garage);
                if(x==2)
                    printList(road);
            }
        }
    }
    if(t==2)
    {
        while(fgets(pFile,sizeof(line),line)!=0)
        {
            if(strcmp(line,"R")!=0)
            {
                int y;
                fscanf(pFile,"%d",&y);
                NodeT *truck = createSLLNode(y);
                insertAtFront(road,truck);
            }
            if(strcmp(line,"E")!=0)
            {
                int y;
                fscanf(pFile,"%d",&y);
                if(road->first->key==y)
                {
                    deleteFirst(road);
                    NodeT *truck=createSLLNode(y);
                    insertAtRear(garage,truck);
                }
                else printf("not on road");
            }
            if(strcmp(line,"X")!=0)
            {
                int y;
                fscanf(pFile,"%d",&y);
                if(garage!=NULL)
                {
                    if(garage->first->key==y)
                    {
                        deleteFirst(garage);
                    }
                    else printf("can't move the truck from the garage");
                }
                else printf("not on garage");
            }
            if(strcmp(line,"S")!=0)
            {
                int x;
                fscanf(pFile,"%d",&x);
                if(x==1)
                    printList(garage);
                if(x==2)
                    printList(road);
            }


        }
    }
    return 0;
}
