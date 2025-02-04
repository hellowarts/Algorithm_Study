#include<bits/stdc++.h>

static int N;
static int array[100001];
static int sum[100001];
long long int dp[5];

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
        // 전체 합이 0인 경우
        if(!sum[N-1]) {
            answer = (long long int)(((N-3) * (N-2) * (N-1)) / 6);
        }
        // 전체 합이 4의 배수인 경우
        else {
            dp[0] = 1;
            int val = sum[N-1] / 4; // 4등분한 값
            
            for(int i=0; i<N; i++) {
                int pos = sum[i] / val;
                if(sum[i] % val !=0) continue;
                if(pos < 1 || pos > 4) continue;
                dp[pos] += dp[pos-1];
            }
            answer = dp[4];
        }
    }  
    std::cout << answer;

    return 0;
}