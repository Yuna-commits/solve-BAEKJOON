#include<iostream>
#include<queue>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N_SIZE 100
using namespace std;
int N;
char grid[N_SIZE][N_SIZE];
int visited[N_SIZE][N_SIZE];
int dx[] = { 0,-1,0,1 }, dy[] = { -1,0,1,0 };
//type: 0 -> 색약o, 1 -> 색약x
void BFS(int x, int y, int type) {
        queue<pair<int, int>> que;
        que.push({ x,y });
        visited[x][y] = 1;
        char color = grid[x][y];//기준 색
        while (!que.empty()) {
                pair<int, int> now = que.front(); que.pop();
                for (int i = 0; i < 4; i++) {
                        int nx = now.first + dx[i];
                        int ny = now.second + dy[i];
                        //색약이면 빨강==초록으로 취급
                        if (!type) {
                                if ((color == 'R' && grid[nx][ny] == 'G') || (color == 'G' && grid[nx][ny] == 'R'))
                                        grid[nx][ny] = color;
                        }
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                                continue;
                        if (visited[nx][ny]||grid[nx][ny]!=color)
                                continue;
                        que.push({ nx, ny });
                        visited[nx][ny] = 1;
                }
        }
}
int main()
{
        fastio;
        cin >> N;
        fill(&grid[0][0], &grid[N][0], 0);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) cin >> grid[i][j];
        }
        int ans1 = 0, ans2 = 0;
        //색약x
        fill(&visited[0][0], &visited[N][0], 0);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (!visited[i][j]) {
                                BFS(i, j, 1);
                                ans1++;
                        }
                }
        }
        //색약o
        fill(&visited[0][0], &visited[N][0], 0);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (!visited[i][j]) {
                                BFS(i, j, 0);
                                ans2++;
                        }
                }
        }
        cout << ans1 << " " << ans2;
}