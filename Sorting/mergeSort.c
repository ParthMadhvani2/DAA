#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>


int size;

void mergesort(int arr[],int f,int l);
void merge(int arr[],int f,int m,int l);
void display(int arr[]);

int main()
	{
		printf("Enter size of array: ");
		
		scanf("%d",&size);
		
		int *arr = (int*)malloc(sizeof(int)*size);
		
		for(int i=0;i<size;i++)
		{
			arr[i]=rand()%1000;
		}
		

		
		struct timeval tv1,tv2;
		struct timezone tz;
		
		gettimeofday(&tv1,&tz);
					mergesort(arr,0,size-1);
		gettimeofday(&tv2,&tz);
		
		int time = (tv2.tv_usec - tv1.tv_usec);
		display(arr);
		printf("Time: %d usec\n",time);
		
		double times = (double)time / 10000000;
		printf("Time %f Sec\n",times);
		
	
	return 0;
	
	}

void mergesort(int arr[],int f,int l)
	{	
		
		if(f<l)
		{	int m = (f+l)/2;
		
			mergesort(arr,f,m);
			mergesort(arr,m+1,l);
			
			merge(arr,f,m,l);
			
		}

	
	}

void merge(int arr[],int f,int m,int l)
	{
		int i,j,k;
		i=f;
		j=m+1;
		int *b = (int*)malloc(sizeof(int)*size);
		k=f;
		
		while(i<=m && j<=l)
		{
			if(arr[i]>=arr[j])
			{
				b[k]=arr[j];
				j++;
				k++;
			}
			else
			{
				b[k]=arr[i];
				i++;
				k++;	
			
			}
			
			
		}
		
		
		while(i <= m)
		{		
			b[k]=arr[i];
			i++;
			k++;
		}
		
		while(j <= l)
		{	
			b[k]=arr[j];
			j++;
			k++;
		}
		
		
		for(int i=f;i<=l;i++)
		{
			arr[i]=b[i];
		}
	
	}
	
void display(int arr[])
			{
			for(int i=0;i<size;i++)
			printf("%d\n",arr[i]);
			}
