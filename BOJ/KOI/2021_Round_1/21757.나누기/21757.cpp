#include<bits/stdc++.h>

static int N;
static int array[100001];
static int sum[100001];
static long long int dp[4];

int main(void) {

    std::cin >> N;
    for(int i = 0; i < N; i++)
        std::cin >> array[i];

    // 0 ~ N-1까지의 합을 구해 놓는다.
    sum[0] = array[0];
    for(int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + array[i];

    long long int answer = 0;
    if(sum[N-1] % 4 == 0) {
        dp[0] = 1;
        int val = sum[N-1] / 4; // 4등분한 값

        for (int i=0; i<N-1; i++) {
            for (int j=3; j>0; j--) {
                if (sum[i] == val*j) 
                    dp[j] += dp[j-1];
            }
        }
        answer = dp[3];
    }  
    std::cout << answer;

    return 0;
}