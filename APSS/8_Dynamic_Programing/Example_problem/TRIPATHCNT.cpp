// 예제: 삼각형 위의 최대 경로 개수 세기 (문제 ID: TRIPATHCNT, 난이도: 중)
#include <bits/stdc++.h>
/*
경로의 개수
- 삼각형의 각 위치별로 최대 경로를 구한 후 해당 위치에서 다음 경로로 이동할 때 
  반드시 2가지 경로 중 최대 경로의 크기가 높은 경로를 선택하게 되어 있다.

  예를 들어 아래와 같은 삼각형이 있다고 가정하자
  9
  5 7
  1 3 2
  3 5 5 6

  위 삼각형의 위치별 최대 경로를 path2()함수를 통해 구하면 다음과 같다.
  24
  13 15
  6  8  8
  3  5  5  6
  
  위 그림에서 (0, 0)에서 시작하는 최대 경로는 (1, 0)과 (1, 1)중 최대 경로의 크기가 더 큰 (1, 1)을 선택함을 알 수 있다.
  그러나 (1, 1)에서 시작하는 최대 경로는 어느쪽을 선택하든 상관 없기 때문에 이 때 최대 경로는 두 경우 모두를 포함함을 알 수 있다.
  이를 통해 재귀식을 세우면 다음과 같다.

  count(y, x) = if (path2(y+1, x) > path2(y+1, x+1)) : count(y+1, x)
                else if (path2(y+1, x+1) > path2(y+1, x)) : count(y+1, x+1)
                else if (path2(y+1, x+1) == path2(y+1, x)) : count(y+1, x+1) + count(y+1, x)
*/ 

int n, triangle[100][100];
int cache[100][100];
int countCache[100][100];

int path2(int y, int x) {
    // 기저 사례: 맨 아래 줄까지 도달했을 경우
    if(y == n-1) return triangle[y][x];
    // 메모이제이션
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = triangle[y][x] + std::max(path2(y+1, x+1), path2(y+1, x));
}

// (y, x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x) {
    // 기저 사례: 맨 아래줄에 도달한 경우
    if(y == n-1) return 1;
    // 메모이제이션
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
    if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
    return ret;
}

int C;
int main(void) {
    std::cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        memset(countCache, -1, sizeof(countCache));
        std::cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i+1; j++) 
                std::cin >> triangle[i][j];
        }
        std::cout << count(0, 0) << "\n";
    }
}