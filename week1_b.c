#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *first=NULL;

void main()
{
	double m;
	clock_t t1,t2;
	struct node *n,*current;
	int d,x,a,b,l,c;
	do
	{
		n=(struct node*)malloc(sizeof(struct node));
		printf("enter the data: ");
		scanf("%d",&d);
		n->data=d;
		if(first==NULL)	first=n;
		else
		{
			current=first;
			while(current->next!=NULL)	current=current->next;
			current->next=n;
		}
		printf("do you want to continue (1/0)?: ");
		scanf("%d",&x);
	}
	while(x==1);
	current=first;
	while(current!=NULL)
	{
		c=current->data;
		printf("%d\t",c);
		current=current->next;
	}

	t1=clock();
	printf("\nenter element to delete: ");
	scanf("%d",&a);
	if(first->data==a)	first=first->next;
	else
	{
	current=first;
	while(current->next->data!=a&&current->next!=NULL)	current=current->next;
	current->next=current->next->next;
	}
	printf("\n");
	current=first;
	while(current!=NULL)
	{
		c=current->data;
		printf("%d\t",c);
		current=current->next;
	}


	printf("\nenter the element: ");
	scanf("%d",&b);
	current=first;
	while(current->data!=b&&current->next!=NULL)	current=current->next;
	l=current->data;
	current=current->next;
	while(current->data<l)	current=current->next;
	l=current->data;
	printf("\nnext larger element: %d",l);

	t2=clock();
	m=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\ntime taken: %f",m);
}