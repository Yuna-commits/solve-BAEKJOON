#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MAX_SIZE 50
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
using namespace std;
int N, M, ans;
int space[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];/*방문확인*/
int dist[MAX_SIZE][MAX_SIZE];/*상어로부터 안전거리*/
/*시계방향 8방향 이동*/
int dx[] = { -1,-1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
bool is_valid(int x, int y) { return (x >= 0 && x < N && y >= 0 && y < M); }
void BFS(int x, int y) {
        visited[x][y] = true;
        queue<pair<int, int>> que;
        que.push({ x,y });
        while (!que.empty()) {
                int now_x = que.front().first;
                int now_y = que.front().second;
                que.pop();
                /*현재 위치에서부터 시계방향으로 8방향 빈공간 탐색*/
                for (int i = 0; i < 8; i++) {
                        int next_x = now_x + dx[i], next_y = now_y + dy[i];
                        if (is_valid(next_x, next_y) && !space[next_x][next_y]) {/*빈공간만*/
                                if (!visited[next_x][next_y]) {
                                        visited[next_x][next_y] = true;
                                        int dt = dist[now_x][now_y] + 1;
                                        /*dist[nx][ny]==0이면 방문한적 없는 곳
                                        방문한적 있는 곳이면 최단거리로 갱신*/
                                        if (dist[next_x][next_y]) dist[next_x][next_y] = min(dist[next_x][next_y], dt);
                                        else dist[next_x][next_y] = dt;
                                        que.push({ next_x, next_y });
                                }
                        }
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) cin >> space[i][j];
        }
        /*상어가 있는 곳에서 다른 빈 공간까지의 안전거리(최단거리)*/
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        memset(visited, false, sizeof(visited));/*visited 배열 0 초기화*/
                        if (space[i][j] == 1) BFS(i, j);
                }
        }
        for (int i = 0; i < N; i++) {/*안전거리의 최댓값*/
                for (int j = 0; j < M; j++) ans = max(ans, dist[i][j]);
        }
        cout << ans << endl;
}