#include<iostream>
#include<cstdlib>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N_SIZE 100001
using namespace std;
int N, arr[N_SIZE];
int main() {
        fastio;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> arr[i];
        //투 포인터
        int left = 0, right = N - 1, sum = 2e9;//2*109 = 20억
        pair<int, int> ans;
        while (left < right) {//서로 다른 두 용액
                int x = arr[left], y = arr[right];
                if (abs(x + y) < sum) {//더 작은 값으로 갱신
                        ans = { x,y };
                        sum = abs(x + y);
                }
                //포인터 이동
                if (x + y < 0) left++;
                else right--;
        }
        cout << ans.first << " " << ans.second;
}