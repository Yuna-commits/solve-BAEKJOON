#include<iostream>
#define N_SIZE 11
using namespace std;
//dp[i] == i를 1, 2, 3의 합으로 나타내는 방법의 수
int main() {
        int T;
        int dp[N_SIZE] = { 0, };
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for (int i = 4; i < N_SIZE; i++)
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        cin >> T;
        while (T--) {
                int n; cin >> n;
                cout << dp[n] << endl;
        }
}