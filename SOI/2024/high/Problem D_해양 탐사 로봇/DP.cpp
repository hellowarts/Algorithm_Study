#include <bits/stdc++.h>

const int MAX = 31;
int n;
int A[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
long long dp[MAX][MAX][MAX];

// 방향: x+, y+, z+
const int dx[3] = {1, 0, 0};
const int dy[3] = {0, 1, 0};
const int dz[3] = {0, 0, 1};

// 경로 저장용
struct Pos {
    int x, y, z;
};

// forward DP + 경로 저장
std::vector<Pos> forward_path() {
    memset(dp, 0, sizeof(dp));
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            for (int z = 1; z <= n; ++z) {
                dp[x][y][z] = std::max({
                    dp[x-1][y][z],
                    dp[x][y-1][z],
                    dp[x][y][z-1]
                }) + A[x][y][z];
            }

    // 경로 역추적
    std::vector<Pos> path;
    int x = n, y = n, z = n;
    while (!(x == 1 && y == 1 && z == 1)) {
        path.push_back({x, y, z});
        if (x > 1 && dp[x][y][z] == dp[x-1][y][z] + A[x][y][z]) --x;
        else if (y > 1 && dp[x][y][z] == dp[x][y-1][z] + A[x][y][z]) --y;
        else --z;
    }
    path.push_back({1, 1, 1});
    std::reverse(path.begin(), path.end());
    for (const auto& p : path) visited[p.x][p.y][p.z] = true;
    return path;
}

// backward DP + visited 확인
long long backward_collect() {
    memset(dp, 0, sizeof(dp));
    for (int x = n; x >= 1; --x)
        for (int y = n; y >= 1; --y)
            for (int z = n; z >= 1; --z) {
                long long gain = visited[x][y][z] ? 0 : A[x][y][z];
                dp[x][y][z] = std::max({
                    dp[x+1][y][z],
                    dp[x][y+1][z],
                    dp[x][y][z+1]
                }) + gain;
            }
    return dp[1][1][1];
}

int main() {
    std::cin >> n;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            for (int z = 1; z <= n; ++z)
                std::cin >> A[x][y][z];

    std::vector<Pos> _ = forward_path();
    long long total = 0;
    for (const auto& p : _) total += A[p.x][p.y][p.z];
    total += backward_collect();

    std::cout << total << '\n';
    return 0;
}
