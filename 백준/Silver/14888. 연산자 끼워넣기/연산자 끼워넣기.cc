#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define OPRD_SIZE 12
#define OPTR_SIZE 4
int oprd[OPRD_SIZE], optr[OPTR_SIZE];//피연산자, 연산자
int N, mx = INT_MIN, mn = INT_MAX;
void solve(int result, int oprd_idx) {
        if (oprd_idx == N) {
                mx = max(mx, result);
                mn = min(mn, result);
                return;
        }
        for (int i = 0; i < OPTR_SIZE; i++) {
                if (optr[i] > 0) {
                        optr[i]--;
                        if (i == 0)solve(result + oprd[oprd_idx], oprd_idx + 1);//덧셈
                        else if(i==1)solve(result - oprd[oprd_idx], oprd_idx + 1);//뺄셈
                        else if(i==2)solve(result * oprd[oprd_idx], oprd_idx + 1);//곱셈
                        else solve(result / oprd[oprd_idx], oprd_idx + 1);//나눗셈
                        optr[i]++;
                }
        }
}
int main()
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &oprd[i]);
        for (int i = 0; i < OPTR_SIZE; i++)scanf("%d", &optr[i]);
        solve(oprd[0], 1);
        printf("%d\n%d\n", mx, mn);
}