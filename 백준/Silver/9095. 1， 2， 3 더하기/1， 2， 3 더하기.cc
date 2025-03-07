#include<iostream>
#define N_SIZE 11
using namespace std;
int T;
int dp[N_SIZE];
//dp[i] == i를 1, 2, 3의 합으로 나타내는 방법의 수
int main() {
        fill(&dp[0], &dp[N_SIZE], 1);// dp[0]<- 1
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        cin >> T;
        while (T--) {
                int n; cin >> n;
                for (int i = 4; i <= n; i++) {
                        dp[i] = (dp[i - 1] * 2) - dp[i-4];
                }
                cout << dp[n] << endl;
        }
}