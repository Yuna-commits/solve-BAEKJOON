#include<iostream>
#include<algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N_SIZE 1000001
using namespace std;
long long N, M;
int tree[N_SIZE];
int solve(int len) {//절단기 높이
        long long sum = 0;
        for (int i = 0; i < N; i++) {
                if (tree[i] - len > 0) sum += (tree[i] - len);
        }
        if (sum >= M) return 1;//높이를 더 높일 수 있음
        else return 0;//높이를 더 낮춰야 함
}
int main()
{
        fastio;
        long long ans = 0, left = 0, right = -1;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                cin >> tree[i];
                right = max(right, (long long)tree[i]);
        }
        while (left <= right) {
                long long mid = (left + right) / 2;
                if (solve(mid)) {
                        ans = mid;
                        left = mid + 1;
                }
                else right = mid - 1;
        }
        cout << ans;
}