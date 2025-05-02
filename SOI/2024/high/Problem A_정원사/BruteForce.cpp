#include<bits/stdc++.h>

int n;
long long k; // 0 ≤ k ≤ 1,000,000,000  (10^9)
std::vector<long long> trees;

int main() {
    std::cin >> n >> k;

    trees.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> trees[i];
    }

    int result = 0;

    while (true) {
        int max_idx = -1; // 가장 큰 나무의 인덱스
        long long max_height = -1; // 가장 큰 나무의 높이

        // 가장 큰 나무 찾기
        for (int i = 0; i < n; i++) {
            if (trees[i] <= k || trees[i] <= max_height) continue; 
            max_height = trees[i];
            max_idx = i;
        }

        if (max_idx == -1) break;  // 모두 k 이하라면 종료

        trees[max_idx] /= 2;
        result++;
    }

    std::cout << result << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << trees[i];
        if (i != n - 1) std::cout << ' ';
    }

    return 0;
}