#include <stdio.h>
#include <stdlib.h>
int main()
{
    void knapsack(float w[],float p[],int n,int cap,float pw[]);
    int cap, n;
     int t1, t2, t3;
    printf("Enter the knapsack's weight capacity \t");
    scanf("%d",&cap);
    printf("\n number of objects:");
    scanf("%d",&n);
    float pw[n],p[n],w[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter weights of object %d\n",i+1);
        scanf("%f", &w[i]);
    }
    printf("\nEnter Profit\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        pw[i] = p[i] / w[i];
    }

     for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (pw[j] < pw[j+1])
            {
                t1 = pw[j];
                pw[j] = pw[j+1];
                pw[j+1] = t1;

                t2 = w[j];
                w[j] = w[j+1];
                w[j+1] = t2;

                t3 = p[j];
                p[j] = p[j+1];
                p[j+1] = t3;
            }
        }
    }
    knapsack(w,p,n,cap,pw);
    return 0;
}
void knapsack(float w[],float p[],int n,int cap,float pw[]){
    int k=0;
    float f[n],prof=0,wt=0;
    for (int i = 0; i < n; i++)
    {
        if ((wt + w[i]) <= cap)
        {
            k++;
            f[i] = 1;
            wt += w[i];
            prof += p[i];
        }
        else
        {
            k++;
            f[i] = (cap - wt) / w[i];
            w[i] = cap - wt;
            wt=cap;
            prof += (f[i] * p[i]);
            p[i] = (f[i] * p[i]);
            break;
        }
    }
    printf("\nThe total profit :  %f\n", prof);
}
