#include<iostream>
#include<algorithm>
#define MAX_SIZE 301
using namespace std;
int N, M;
int wook[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE] = { 0, };
int main()
{
        cin >> N >> M;//N:5 M:4
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) cin >> wook[i][j];
        }
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                        dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) + wook[i][j];
                }
        }
        cout << dp[N][M];
}