#include<iostream>
#include<algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N_SIZE 1000001
using namespace std;
int A, K;
int dp[N_SIZE];//dp[i] == A가 i를 만드는 최소 연산 횟수
int main() {
        fastio;
        cin >> A >> K;
        fill(&dp[A], &dp[K + 1], 987654321);
        dp[A] = 0;
        for (int i = A + 1; i <= K; i++) {
                if (i % 2 == 0 && i / 2 >= A) {//i가 짝수면 연산1, 연산2 비교
                        dp[i] = min(dp[i] + 1, dp[i / 2] + 1);
                }
                else  dp[i] = dp[i - 1] + 1;
        }
        cout << dp[K];
}