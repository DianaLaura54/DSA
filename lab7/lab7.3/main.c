#include <stdio.h>
#include <stdlib.h>
#define NMAX  100
#define INFTY  100000
double dist[NMAX];
double cost[NMAX][NMAX];
int parent[NMAX];
int S[NMAX];
void Dijkstra(int n, int source)
{



for (int i = 1; i <= n; i++)
{
S[i] = 0;
dist[i] = cost[source][i];
if (dist[i] < INFTY) parent[i] = source;
else parent[i] = 0;
}
S[source] = 1;
parent[source] = 0;
dist[source] = 0;
int k=INFTY;
for(int i=1;i<=n;i++)
{
    if(dist[i]<k && k!=source)
    {
        k=i;
    }

}

for (int step = 1; step <= n-1; step++)
{

if (S[step]== INFTY) return;
S[k] = 1;
for (int j = 1; j <= n; j++)
if (S[j] == 0 && dist[k] + cost[k][j] < dist[j])
{
dist[j] = dist[k] + cost[k][j];
parent[j] = k;
}
}
}
int main()
{
    FILE *pFile=fopen("text.in","r");
    int n1,n2,n3;
    int mx=-1;

while(fscanf(pFile,"%d %d %d ",&n1,&n2,&n3)==3)
{
    if(n1>mx)
    {
        mx=n1;
    }
    if(n2>mx)
    {
        mx=n2;
    }
    cost[n1][n2]=n3;
}
int v[mx];

for(int i=1;i<=mx;i++)
{ Dijkstra(mx,i);
v[i]=dist[mx];

}
int mini=INFTY;
for(int i=1;i<=mx;i++)
{
    if(v[i]<mini)
        mini=v[i];
}
printf("%d",mini);
    return 0;
}
