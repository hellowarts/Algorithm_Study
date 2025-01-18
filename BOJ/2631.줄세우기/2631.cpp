#include<bits/stdc++.h>

static int N;
static std::vector<int> child;
static std::vector<int> dp;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N;
    child.resize(N);
    dp.resize(N, 1);

    for(int i = 0; i < N; i++) {
        std::cin >> child[i];
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(child[i] > child[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    std::cout << N - *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}