#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    FILE *pFile=fopen(argv[1],"r");
    FILE *pFile2=fopen(argv[2],"w");

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
fscanf(pFile, "\nV' nodes");
j=0;
int *v=malloc(mx*sizeof(int));
while (fscanf(pFile, " %d", &i)==1)
{
*(v+j)=i;
j++;
}
for(int x=0;x<j;x++)
{for(int y=0;y<j;y++)
{
    if(*(*(adj+v[x])+v[y])!=0)
    fprintf(pFile2,"%d %d\n",v[x],v[y]);
}}

    return 0;
}
