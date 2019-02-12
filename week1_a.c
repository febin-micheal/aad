#include<stdio.h>
#include<time.h>
			
void main()
{
	double m;
	clock_t t1,t2;
	int s[20],i,n,j,x,y,l;
	printf("enter no. of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&s[i]);
	for(i=0;i<n;i++)	printf("%d\t",s[i]);

	t1=clock();
	printf("\nenter element to remove: ");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(s[i]==x)
		{
			for(j=i;j<n;j++)	s[j]=s[j+1];
			n--;
		}
	}
	for(i=0;i<n;i++)	printf("%d\t",s[i]);

	printf("enter the element i: ");
	scanf("%d",&y);
	for(i=0;i<n;i++)
	{
		if(s[i]==y)
		{
			l=y;
			for(j=i+1;j<n;j++)
			{
				if(s[j]>l){
					l=s[j];
					break;
				}
			}
		}
	}
	printf("\nnext larger element: %d",l);
	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\ntime taken: %f",m);

}
