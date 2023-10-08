#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W, n;
    int w, l = 0, p;

    printf("Enter the knapsack's weight capacity\n");
    scanf("%d", &W);
    
    printf("Enter number of objects \n");
    scanf("%d", &n);
    
    int k[n + 1][W + 1], wts[W], val[W], ks[W];
    printf("Enter weights of objects \n");
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &wts[i]);
    }
    printf("Enter Value of objects \n");
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i <= W; i++)
        k[0][i] = 0;
    for (int i = 1; i <= n + 1; i++)
        k[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            if (wts[i] <= j)
            {
                if (val[i] + k[i - 1][j - wts[i]] > k[i - 1][j])
                {
                    k[i][j] = val[i] + k[i - 1][j - wts[i]];
                }
                else
                {
                    k[i][j] = k[i - 1][j];
                }
            }
            else
            {
                k[i][j] = k[i - 1][j];
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            printf("%d  ", k[i][j]);
        }
        printf("\n");
    }
    printf("Total Value in knapsack is  %d \n\n", k[n][W]);
    
    return 0;
}