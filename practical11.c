#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int g[n][n];
    printf("Enter the values:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n[%d][%d]:",i,j);
            scanf("%d",&g[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }

    int inf=10000;
    for(int k=0;k<n;k++){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(g[i][j]>g[i][k]+g[k][j] && (g[i][k]!=inf && g[k][j]!=inf)){
                    g[i][j]=g[i][k]+g[k][j];
                }

            }
            
        }
        
    }
    printf("\nShortest distances between every pair of vertices\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",g[i][j]);
        }
        printf("\n");        
    }
}