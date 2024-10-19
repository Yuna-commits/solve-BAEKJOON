/*
1x2 사이즈 타일로 nx2 사이즈 직사각형을 채우는 방법의 수
**중요한 점**
타일을 세로(1)로 채우는 경우 -> 직사각형의 남은 가로 길이는 n-1
타일을 가로(2)로 채우는 경우 -> 직사각형의 남은 가로 길이는 n-2
피보나치 수열과 같은 방식으로 (n-1)일 때 방법의 수와 (n-2)일 때 방법의 수를 더함
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int dp[1001] = { 0, };
int main()
{
        int n;
        scanf("%d", &n);
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
        printf("%d\n", dp[n]);
}