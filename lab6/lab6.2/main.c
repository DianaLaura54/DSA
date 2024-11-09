#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
FILE* input=fopen("input.txt","r+");
FILE* output=fopen("output.txt","w");
int main()
{
    Node** buckets=(Node**)malloc((B+1)*sizeof(Node*));
    Node* extra=(Node*)malloc(sizeof(Node));
    for (int i=0;i<B;i++)
    {

        buckets[i]=NULL;
    }
    char s[100];char c;
    while(fscanf(input,"%s\n",s)!=-1)
    {
            c=s[0];
            strcpy(s,s+1);
            if (c=='i')
            {
                int h=hashf(s);
                insertt(buckets,extra,s);

            }
            if (c=='l')
            {
                for (int i=0;i<=B;i++) printt(buckets[i],output);
            }
            if (c=='f')
            {
                fprintf(output,"%s\n",findd(buckets,s));
            }
            if (c=='d')
            {
                if (del(buckets,s)==1) fprintf(output,"deleting the node %s works\n",s);
                else fprintf(output,"deleting the node %s does not work\n",s);
            }
    }

    return 0;
}
