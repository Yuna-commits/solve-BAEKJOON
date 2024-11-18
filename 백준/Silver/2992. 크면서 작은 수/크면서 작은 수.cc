/*for문만 사용하면 X 자리수 len만큼 len개의 반복문 사용해야 함
=> 156이면 for문 3개, 27711이면 for문 5개 사용
=> 재귀 사용해서 줄이기
구성 숫자로 만들 수 있는 모든 수를 만들고 정렬해서 가장 작은 수 출력
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define NUM_SIZE 6
using namespace std;
string X;
vector<int>vec;
int len, chk[NUM_SIZE] = { 0, }; //X의 각 자리 수를 사용했는지 확인
void solve(string tmp, int idx) {
        if (idx == len) {
                //X보다 큰 경우에만 벡터에 넣음
                if (stoi(tmp) > stoi(X)) vec.push_back(stoi(tmp));
                return;
        }
        for (int i = 0; i < len; i++) {
                if (chk[i] == 0) {
                        chk[i] = 1;
                        solve(tmp + X[i], idx + 1);
                        chk[i] = 0;
                }
        }
        return;
}
int main()
{
        cin >> X;
        len = X.length();
        solve("", 0);
        sort(vec.begin(), vec.end());
        //만들 수 있는 수가 없으면 벡터가 비어있음
        if (!vec.empty()) cout << vec.front() << endl;
        else cout << 0 << endl;
}