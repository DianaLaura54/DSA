#include <stdio.h>
#include <stdlib.h>

int k;

typedef struct activity
{
    int begin, finish;
}act;

int compareAct(const int *a, const int *b)
{
    return ((act*)a)->finish > ((act*)b)->finish;
}

int main()
{
    FILE *fin;
    fin=fopen("input.txt","r");
    if (fin == NULL)
    {
        perror("not found");
        exit(-1);
    }
    int i,n;
    fscanf(fin,"%d ",&n);
    act events[n];
    for(i=1;i<=n;i++)
    {
        fscanf(fin," %d %d" ,&events[i].begin, &events[i].finish );

    }

    for (i=1;i<=n;i++)
        printf(" %d - %d ; ",events[i].begin, events[i].finish );

    qsort(events,n,sizeof(act),compareAct);

    printf("\n");
    for (i=1;i<=n;i++)
        printf(" %d - %d ; ",events[i].begin, events[i].finish );

    act e[100];
    int k=1;
    e[1]=events[1];
    for(i=2;i<=n;i++)
    {
        if ( e[k].finish < events[i].begin)
            e[++k]=events[i];
    }
    printf("\n");
    for (i=1;i<=k;i++)
        printf(" %d - %d ; ",e[i].begin, e[i].finish );
    return 0;
}
