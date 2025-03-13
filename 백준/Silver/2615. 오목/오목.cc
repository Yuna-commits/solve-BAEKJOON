#include<iostream>
#define MAX_SIZE 20
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
//탐색 방향: "연속"된 방향으로 위->아래, 왼->오, 우상향/우하향 대각
//연속된 다섯알이 존재하는 dfs의 "시작 좌표(가장 왼쪽의 돌)" 구하기
//-> 여섯알인 경우를 주의??? -> 연속된 돌의 앞, 뒤쪽 끝도 확인
//xx(xxxxx) -> 여섯 알 이상으로 연속된 돌이기 때문에 해당 안됨
//따라서 탐색 시작 위치의 앞과, 끝난 위치의 뒤도 탐색해야함
int dx[] = { -1, 0, 1, 1 };
int dy[] = { 1,1,1,0 };
int Baduk[MAX_SIZE][MAX_SIZE];
int ansX, ansY;
int isValid(int x, int y) {
        return (0 < x && x < MAX_SIZE && 0 < y && y < MAX_SIZE);
}
int solve(int x, int y) {
        for (int dir = 0; dir < 4; dir++) {//dir 한 방향으로 계속 탐색
                int cnt = 1;
                int nx = x + dx[dir], ny = y + dy[dir];
                while (1) {//뒤쪽 끝까지 탐색
                        if (!isValid(nx, ny)||Baduk[x][y] != Baduk[nx][ny]) break;//연속된 돌이 아님
                        cnt++;
                        if (cnt == 5) {
                                //앞쪽
                                if (isValid(x - dx[dir], y - dy[dir]) && Baduk[x - dx[dir]][y - dy[dir]] == Baduk[x][y])
                                        break;
                                //뒤쪽
                                if (isValid(nx + dx[dir], ny + dy[dir]) && Baduk[nx + dx[dir]][ny + dy[dir]] == Baduk[x][y])
                                        break;
                                return 1;
                        }
                        nx += dx[dir]; ny += dy[dir];
                }
        }
        return 0;
}
int main()
{
        fastio;
        for (int i = 1; i < MAX_SIZE; i++) {
                for (int j = 1; j < MAX_SIZE; j++) cin >> Baduk[i][j];
        }
        for (int i = 1; i < MAX_SIZE; i++) {
                for (int j = 1; j < MAX_SIZE; j++) {
                        if (Baduk[i][j] == 0) continue;
                        if (solve(i, j)) {
                                cout << Baduk[i][j] << "\n";
                                cout << i << " " << j << "\n";
                                return 0;
                        }
                }
        }
        //승부가 안 났으면 0 출력
        cout << 0;
}