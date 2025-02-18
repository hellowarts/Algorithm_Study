// 예제: 장마가 찾아왔다 (문제 ID: SNAIL, 난이도: 하)
#include <bits/stdc++.h>
/*
구현 아이디어
- 기존 달팽이 문제와 다르게 비가 올 확률이 75%로 늘어났기 때문에 
  다음과 같이 ret 값을 확률에 맞는 실수 값을 곱하면 된다.
  climb2(days, climbed) = 0.25 * climb2(days+1, climbed+1) + 0.75 * climb2(days+1, climbed+2)
  */

const int MAX = 1001;

int n, m;
double cache[MAX][2*MAX+1];

double climb2(int days, int climbed) {
    // 기저 사례: m일이 모두 지난 경우
    if(days == m) return climbed >= n ? 1 : 0;
    // 메모이제이션
    double& ret = cache[days][climbed];
    if(ret != -1) return ret;
    return ret = 0.25 * climb2(days+1, climbed+1) + 0.75 * climb2(days+1, climbed+2);
}

int main(void) {
    int C;
    std::cin >> C;
    while(C--) {
        std::fill(cache[0], cache[MAX], -1);
        std::cin >> n >> m;
        printf("%.10lf\n", climb2(0, 0));
    } 
}