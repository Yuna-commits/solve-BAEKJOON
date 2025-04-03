#include<iostream>
using namespace std;
int arr[1000001] = { 0, };
int main() {
        int M, N; cin >> M >> N;
        for (int i = 2; i <= N; i++) arr[i] = i;
        //에라토스테네스의 체(소수 판별 알고리즘)
        //배수에 해당하는 수(소수 아님)이면 0으로 바꿈
        for (int i = 2; i <= N; i++) {
                if (arr[i] == 0) continue;
                for (int j = 2 * i; j <= N; j += i) arr[j] = 0;
        }
        for (int i = M; i <= N; i++) {
                if (arr[i] == 0) continue;
                cout << i << "\n";
        }
}