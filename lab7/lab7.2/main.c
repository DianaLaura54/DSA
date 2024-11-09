#include <stdio.h>
#include <stdlib.h>
typedef struct Node2
{
    int key;
    struct Node2* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} List;

void insertLast(List* list, int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    if (list->tail == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void addEdge(List *neighb[], int x, int y)
{
    insertLast(neighb[x], y);
    insertLast(neighb[y], x);
}void DFS(List *neighb[], int p,int n)
{ int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
   visited[p] = 1;
    printf("%d ", p);

    Node* x = neighb[p]->head;
    while (x != NULL)
    {
        if (visited[x->key] == 0)
        {
            visited[x->key] = 1;
            DFS(neighb, x->key,n);
        }
        x = x->next;
    }
}
void BFS(List *neighb[], int n, int start)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int queue[n];
    int left = 0;
    int right = 0;


    queue[right] = start;
    right++;

    visited[start] = 1;

    while (left != right)
    {
        int p = queue[left];
        left++;
        printf("%d ", p);


        Node *x = neighb[p]->head;
        while (x != NULL)
        {
            if (visited[x->key] == 0)
            {
                visited[x->key] = 1;
                queue[right] = x->key;
                right++;
            }
            x = x->next;
        }
    }
}
int main(int argc,char *argv[])
{
   FILE *pFile=fopen(argv[1],"r");



int i;
int mx=0;
fscanf(pFile, "V nodes");
int k=0;
while (fscanf(pFile, " %d", &i)==1)
{
if (i>mx) mx=i;
k++;

}
fscanf(pFile, "\nV arcs");
int **adj=malloc(mx*sizeof(int*));

for (i=0; i<mx; i++)
{
adj[i]=malloc(mx*sizeof(int));

}
int j;
while (fscanf(pFile, " %d %d", &i, &j)==2)
{
*(*(adj+i)+j)=1;
}
List *listPtr[mx];
for(int x=0;x<mx;x++)
    listPtr[x]->head= listPtr[x]->tail= NULL;
for(int x=1;x<mx-1;x++)
{for(int y=2;y<mx;y++)
    if(*(*(adj+x)+y)!=0)
    addEdge(listPtr,x,y);}
 BFS(listPtr,mx,0);
 DFS(listPtr,0,mx);

    return 0;
}
