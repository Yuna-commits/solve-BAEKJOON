#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MAX_N 1001
#define MAX_M 11
int N, M;
int A[MAX_M], B[MAX_M], C[MAX_M], D[MAX_M];
int Bound[MAX_M]; //만들 수 있는 만두 개수
//i번째 만두를 j개까지 만들어 k그램의 밀가루를 사용했을 때의 최대 가치
int DP[MAX_M * MAX_N][MAX_N];
int idx = 1, ans = 0;
int main()
{
     scanf("%d%d%d%d", &N, &M, &C[0], &D[0]);
     for (int i = 1; i <= M; i++)scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
     Bound[0] = N / C[0];
     for (int i = 1; i <= M; i++) Bound[i] = min((A[i] / B[i]), (N / C[i]));
     for (int i = 0; i <= M; i++) {//i번째 만두
          for (int j = 1; j <= Bound[i]; j++) {//i번째 만두의 만들 수 있는 개수
               for (int k = N; k >= 0; k--) {
                    //만두를 만들 밀가루가 남아있는 경우
                    //(idx-1번째)만두만 만들었을 떄의 금액과
                    //(idx-1번째)만두를 x개 빼고 idx번째 만두를 추가로 x개 만들었을 때의 금액 비교
                    if (k - C[i] >= 0)DP[idx][k] = max(DP[idx - 1][k], D[i] + DP[idx - 1][k - C[i]]);
                    else DP[idx][k] = DP[idx - 1][k];
                    ans = max(ans, DP[idx][k]);
               }
               idx++;
          }
     }
     printf("%d\n", ans);
}