#include<bits/stdc++.h>

static int N;
static int X[3001], T[3001];

int main(void) {
    std::cin >> N;
    int Max = -1;
    for(int i=1; i<=N; i++){
        std::cin >> X[i];;
        if(Max < X[i]) Max = X[i]; 
    }
    for(int i=1; i<=N; i++) std::cin >> T[i];
    X[0] = 0;
    int ans = Max;
    for(int i=N; i; i--) {
        if(T[i] > ans) ans = T[i];
        ans += (X[i] - X[i-1]);
    }
    std::cout << ans;
}