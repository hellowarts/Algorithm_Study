#include<bits/stdc++.h>

static int N;
static std::vector<int> arr;
static std::vector<int> dp;

int main(void) {
    std::cin >> N;
    arr.resize(N+1);
    dp.resize(N+1);
    for(int i=1; i<=N; i++) std::cin >> arr[i];
    
    for(int i=1; i<=N; i++) {
        int max_val = 0, min_val = 10001;
        for(int j=i; j>0 && i-j+1<=N; j--) {
            max_val = std::max(max_val, arr[j]);
            min_val = std::min(min_val, arr[j]);
            dp[i] = std::max(dp[i], dp[j-1] + max_val - min_val);
        }
    }
    std::cout << dp[N];
} 