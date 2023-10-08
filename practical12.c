
#include <stdio.h>
#include <limits.h>

int ChainMultuplication(int arr[], int n) {
   int minMul[n][n];
   int j, q;
   for (int i = 1; i < n; i++)
   minMul[i][i] = 0;
   for (int Len = 2; Len < n; Len++) {
      for (int i = 1; i < n - Len + 1; i++) {
         j = i + Len - 1;
         minMul[i][j] = INT_MAX;
         for (int k = i; k <= j - 1; k++) {
            q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
            if (q < minMul[i][j])
            minMul[i][j] = q;
         }
      }
   }
   return minMul[1][n - 1];
}
int main(){
   int arr[] = {13, 5, 89, 3, 34};
   int size = sizeof(arr) / sizeof(arr[0]);
   printf("Minimum number of multiplications required are %d ", ChainMultuplication(arr, size));
   getchar();
   return 0;
}
