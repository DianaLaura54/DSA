#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int Tconfig[5][5];

typedef struct list
{
	unsigned cost, level;
	Tconfig inf;
	struct list *next, *pred;
} List;

typedef struct intT
{
	int nb;
}Integer;

Tconfig ConfIni;
List *r, *head;
Integer zl, zc ;
FILE *out , *in;


void read ( void )
{
	 int i,j;

	in = fopen ("in.dat" , "r");
	for (i = 1; i <= 4; i++)
		for ( j = 1; j <= 4; j++ )
			fscanf( in , "%d" , &ConfIni[i][j] );
	fclose( in );
}

void searchZero(Tconfig x, Integer *zLin, Integer *zCol)
{
	int i,j;
	for ( i = 1 ; i <= 4 ; i++)
		for ( j = 1 ; j <= 4 ; j++ )
			if (x[i][j] == 0)
			{
				zLin->nb = i;
				zCol->nb = j;
			}
}

int Distance (Tconfig conf)
{
	int cst = 0 , e , r , i , j;
	for ( i = 1 ; i <= 4 ; i++)
		{for (j = 1 ; j <=4 ; j++)
		{
			e = conf[i][j]/4 + 1;
			r = conf[i][j] % 4 ;
			if ( r == 0 )
			{
				r = 4;
				e -= 1;
			}
			if (conf[i][j] == 0)
				cst +=  abs(i-4)+ abs(j-4);
			else
				cst +=  abs(i-e)+ abs(j-r);
		}}
		return cst;
}

int theCost (Tconfig p, int parentLevel )
{
	return Distance(p) + parentLevel ;
}

void insertNode ( List *p)
{
	 List *t , *u;
	 t = head->next;
	 u = head;
	 while ((p->cost >= t->cost) && ( t!= NULL ))
	 {
		 u = t;
		 t = t->next;
	 }
	 p->next = t;
	 u->next = p;
}

void printMatrix ( Tconfig x)
{
	int i,j;

	for ( i = 1; i<=4; i++ )
	{
		for ( j = 1; j<=4; j++ )
			fprintf( out ,"%d ",x[i][j]);
		fprintf( out ,"\n");
	}
	fprintf( out ,"\n");
}
void Reconstit (List *node)
{
	if (node != NULL )
	{
		Reconstit (node->pred);
		printMatrix(node->inf);
	}

}


int main()
{
	int i,j;
	out = fopen("out.dat","w");
	read();
  head = (List*) malloc (sizeof (List));
	if (head == NULL )
	{
		fprintf( out , "Memory allocation error\n");
		fclose( out );
		exit(1);
	}
	head->pred = NULL;
	for (i=1; i<=4; i++)
		for (j=1; j<=4; j++)
			 head->inf[i][j] = ConfIni[i][j];
	head->next = NULL;
	head->level = 0;
	head->cost = theCost(head->inf , 0 );
	do
	{
		searchZero(head->inf, &zl, &zc);
		if ( (zc.nb) > 1 )
		{
			 r = (List*) malloc (sizeof (List));
			 for (i=1; i<=4; i++)
				 for (j=1; j<=4; j++)
					 r->inf[i][j] = head->inf[i][j];
			 r->inf[zl.nb][zc.nb] = r->inf[zl.nb][zc.nb-1];
			 r->inf[zl.nb][zc.nb-1] = 0;
			 r->cost = theCost (r->inf , head->level);
			 r->pred = head;
			 r->next = NULL;
			 r->level = head->level + 1;
			 insertNode(r);
		}
		if ( (zl.nb) < 4 )
		{
			r = (List*) malloc (sizeof (List));
			 for (i=1; i<=4; i++)
				 for (j=1; j<=4; j++)
					 r->inf[i][j] = head->inf[i][j];
			 r->inf[zl.nb][zc.nb] = r->inf[zl.nb+1][zc.nb];
			 r->inf[zl.nb+1][zc.nb] = 0;
			 r->cost = theCost (r->inf , head->level);
			 r->pred = head;
			 r->next = NULL;
			 r->level = head->level + 1;
			 insertNode(r);
		}
		if ( (zl.nb) > 1 ) /**/
		{
			r = (List*) malloc (sizeof (List));
			 for (i=1; i<=4; i++)
				 for (j=1; j<=4; j++)
					 r->inf[i][j] = head->inf[i][j];
			 r->inf[zl.nb][zc.nb] = r->inf[zl.nb-1][zc.nb];
			 r->inf[zl.nb-1][zc.nb] = 0;
			 r->cost = theCost (r->inf , head->level);
			 r->pred = head;
			 r->next = NULL;
			 r->level = head->level + 1;
			 insertNode(r);
		}
		if ( (zc.nb) < 4 )
		{
			r = (List*) malloc (sizeof (List));
			 for (i=1; i<=4; i++)
				 for (j=1; j<=4; j++)
					 r->inf[i][j] = head->inf[i][j];
			 r->inf[zl.nb][zc.nb] = r->inf[zl.nb][zc.nb+1];
			 r->inf[zl.nb][zc.nb+1] = 0;
			 r->cost = theCost (r->inf , head->level);
			 r->pred = head;
			 r->next = NULL;
			 r->level = head->level + 1;
			 insertNode(r);
		}
		head = head->next;
	}
	while (theCost (head->inf, 0) !=0);
	Reconstit (head);
	fclose( out );
	return 1;
}
