#include<iostream>
#include<string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
class Robot {
public:
        int M;//영역 s의 범위
        int x, y;//현재 위치, 초기값 (0, 0)
        char nowD;//현재 방향, 초기값 e
        Robot() {
                M = 0; x = 0; y = 0;
                nowD = 'e';
        }
        void setDirection(int dir) {
                if (dir) {//오른쪽 90도 회전
                        switch (nowD) {
                        case 'e':  nowD = 'n'; break;
                        case 'w':  nowD = 's'; break;
                        case 'n':  nowD = 'w'; break;
                        case 's':  nowD = 'e'; break;
                        }
                }
                else {//왼쪽 90도 회전
                        switch (nowD) {
                        case 'e':  nowD = 's'; break;
                        case 'w':  nowD = 'n'; break;
                        case 'n':  nowD = 'e'; break;
                        case 's':  nowD = 'w'; break;
                        }
                }
        }
        int moveRobot(int d) {//유효하지 않으면 return 0
                switch (nowD) {
                case 'e': y += d; break;
                case 'w': y -= d; break;
                case 'n': x -= d; break;
                case 's': x += d; break;
                }
                if (x<0 || x>M || y<0 || y>M) return 0;
                else return 1;
        }
};
int main() {
        fastio;
        Robot rob;
        string cmd;
        int n, d;
        cin >> rob.M >> n;
        for (int i = 0; i < n; i++) {
                cin >> cmd >> d;
                if (cmd == "MOVE") {
                        if (!rob.moveRobot(d)) {
                                cout << -1;
                                return 0;
                        }
                }
                else rob.setDirection(d);
        }
        cout << rob.y << " " << rob.x;
}