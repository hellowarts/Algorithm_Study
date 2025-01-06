#include<bits/stdc++.h>
static int N;
int cache[100001];
int main(void) {
    std::cin >> N;
    
    cache[1] = 3;
    cache[2] = 7;
    for(int i=3; i<=N; i++) 
        cache[i] = (2*cache[i-1] + cache[i-2]) % 9901;
    std::cout << cache[N];
}