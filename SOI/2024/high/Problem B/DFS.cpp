#include<bits/stdc++.h>

int n, result = 0;
std::vector<std::string> grid;
std::string target = "SJOI";

int dx[8] = {-1, -1, -1,  0, 1, 1, 1,  0};
int dy[8] = {-1,  0,  1,  1, 1, 0, -1, -1};

void dfs(int x, int y, int deepth) {
    if (deepth == 3) {  // 마지막 문자 'I'까지 도달한 경우
        result++;
        return;
    }

    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (grid[nx][ny] == target[deepth + 1]) {
                dfs(nx, ny, deepth + 1);
            }
        }
    }
}

int main() {
    std::cin >> n;
    grid.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'S') {
                dfs(i, j, 0);  // 시작 인덱스는 0: 'S'
            }
        }
    }

    std::cout << result;
    return 0;
}
