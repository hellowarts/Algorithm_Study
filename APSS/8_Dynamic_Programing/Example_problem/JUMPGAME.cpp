// 예제: 외발 뛰기 (문제 ID: JUMPGAME, 난이도: 하)
#include<bits/stdc++.h>
/*
재귀 호출에서 시작
- 우선 문제를 재귀적으로 핵셜하는 완전 탐색 알고리즘을 만들어 본다.
    jump(y, x) : (y, x) 에서 부터 맨 마지막 칸까지 도달할 수 있는지 여부 반환
- 이후 jump() 함수를 호출할 때 마다 아래쪽으로 갈지 오른쪽으로 갈지를 선택한다.
    jump(y, x) : jump(y+jumpSize, x) || jump(y, x+jumpSize)
*/

// 재귀 호출 알고리즘
// int n, board[100][100];
// bool jump(int y, int x) {
//     // 기저 사례: 게임 판 밖을 벗어난 경우
//     if(y >= n || x >= n) return false;
//     // 기저 사례: 마지막 칸에 도착한 경우
//     if(y == n-1 && x == n-1) return true;
//     int jumpSize = board[y][x];
//     return jump(y+jumpSize, x) || jump(y, x+jumpSize);
// }

/*
메모제이션 적용하기
- 위 재귀 함수 코드로도 문제를 풀 수 있을 것 같지만 만약 정답이 없는 경우에도 완전 탐색은 모든 경로를 탐색하기에 지수적 시간이 걸린다.
  그렇기에 중복으로 해결되는 부분 문제를 메모제이션 방식으로 없애야 한다.
*/

int n, board[100][100];
int cache[100][100];
int jump2(int y, int x) {
    // 기저 사례 처리 (jump()와 동일)
    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;
    // 메모제이션
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = jump2(y+jumpSize, x) || jump2(y, x+jumpSize);
}

void init_data(){
    memset(cache, -1, sizeof(cache));
    memset(board, 0, sizeof(board));
}

int C;
int main(void) {
    std::cin >> C;
    while(C--) {
        init_data();
        std::cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) 
                std::cin >> board[i][j];
        }
        if(jump2(0, 0)) std::cout << "YES" << "\n";
        else std::cout << "NO" << "\n";
    }
}

/*
정리
1. 주어진 문제를 완전 탐색을 이용해 해결한다.
2. 중복된 부분 문제를 한 번만 계산하도록 메모제이션을 적용한다.
*/