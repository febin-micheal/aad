#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100


void insertionSort(int a[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{	
		x=a[i];
		for(j=i-1;j>=0&&x<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=x;
	}
}

void binarySearch(int a[],int n,int x)
{
	int f,l,m;
	// printf("\nenter element to search: ");
	// scanf("%d",&x);
	f=0;
	l=n;
	do
	{
		m=(f+l)/2;
		if(a[m]==x)	break;
		else if(a[m]>x)	l=m-1;
		else	f=m+1;
	}
	while(f<l);
	if(a[m]==x)	printf("element %d found at %d",x,m+1);
	else	printf("not found");
}	

void main()
{
	double m;
	clock_t t1,t2;

	FILE *fp;
	fp=fopen("binarySearch.dat", "a");

	int a[N],n,i,pos,x,y,ch;
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
			case 1:	x=a[2];
					break;
			case 2:	x=a[n/2];
					break;
			case 3: x=a[n-1];
					break;
			default: printf("invalid chice");
		}

		insertionSort(a,n);

		t1=clock();
		binarySearch(a,n,x);
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