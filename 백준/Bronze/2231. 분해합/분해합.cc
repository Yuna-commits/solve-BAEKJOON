#include<iostream>
using namespace std;
int N;
int solve() {
        for (int i = 1; i < N; i++) {
                int tmp = i;
                int ans = tmp;
                while (tmp) {
                        ans += (tmp % 10);
                        tmp /= 10;
                }
                if (ans == N) return i;
        }
        return 0;//생성자가 없는 경우
}
int main()
{
        cin >> N;
        cout << solve() << endl;
}