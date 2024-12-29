// 예제: 삼각형 위의 최대 경로 (문제 ID: TRIANGLEPATH, 난이도: 하)
#include <bits/stdc++.h>
/*
완전 탐색으로 시작하기
- 경로를 각 가로줄로 조각 낸 뒤, 각 조각에서 아래로 내려갈지 오른쪽으로 내려갈 지 결정한다.
    pathSum (y, x, sum) : 현재 위치가 (y, x)이고, 지금까지 만난 수의 함이 sum일 때, 경로의 최대 합 반환
    pathSum (y, x, sum) = max(path(y+1, x, sum + triangle[y][x]),
                              path(y+1, x+1, sum + triangle[y][x]))
*/ 

// 메모이제이션으로만 푼 문제
// 한 칸에 들어갈 숫자의 최대치 
// const int MAX_NUMBER = 10;
// int n, triangle[100][100];
// int cache[100][100][MAX_NUMBER*100+1];
// int path1(int y, int x, int sum) {
//     // 기저 사례: 맨 아래 줄까지 도달했을 경우
//     if(y == n-1) return sum + triangle[y][x];
//     // 메모이제이션
//     int& ret = cache[y][x][sum];
//     if(ret != -1) return ret;
//     sum += triangle[y][x];
//     return ret = std::max(path1(y+1, x+1, sum), path1(y+1, x, sum));
// }

/*
입력 걸러내기
- 현재 코드로는 cache에 의해 저장해야할 메모리가 너무 많아지게 된다. cache의 구조를 분석해 보면
    1. y와 x : 재귀 호출로 풀어야 할 부분 문제를 결정
    2. sum : 지금까지의 풀었던 조각들에 대한 정보
    즉 sum이라는 정보는 앞으로 남은 조각들을 풀이하는데 아무런 도움이 되지 않음을 알 수 있다.
    그렇기에 재귀식을 다시 표현해자면 다음과 같을 것이다.

    path2(y, x) : (y, x)에서 시작하여 맨 아래줄까지 내려가는 부분 경로의 최대 합 반환
    path2(y, x) = triangle[y][x] + max(path2(y+1, x), path(y+1, x+1))
*/

int n, triangle[100][100];
int cache[100][100];
int path2(int y, int x) {
    // 기저 사례: 맨 아래 줄까지 도달했을 경우
    if(y == n-1) return triangle[y][x];
    // 메모이제이션
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = triangle[y][x] + std::max(path2(y+1, x+1), path2(y+1, x));
}

int C;
int main(void) {
    std::cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        std::cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i+1; j++) 
                std::cin >> triangle[i][j];
        }
        std::cout << path2(0, 0) << "\n";
    }
}