// 예제: 타일링 방법의 수 세기 (문제 ID: TILING2, 난이도: 하)
#include <bits/stdc++.h>
/*
구현 아이디어
- 우선 완전 탐색을 이용해 모든 답을 만들면서 개수를 세어 보는 함수를 작성한다.
  그 후 메모이제이션을 이용해 DP 알고리즘으로 바꾸면 된다.

  재귀 호출을 이용해 모든 타일링 방법을 만들기 위해서는 맨 왼쪽 세로 줄이 어떻게 채워지는냐에 따라 결정된다.
  따라서 왼쪽 세로 줄이 채워지는 방법에 따라 2가지 경우로 나누어 볼 수 있다.
    1. 왼쪽 세로 줄이 1개의 타일로 채워진 경우
    2. 왼쪽 세로 줄이 2개의 타일로 채워진 경우

  이때 다음의 조건들이 성립합을 알 수 있다.abort
  - 이 두가지 분류는 타일링하는 방법을 모두 포함한다.
  - 이 두가지 분류는 서로 겹치지 않는다.

  고로 각 단계에서 세로줄을 세로 타일 하나로 덮을 것인지 가로 타일 두 개로 덮을 것인지를 결정하기만 하면 된다.
  이 때 남은 공간은 각각 2 X (n - 1) 칸과 2 X (n - 2) 칸이 되므로 재귀식은 다음과 같아 진다.abort

  tiling(n) = tiling(n - 1) + tiling(n - 2)
*/ 

const int MOD = 1000000007;
int cache[101];
// 2 X n 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: 너비가 1이하하면 바로 끝난다.
    if(width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    if(ret != -1) return ret;
    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

int main(void) {
    int C;
    std::cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        int n;
        std::cin >> n;
        std::cout << tiling(n) << "\n";
    }
}