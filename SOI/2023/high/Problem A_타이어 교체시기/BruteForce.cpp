#include <bits/stdc++.h>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int tires[4] = {a, b, c, d};
    int over15000 = 0;

    // 2번 조건을 만족하는지 체크
    for (int i = 0; i < 4; ++i) {
        if (tires[i] >= 15000) ++over15000;
    }

    // 1번 조건을 만족하는지 체크
    bool allOver10000 = true;
    for (int i = 0; i < 4; ++i) {
        if (tires[i] < 10000) {
            allOver10000 = false;
            break;
        }
    }

    if (allOver10000 || over15000 >= 2) {
        std::cout << 0 << '\n';
    } else {
        // 남은 거리 = 10000 - 가장 많이 마모된 타이어 기준
        int minDistance = *std::min_element(tires, tires + 4);
        std::cout << 10000 - minDistance << '\n';
    }

    return 0;
}
