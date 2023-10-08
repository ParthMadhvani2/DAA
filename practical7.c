#include<stdio.h>

void makechange(int coins[], int n, int amount){
    int count = 0;
    for(int i=0; i<n; i++){
        while( amount >= coins[i]){
            amount -= coins[i];
            count ++;
            printf("use coin %d \n", coins[i]);
        }
    }
    printf("Total no. of coins used: %d \n", count);
}

int main(){
    int coins[] = {50,20, 10, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount;

    printf("Enter amount for which you want to make change: ");
    scanf("%d",&amount);
    printf("making change for %d rupees", amount);
    makechange(coins, n, amount);

    return 0;
}