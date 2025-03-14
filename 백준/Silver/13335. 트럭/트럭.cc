#include<iostream>
#include<queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N_SIZE 1001
using namespace std;
int N, W, L;
int check[N_SIZE];//트럭의 이동 시간
queue<pair<int, int>> truck;
int solve() {
        queue<pair<int, int>> bridge;
        int time = 0, now = 0, idx = 0;//현재 시간, 현재 다리 위 무게
        while (1) {
                if (truck.empty() && bridge.empty()) break;
                if (!bridge.empty()) {//트럭이 다리에서 나올 수 있음
                        if (check[bridge.front().second] == W) {
                                now -= bridge.front().first;
                                bridge.pop();
                        }
                }
                if (!truck.empty()) {
                        if (now + truck.front().first <= L) {//트럭이 다리를 지나갈 수 있음
                                now += truck.front().first;
                                bridge.push({ truck.front().first, idx });
                                truck.pop();
                                idx++;
                        }
                }
                for (int i = 0; i < idx; i++) check[i]++; //이동 시간 계산
                time++;
        }
        return time;
}
int main() {
        fastio;
        cin >> N >> W >> L;
        fill(&check[0], &check[N], 0);
        for (int i = 0; i < N; i++) {
                int tmp; cin >> tmp;
                truck.push({ tmp, i });
        }
        cout << solve();
}