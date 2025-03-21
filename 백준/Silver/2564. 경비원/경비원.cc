#include<iostream>
#include<vector>
#include<algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dong[2];//동근이 위치
int N, M, S;//N: row, M: col, S: 가게 개수
vector<pair<int, int>> store;
int solve() {
        //동근이 위치와 가게 위치에 따라 조건 분기
        int sum = 0;
        for (int i = 0; i < S; i++) {
                //동근과 상점이 같은 라인
                if (dong[0] == store[i].first) sum += abs(store[i].second - dong[1]);
                else if (dong[0] == 1 || dong[0] == 2) {//동근: 북 or 남
                        if (store[i].first == 3 || store[i].first == 4) {//상점: 서 or 동
                                if (store[i].first == 3) sum += dong[1];
                                else sum += (M - dong[1]);
                                if (dong[0] == 1)  sum += store[i].second;
                                else sum += (N - store[i].second);
                        }
                        else {//상점: 남 or 북(동근과 마주보는 위치)
                                sum += N;
                                sum += min(dong[1] + store[i].second, 2 * M - (dong[1] + store[i].second));
                        }
                }
                else {//동근: 동 or 서
                        if (store[i].first == 1 || store[i].first == 2) {//상점: 남 or 북
                                if (store[i].first == 1) sum += dong[1];
                                else sum += (N - dong[1]);
                                if (dong[0] == 3) sum += store[i].second;
                                else sum += (M - store[i].second);
                        }
                        else {//상점: 서 or 동(동근과 마주보는 위치)
                                sum += M;
                                sum += min(dong[1] + store[i].second, 2 * N - (dong[1] + store[i].second));
                        }
                }
        }
        return sum;
}
int main() {
        fastio;
        cin >> M >> N;
        cin >> S;
        for (int i = 0; i < S; i++) {
                int dir, loc; cin >> dir >> loc;
                store.push_back({ dir, loc });
        }
        cin >> dong[0] >> dong[1];
        cout << solve();
}