#include <stdio.h>
#include <sys/time.h>

void bubble_sort(int arr[], int size)
{
    int i = 0, temp, j = 0, flag;
    for (i = 0; i < size-1; i++)
    {
        flag = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {

            break;
        }
    }
}
void display(int arr[], int size)
{
    // printf("Sorted array:");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
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
        // arr[i] = rand() % 1000; //average case
        arr[i]=i+1;         //best case
        // arr[i]=size-i;      //worst case
    }
    gettimeofday(&tv, &tz);
    t1 = tv.tv_usec;
    bubble_sort(arr, size);
    gettimeofday(&tv, &tz);
    t2 = tv.tv_usec;
    times=t2-t1;
    ti=(double)times/1000000;
    display(arr, size);
    printf(" \n time %d sec",times);
    printf(" \n time %f msec",ti);
}