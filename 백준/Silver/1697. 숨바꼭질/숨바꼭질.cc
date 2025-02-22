#include<iostream>
#include<queue>
#include<cstring>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100001
using namespace std;
int graph[MAX_SIZE];
void BFS(int start, int end) {
        queue<int> que;
        que.push(start);
        graph[start] = 0;
        while (graph[end] == 0) {
                int now = que.front();
                que.pop();
                for (int next : {now + 1, now - 1, 2 * now}) {
                        if (next < 0 || next >= MAX_SIZE) continue;
                        if (graph[next] == 0 || graph[next] > graph[now] + 1) {
                                que.push(next);
                                graph[next] = graph[now] + 1;
                        }
                }
        }
}
int main()
{
        fastio;
        int N, K; cin >> N >> K;
        if (N == K) {
                cout << 0;
                return 0;
        }
            memset(graph, 0, sizeof(graph));
        BFS(N, K);
        cout << graph[K];
}