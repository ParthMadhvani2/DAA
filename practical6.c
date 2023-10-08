#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
int size;

void Quick_sort(int a[], int SP, int EP)
{
    int i, j, pivot;
    int Flag = 1;

    if (SP < EP)
    {

        pivot = a[SP];
        i = SP;
        j = EP + 1;

        while (Flag == 1)
        {

            i = i + 1;

            while (a[i] < pivot)
            {
                i = i + 1;
            }

            j = j - 1;

            while (a[j] > pivot)
            {
                j = j - 1;
            }

            if (i < j)
            {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else
            {
                Flag = 0;
            }
        }
        int temp;
        temp = a[SP];
        a[SP] = a[j];
        a[j] = temp;

        Quick_sort(a, SP, j - 1);
        Quick_sort(a, j + 1, EP);
    }
}

int main()
{
    struct timeval tv;
    struct timezone tz;
    int t1, t2, t;
    double ts;
    printf("Enter size of array: ");

    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        // arr[i]=rand()%1000; //best case,avergae case
         arr[i] = i + 1; // worst case
        // arr[i]=size-i; //worst case
    }
    gettimeofday(&tv, &tz);
    t1 = tv.tv_usec;
    Quick_sort(arr, 0, size - 1);
    gettimeofday(&tv, &tz);
    t2 = tv.tv_usec;
    t = (t2 - t1);
    ts = (double)t / 1000000;
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Time in sec %f", ts);
    return 0;
}
