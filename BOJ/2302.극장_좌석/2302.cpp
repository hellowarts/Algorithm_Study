#include<bits/stdc++.h>
static int N, M;
std::vector<int> cache;
int main(void) {
    std::cin >> N;
    std::cin >> M;
    cache.resize(N + 1);

    int ans = 1;
    int prev = 0;
    cache[0] = 1;
    cache[1] = 1;
    for(int i = 2; i <= N; i++) {
        cache[i] = cache[i-1] + cache[i-2];
    }
    for(int i = 0; i < M; i++) {
        int num;
        std::cin >> num;
        ans *= cache[num - prev - 1];
        prev = num;
    }
    ans *= cache[N - prev];
    std::cout << ans;
    return 0;
}