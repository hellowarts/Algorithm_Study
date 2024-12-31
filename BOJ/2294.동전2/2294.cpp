#include<bits/stdc++.h>
static int n, k;
static std::vector<int> coin;

int cache[10001];
int min_coin(int total) {
    if(total == 0) return 0;
    int& ret = cache[total];
    if(ret != -1) return ret;
    ret = 1000001;
    for(int i=0; i<n; i++) {
        if(total-coin[i] >= 0)
            ret = std::min(ret, min_coin(total-coin[i])+1);
    }
    return ret;
}

int main(void) {
    std::cin >> n >> k;
    coin.resize(n);
    for(int i=0; i<n; i++) std::cin >> coin[i];

    memset(cache, -1, sizeof(cache));
    int ret = min_coin(k);
    if(ret != 1000001) std::cout << ret;
    else std::cout << -1;
}