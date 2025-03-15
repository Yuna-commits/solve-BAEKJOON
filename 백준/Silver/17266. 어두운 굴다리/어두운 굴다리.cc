#include<iostream>
#include<vector>
#define N_SIZE 100001
using namespace std;
int N, M;
vector<int> lamp;
int check(int mid) {
        if (lamp[0]>mid||N - lamp[lamp.size()-1] > mid) return false;
        for (int i = 0; i < lamp.size() - 1; i++) {
                if ((lamp[i + 1] - lamp[i]) > mid * 2) return false;
        }
        return true;
}
int main() {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
                int X; cin >> X;
                lamp.push_back(X);
        }
        int ans = 0, left = 0, right = N;//굴다리 길이
        while (left <= right) {
                int mid = (left + right) / 2;
                if (check(mid)) {
                        ans = mid;
                        right = mid - 1;
                }
                else left = mid + 1;
        }
        cout << ans;
}