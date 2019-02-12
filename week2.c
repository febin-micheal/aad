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

void swap(int *pa,int *pb)
{
	int temp;
	temp=*pa;
	*pa=*pb;
	*pb=temp;
}

void bubble_sort(int a[],int n)
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

void insertion_sort(int a[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{	
		x=a[i];
		for(j=i-1;j>=0&&x<a[j];j--)
		{
			a[j+1]=a[j];
		display(a,n);
		}
		a[j+1]=x;
	}
}

void selection_sort(int a[],int n)
{
	int i,j,lowest,temp;
	for(i=0;i<n-1;i++)
	{
		lowest=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[lowest])	lowest=j;
		}
		temp=a[i];
		a[i]=a[lowest];
		a[lowest]=temp;
		display(a,n);
	}
}

int partition(int a[],int beg,int end)
{
	int loc,temp;
	loc=beg;
	while(1)
	{
		while(a[loc]<=a[end]&&loc!=end)	end--;
		if(loc==end)	return loc;
		swap(&a[loc],&a[end]);
		while(a[loc]>=a[beg]&&loc!=beg)	beg++;
		if(loc==beg)	return loc;
		swap(&a[loc],&a[beg]);
	}
}		
void quick_sort(int a[],int beg,int end)
{
	int x;
	if(beg<end)
	{
		x=partition(a,beg,end);
		quick_sort(a,beg,x-1);
		quick_sort(a,x+1,end);
	}
}

void main()
{
	double m;
	clock_t t1,t2;




	int i,a[N],n,j;
	printf("enter no. of terms: ");
	scanf("%d",&n);

/*	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}


/*	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
*/	
	for(i=0,j=n;i<n,j>0;i++,j--)
	{
		a[i]=j;
	}


	display(a,n);

	t1=clock();

	bubble_sort(a,n);
	//insertion_sort(a,n);
	//selection_sort(a,n);
	//quick_sort(a,0,n);

	t2=clock();

	printf("\nbubble sort");
	display(a,n);

	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\ntime taken: %f",m);


}