#include<bits/stdc++.h>
static int N;
static int array[100001];
static int sum[100001];

int main(void) {
    std::cin >> N;
    for(int i = 1; i <= N; i++)
        std::cin >> array[i];
    for(int i = 1; i <= N; i++)
        sum[i] = array[i] + (i == 0 ? 0 : sum[i-1]);
    
    int answer = 0;
    // 벌통이 가운데 있는 경우
    for (int i = 2; i <= N-1; i++) {
        int left = sum[i] - sum[1];
        int right = sum[N - 1] - sum[i-1];
        answer = std::max(answer, left + right);
    }
    // 벌통이 왼쪽 끝에 있는 경우
    for(int i=2; i<=N-1; i++) {
        int left = sum[i - 1];
        int right = sum[N-1] - array[i];
        answer = std::max(answer, left + right);
    }
    // 벌통이 오른쪽 끝에 있는 경우
    for(int i=2; i<=N-1; i++) {
        int left = sum[N] - sum[1] - array[i];
        int right = sum[N] - sum[i];
        answer = std::max(answer, left + right);
    }

    std::cout << answer;
    return 0;
}