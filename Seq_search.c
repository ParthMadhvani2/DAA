#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int Seq_search(int arr[],int key,int n)
{
	for(int i=0;i<n;i++){
		if(arr[i]==key)
		return i;
	}
	return -1;


}
int main(){
	int size,key,x;
	struct timeval tv;
	struct timezone tz;
	int t2,t1;
	printf("Enter the size of array");
	scanf("%d",&size);
	int *arr=(int *)malloc(size*sizeof(int));
	
	for(int i=0;i<size;i++)
	{
		arr[i]=rand()%10000;
	}
	printf("Enter the element to find");
	scanf("%d",&key);
	
	gettimeofday(&tv,&tz);
	t1=tv.tv_usec;
	x=Seq_search(arr,key,size);
	gettimeofday(&tv,&tz);
	t2=tv.tv_usec;
	
	if(x==-1)
		printf("Element not found\n");
	else
		printf("Element found at index %d \n",x);
	
	printf("Time: %d",(t2-t1));
return 0;
}
