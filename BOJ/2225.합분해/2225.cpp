#include<bits/stdc++.h>
static int N, K;

long long cache[201][201];
long long combin_decomp(int k, int n) {
    for(int i=0; i<=n; i++) cache[1][i] = 1;
    
    for(int i=2; i<=k; i++) {
        for(int j=0; j<=n; j++) {
            for(int l=0; l<=j; l++) 
                cache[i][j] += cache[i-1][l];
            cache[i][j] %= 1000000000;
        }
    }
    return cache[K][N];
}

int main(void) {
    std::cin >> N >> K;
    std::cout << combin_decomp(K, N);
}