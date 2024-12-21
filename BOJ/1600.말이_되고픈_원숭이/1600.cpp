#include<bits/stdc++.h>
struct P{
    int x, y;
    int k;
};

static int K, W, H;
static int map[201][201];
static int visited[201][201][31];
static int dx[] = {1, 0, -1, 0};
static int dy[] = {0, 1, 0, -1};
static int Ndx[] = {-1, 1, -1, 1, -2, -2, 2, 2};
static int Ndy[] = {2, 2, -2, -2, 1, -1, 1, -1};

int BFS(int x, int y);

int main(void) {
    std::cin >> K;
    std::cin >> W >> H;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) 
            std::cin >> map[i][j];
    }
    std::cout << BFS(0, 0);
    return 0;
}

int BFS(int x, int y){
    std::queue<P> q;
    q.push({x, y, 0});
    while(!q.empty()) {
        P now = q.front();
        q.pop();

        if(now.x == W-1 && now.y == H-1) 
            return visited[now.y][now.x][now.k];

        if(now.k < K) {
            for(int i=0; i<8; i++) {
                int nx = now.x + Ndx[i];
                int ny = now.y + Ndy[i];

                if(nx<0 || nx>=W || ny<0 || ny>=H) continue;
                if(visited[ny][nx][now.k+1] || map[ny][nx]) continue;

                visited[ny][nx][now.k+1] = visited[now.y][now.x][now.k] + 1;
                q.push({nx, ny, now.k+1});
            }
        }
        for(int i=0; i<4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if(nx<0 || nx>=W || ny<0 || ny>=H) continue;
            if(visited[ny][nx][now.k] || map[ny][nx]) continue;

            visited[ny][nx][now.k] = visited[now.y][now.x][now.k] + 1;
            q.push({nx, ny, now.k});
        }
    }
    return -1;
}