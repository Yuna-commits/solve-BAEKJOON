#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 1000000
#define MIN -1000000
int main()
{
        int N, max = MIN, min = MAX;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                int data; scanf("%d", &data);
                if (data > max)max = data;
                if (data < min)min = data;
        }
        printf("%d %d\n", min, max);
}