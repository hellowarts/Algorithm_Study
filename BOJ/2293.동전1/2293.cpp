#include<bits/stdc++.h>
static int n, k;
static std::vector<int> coin;

int cache[10001];
int total_coin(int total) {
    cache[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<=k; j++) {
            cache[j] += cache[j-coin[i]];
        }
    }
    return cache[k];
}

int main(void) {
    std::cin >> n >> k;
    coin.resize(n);
    for(int i=0; i<n; i++) {
        std::cin >> coin[i];
    }
    std::cout << total_coin(k);
}