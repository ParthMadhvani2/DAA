#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>


int binary_search(int arr[],int key,int size,int l,int r)
{
	int mid;
	if(l<=r)
	{
		mid=(l+r)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		if(arr[mid]<key)
		{
			 return binary_search(arr,key,size,mid+1,r);
		}
		else 
		{	
			return binary_search(arr,key,size,l,mid-1);
		}
    	}
	
	return -1;
	

}

int main(){
	int size,key,x;
	struct timeval tv;
	struct timezone tz;
	int t2,t1;
	int l,r;
	printf("Enter the size of array");
	scanf("%d",&size);
	int *arr=(int *)malloc(size*sizeof(int));
	
	for(int i=0;i<size;i++)
	{
		arr[i]=i+1;
		printf("%d\t",arr[i]);
	}
	printf("Enter the element to find");
	scanf("%d",&key);
	l=0;
	r=size-1;
	gettimeofday(&tv,&tz);
	t1=tv.tv_usec;
	x=binary_search(arr,key,size,l,r);
	gettimeofday(&tv,&tz);
	t2=tv.tv_usec;
	
	if(x==-1)
		printf("Element not found\n");
	else
		printf("Element found at index %d \n",x);
	
	printf("Time: %d",(t2-t1));
return 0;
}
