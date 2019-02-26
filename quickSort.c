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

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void main()
{
	double m;
	clock_t t1,t2;

	FILE *fp;
	fp=fopen("quickSort.dat", "a");

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
		quickSort(a,0,n-1);
		t2=clock();
		printf("\nsorted list");
		display(a,n);

		m=(double)(t2-t1)/CLOCKS_PER_SEC;
		printf("\ntime taken: %f",m);

		if(ch==1)
		{
			fprintf(fp,"%d ",n);
			fprintf(fp,"%f\n",m);

		}

		printf("\ndo you like to continue (1/0)?: ");
		scanf("%d",&x);
	}
	while(x==1);
	fclose(fp);

}
