#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int amt, n;
    printf("\nEnter the number of coins\n");
    scanf("%d", &n);
    printf("Enter the amount which you want to change\n");
    scanf("%d", &amt);

    int c[n + 1][amt + 1], coins[n + 1];
    printf("\nEnter the value of coins\n");
    coins[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        printf("Value for Coin %d :",i);
        scanf("%d", &coins[i]);
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < amt + 1; j++)
            c[i][j] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amt + 1; j++)
        {
            if (i == 1 && j < coins[i])
            {
                c[i][j] = c[i - 1][j];
            }
            else if (i == 1)
            {
                c[i][j] = 1 + c[1][j - coins[1]];
            }
            else if (j < coins[i])
            {
                c[i][j] = c[i - 1][j];
            }
            else
            {
                c[i][j] = min(c[i - 1][j], (c[i][j - coins[i]]) + 1);
            }
        }
    }
    printf("\n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d  ", coins[i]);
        for (int j = 0; j < amt + 1; j++)
        {
            printf("  %d", c[i][j]);
        }
        printf("\n");
    }
    printf("\n------  Use Coins: ------\n");
    int i = n;
    int j = amt;
    int count = 0;
    while (i != 1)
    {
        if (c[i][j] == c[i - 1][j])
            i = i - 1;
        else
        {
            j = j - coins[i];
            printf(" %d ", coins[i]);
            count ++; 
        } 
    }
    printf("\n Number of coins needed %d",count);
    return 0;
}