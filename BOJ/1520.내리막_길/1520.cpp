#include<bits/stdc++.h>
static int M, N;
static int dx[] = {1,0,-1,0};
static int dy[] = {0,1,0,-1};
int map[501][501];
int cache[501][501];

int search(int y, int x) {
    if(y == M-1 && x == N-1) return 1;
    int& ret = cache[y][x];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if(map[y][x] > map[ny][nx]) ret += search(ny, nx);
    }
    return ret;
}

int main(void) {
    std::cin >> M >> N;
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) 
            std::cin >> map[i][j];
    }
    memset(cache, -1, sizeof(cache));
    std::cout << search(0,0);
}