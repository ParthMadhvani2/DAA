#include <stdio.h>
#include <sys/time.h>

void selection_sort(int arr[], int size)
{
    int i, j, max_index, temp;
    for (i = 0; i < size - 1; i++)
    {
        max_index = size - i - 1;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }

        if (max_index != size - i - 1)
        {
            temp = arr[j];
            arr[j] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d\t ", arr[i]);
    }
}
int main()
{
    int arr[20000];
    double ti;
    int i, j, size;
    struct timeval tv;
    struct timezone tz;
    int t1,t2,times;
    printf("Enter the size of aaray:");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        // arr[i] = rand() % 20000;
        arr[i]=i+1;
        // arr[i]=size-i;
    }
    gettimeofday(&tv, &tz);
    t1 = tv.tv_usec;
    selection_sort(arr, size);
    gettimeofday(&tv, &tz);
    t2 = tv.tv_usec;
    times=t2-t1;
    ti=(double)times/1000000;
    display(arr, size);
    printf(" \navg %d",times);
    printf(" \navg %f",ti);    
}