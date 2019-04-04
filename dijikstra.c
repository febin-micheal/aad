#include <stdio.h>
#include<stdlib.h>
 
#define infinity 999
#define MAX 20
 
float G[MAX][MAX],A[MAX][MAX],cost[MAX][MAX];
int n;

float min(float a,float b)
{
	if(a<b)	return a;
	else	return b;
}
void AllPairShortestPath()
{
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		for (int j = 1; j <= n; ++j)
		{
			/* code */
			A[i][j] = cost[i][j];
		}
	}
	for (int k = 1; k <= n; ++k)
	{
		/* code */
		A[k][k]=0;
		for (int i = 1; i <= n; ++i)
		{
			/* code */
			for (int j = 1; j <= n; ++j)
			{
				/* code */
				A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
			}
		}
	}
}

void main()
{

	int i,j;

	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%f",&G[i][j]);
	}

	for(i=1;i<=n;i++)
	{
		cost[i][i]=0;
		for(j=1;j<=n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=infinity;
			else
				cost[i][j]=G[i][j];
		}
	}

	AllPairShortestPath();

	printf("\nAll pair Shortest path matrix:\n");
	
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%f\t",A[i][j]);
	}

}
