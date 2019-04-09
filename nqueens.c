#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

int x[100],count;

void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 
 for(i=1;i<=n;++i)
 {
 	printf("\n\n");
  for(j=1;j<=n;++j) 
  {
   if(x[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
 }
}
int place(int k,int i)
{
	for (int j = 1; j <= k-1; ++j)
	{
		if((x[j] == i))
			return 0;
		else
			if(abs(x[j]-i) == abs(j-k))
			return 0;
	}
	return 1;
}
void NQueen(int k,int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (place(k,i))
		{
			x[k] = i;
			if (k == n)
				print(n);
			else
				NQueen(k+1,n);
		}
	}
}
int main()
{
	int n;
	printf("\n\nEnter number of Queens:");
	scanf("%d",&n);
	NQueen(1,n);
	return 0;
}