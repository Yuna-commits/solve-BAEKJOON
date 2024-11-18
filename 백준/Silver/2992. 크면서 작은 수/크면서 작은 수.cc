/*string은 덧셈으로 문자열 만들 수 있음
string str="abc", string arr[]={"a","b","c"}일 때
str[i]는 char 타입, arr[i]는 string 타입으로 서로 비교할 수 없음
=> string tmp="" 빈 문자열을 만들고 tmp에 str[i]를 붙여서 비교할 수 있음*/
#include<iostream>
#include<string>
#define min(a,b)(a<b?a:b)
#define NUM_SIZE 6
#define INF 1000000
using namespace std;
string X;
int len, visited[NUM_SIZE] = { 0, }, ans = INF;
void solve(string tmp, int idx) {
        if (tmp == X) return;
        if (idx == len) {
                if (tmp > X) {
                        ans = min(ans, stoi(tmp));
                        return;
                }
        }
        for (int i = 0; i < len; i++) {
                if (visited[i] == 0) {
                        visited[i] = 1;
                        solve(tmp + X[i], idx + 1);
                        visited[i] = 0;
                }
        }
        return;
}
int main()
{
        cin >> X;
        len = X.length();
        solve("", 0);
        if (ans != INF) cout << ans << endl;
        else cout << 0 << endl;
}