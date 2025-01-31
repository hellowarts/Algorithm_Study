#include<bits/stdc++.h>
static int n;
static std::vector<std::pair<int, int>> pos;

int main(void) {
    std::cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        std::cin >> x >> y;
        pos.push_back({x, y});
    }

    return 0;
}