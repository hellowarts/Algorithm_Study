#include<bits/stdc++.h>
int map[101][101];
long long cache[101][101];
static int N;
long long jump(int y, int x) {
    if(x == N-1 && y == N-1) return 1;

    long long& ret = cache[y][x];
    if(ret != -1) return ret;
    
    ret = 0;
    int jumpSize = map[y][x];
    if(jumpSize == 0) return ret;
    if(y + jumpSize < N) ret += jump(y + jumpSize, x);
    if(x + jumpSize < N) ret += jump(y, x + jumpSize);

    return ret;
} 
int main(void) {
    std::cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            std::cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    std::cout << jump(0, 0);
}