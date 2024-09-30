#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int N;
int* temp;
int is_Prime(int* temp, int size) {
        int num = 0, exp = size;
        for (int i = 0; i < size; i++) num += temp[i] * pow(10, --exp);
        for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0)return 0;
        }
        return 1;
}
void solve(int idx) {
        if (idx == N) {
                for (int i = 0; i < N; i++)printf("%d", temp[i]);
                printf("\n");
                return;
        }
        for (int bt = 1; bt < 10; bt++) {
                if (idx == 0 && bt == 1)continue;
                temp[idx] = (char)bt;
                if (is_Prime(temp, idx + 1)) solve(idx + 1);
        }
}
int main()
{
        scanf("%d", &N);
        temp = (int*)calloc(N, sizeof(int));
        solve(0);
}