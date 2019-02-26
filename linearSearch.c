#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100


void linearSearch(int a[],int n,int x)
{
	int i;
	// printf("\nenter element to search: ");
	// scanf("%d",&x);
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

	FILE *fp;
	fp=fopen("linearSearch.dat", "a");

	int a[N],n,i,y,x,ch;
	printf("enter no. of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	for(i=0;i<n;i++)	printf("%d\t",a[i]);

	do
	{
		printf("\n1.average\n2.best\n3.worst\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	x=a[n/2];
					break;
			case 2:	x=a[0];
					break;
			case 3: x=a[n-1];
					break;
			default: printf("invalid chice");
		}

		t1=clock();
		linearSearch(a,n,x);
		t2=clock();

		m=(double)(t2-t1)/CLOCKS_PER_SEC;
		printf("\ntime taken: %f",m);

		if(ch==1)
		{
			fprintf(fp,"%d ",n);
			fprintf(fp,"%f\n",m);
		}
		printf("\ndo you like to continue (1/0)?: ");
		scanf("%d",&y);

	}
	while(y==1);
	fclose(fp);
}