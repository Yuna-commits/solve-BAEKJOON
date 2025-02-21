#include<iostream>
#include<queue>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001
using namespace std;
int graph[MAX_SIZE];
void BFS(int start, int end) {
        queue<int> que;
        que.push(start);
        graph[start] = 1;
        while (graph[end] == 0) {
                int now = que.front();
                que.pop();
                if (now + 1 <= 1000000) {
                        if (graph[now + 1] == 0 || graph[now + 1] > graph[now] + 1) {
                                que.push(now + 1);
                                graph[now + 1] = graph[now] + 1;
                        }
                }
                if (now * 2 <= 1000000) {
                        if (graph[now * 2] == 0 || graph[now * 2] > graph[now] + 1) {
                                que.push(now * 2);
                                graph[now * 2] = graph[now] + 1;
                        }
                }
        }
}
int main() {
        fastio;
        int A, K;
        cin >> A >> K;
        BFS(A, K);
        cout << graph[K] - 1;
}