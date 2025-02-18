#include<bits/stdc++.h>

const int MAX_N = 100;
int n, m;
int cache[MAX_N][2*MAX_N+1];
// 달팽이가 days일 동안 climbed미터를 기어올라 왔다고 할 때,
// 달팽이가 m일째에 n미터를 기어올라갈 수 있는 경우의 수
int climb(int days, int climbed) {
    // 기저 사례: m일이 모두 지난 경우
    if(days == m) return climbed >= n ? 1 : 0;
    // 메모이제이션
    int& ret = cache[days][climbed];
    if(ret != -1) return ret;
    return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}

/// climb 함수를 통해 얻어진 결과값에 2^m을 나누면 n미터를 넘을 확률이 된다.