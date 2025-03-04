#include<iostream>
#include<queue>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int h, w;
//< ^ > 시계방향
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1,-1,0, 1, 1, 1, 0, -1 };
int map[50][50], visited[50][50];
void BFS(int x, int y) {
        queue<pair<int, int>> que;
        que.push({ x,y });
        visited[x][y] = 1;
        while (!que.empty()) {
                pair<int, int> now = que.front();
                que.pop();
                for (int i = 0; i < 8; i++) {
                        int nx = now.first + dx[i];
                        int ny = now.second + dy[i];
                        if (nx<0 || nx>=w || ny<0 || ny>=h)
                                continue;
                        if (map[nx][ny] == 0 || visited[nx][ny] == 1)
                                continue;
                        que.push({nx, ny});
                        visited[nx][ny] = 1;
                }
        }
}
int main()
{
        fastio;
        while (1) {
                //입력
                cin >> h >> w;
                if (w == 0 && h == 0) break;
                fill(&map[0][0], &map[50][0], 0);
                for (int i = 0; i < w; i++) {
                        for (int j = 0; j < h; j++) cin >> map[i][j];
                }
                //탐색
                fill(&visited[0][0], &visited[50][0], 0);
                int cnt = 0;
                for (int i = 0; i < w; i++) {
                        for (int j = 0; j < h; j++) {
                                if (map[i][j] == 1 && visited[i][j] == 0) {
                                        BFS(i, j);
                                        cnt++;
                                }
                        }
                }
                cout << cnt << "\n";
        }
}