/*
N을 1로 만들기 위한 최소 횟수
=((N-1)을 1로 만들기 위한 최소 횟수) + 1
2~N은 모두 1이 되기 위한 과정으로 동일한 연산을 취함
=>즉 N이 연산으로 정수 K가 될 때, 
K가 1이 되기 위한 연산 횟수가 X번이라면 N이 1이 되기 위한 연산 횟수는 (X + 1)번
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define min(a,b)(a<b?a:b)
#define MAX_SIZE 10000001
int dp[MAX_SIZE];
int N;
int solve() {
        /*dp[N]=min(dp[N-1]+1, dp[N/X]+1)
        => ((N-1)을 1로 만들기 위한 최소 횟수) + 1와 ((N/X)를 1로 만들기 위한 최소 횟수) + 1 비교*/
        for (int i = 2; i <= N; i++) {
                dp[i] = dp[i - 1] + 1;
                if (i % 2 == 0)
                        dp[i] = min(dp[i], dp[i / 2] + 1);
                if (i % 3 == 0)
                        dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        return dp[N];
}
int main()
{
        scanf("%d", &N);
        printf("%d\n", solve());
}