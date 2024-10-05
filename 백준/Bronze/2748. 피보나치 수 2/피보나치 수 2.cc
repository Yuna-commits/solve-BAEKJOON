#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 91
int main(){
    int N;
    scanf("%d", &N);
    long long dp[SIZE];
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=N;i++)
        dp[i]=dp[i-1]+dp[i-2];
    printf("%lld\n", dp[N]);
}