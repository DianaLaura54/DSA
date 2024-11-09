#include <stdio.h>
#include <stdlib.h>
int posmin(double a[], int first, int last)
{
    double min = INT_MAX;
    int posmin = 0;
    while(first >= last)
    {
        if(a[first] < min)
        {
            min = a[first];
            posmin = first;
        }
        first--;
    }
    return posmin;
}


int posmax(double a[], int first, int last)
{
    double max = 0;
    int posmax = 0;
    while(first <= last)
    {
        if(a[first] > max)
        {
            max = a[first];
            posmax = first;
        }
        first++;
    }
    return posmax;
}

double profit(double a[], int first, int last)
{
    int posmini, posmaxi, posminbfmax, posmaxafmin;
    posmini = posmin(a, last - 1, first);
    posmaxi = posmax(a, first, last - 1);
    posminbfmax = posmin(a, posmaxi, first);
    posmaxafmin = posmax(a, posmini, last - 1);
    if((a[posmaxi] - a[posminbfmax]) > (a[posmaxafmin] - a[posmini]))
        return (a[posmaxi] - a[posminbfmax]);
    return (a[posmaxafmin] - a[posmini]);
}
int main(int argc, char *argv[])
{
    FILE *pFile,*pFile2;
    int n, i;
    double a[100] = {0};
    pFile=fopen(argv[1],"r");
    pFile2=fopen(argv[2],"w");

        fscanf(pFile, "%d", &n);
        for(i = 0; i < n; i++)
        {
            fscanf(pFile, "%lf", &a[i]);
        }


    fprintf(pFile2, "%lf\n", profit(a, 0, n));

    return 0;
}
