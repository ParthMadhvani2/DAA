#include <stdio.h>
#include <sys/time.h>
void max_heapify(int arr[], int size, int i)
{

    int l, r, largest; 
    l = 2 * i + 1;
    r = 2 * i + 2;
    largest = i;
    if (l <= size - 1 && arr[l] > arr[i])
    {
        largest = l;
    }
    if (r < size - 1 && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, size, largest);
    }
}
void build_max_heap(int arr[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, size, i);
    }
}
void heap_sort(int arr[], int size)
{

    build_max_heap(arr, size);
    int n=size-1;
    for (int i = size - 1; i >0; i--)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        n=n-1;
        max_heapify(arr,n,0);

    }
     
   
}
void display(int arr[],int size){
     for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int arr[1000000], size;
    struct timeval tv;
    struct timezone tz;
   int t1,t2;
    printf("Enter the size of array");
    scanf("%d", &size);
    int n=size;
    for (int i = 0; i < size; i++)
    {
        
        // scanf("%d", &arr[i]);
        // // arr[i]=rand()%1000;
        // // arr[i]=i+1;
        arr[i]=n;
        n--;

    }
    gettimeofday(&tv,&tz);
    t1=tv.tv_usec;
    heap_sort(arr, size);
    gettimeofday(&tv,&tz);
    t2=tv.tv_usec;
    display(arr,size);
    double time = (t2-t1)/1000000;
    printf("Time : %f", time);

    return 0;
}