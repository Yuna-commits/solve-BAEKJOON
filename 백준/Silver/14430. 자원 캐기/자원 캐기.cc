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
        //dp 1행, 1열 초기화
        dp[1][1] = wook[1][1];
        for (int i = 2; i <= N; i++) dp[i][1] = dp[i - 1][1] + wook[i][1];
        for (int i = 2; i <= M; i++) dp[1][i] = dp[1][i - 1] + wook[1][i];
        for (int i = 2; i <= N; i++) {
                for (int j = 2; j <= M; j++) {
                        dp[i][j] = max(dp[i - 1][j] + wook[i][j], dp[i][j - 1] + wook[i][j]);
                }
        }
        cout << dp[N][M];
}