#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

void display(int a[],int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)	printf("%d\t",a[i]);
}
void bubbleSort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-(i+1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		display(a,n);
		}
	}
}

void main()
{
	double m;
	clock_t t1,t2;

	int i,j,x,ch,a[N],n;
	printf("enter no. of terms: ");
	scanf("%d",&n);
	do
	{
		printf("1.average\n2.best\n3.worst\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				for(i=0;i<n;i++)
				{
					a[i]=rand()%100;
				}
				break;
			case 2:
				for(i=0;i<n;i++)
				{
					a[i]=i+1;
				}
				break;
			case 3:
				for(i=0,j=n;i<n,j>0;i++,j--)
				{
					a[i]=j;
				}
				break;
			default:
				printf("invalid choice");
		}
		
		printf("unsorted list \n");
		display(a,n);

		t1=clock();
		bubbleSort(a,n);
		t2=clock();
		printf("\nsorted list");
		display(a,n);

		m=(double)(t2-t1)/CLOCKS_PER_SEC;
		printf("\ntime taken: %f",m);

		printf("\ndo you like to continue (1/0)?: ");
		scanf("%d",&x);
	}
	while(x==1);
}

	