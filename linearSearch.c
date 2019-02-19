#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100


void linearSearch(int a[],int n)
{
	int i,x;
	printf("\nenter element to search: ");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			break;
		}
	}
	if(i<n)	printf("element %d found at %d",x,i+1);
	else	printf("not found");
}



void main()
{
	double m;
	clock_t t1,t2;

	int a[N],n,i;
	printf("enter no. of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	for(i=0;i<n;i++)	printf("%d\t",a[i]);
	
	t1=clock();
	linearSearch(a,n);
	t2=clock();

	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\ntime taken: %f",m);


}