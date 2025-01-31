#include<bits/stdc++.h>
static int N, K;

int main(void) {
    std::cin >> N >> K;
    // 1부터 N까지의 합
    int SUM = K * (K + 1) / 2;
    // 1부터 K까지 오름 차순으로 채워 넣을 수 없다면 불가능
    if (N < SUM) {
        std::cout << -1;
        return 0;
    }
    // 만약 오름 차순으로 공을 채우고도 공이 남는다면
    // 각 공마다 같은 비율로 공을 추가하면 최소와 최대 차는 K-1
    // 그렇지 않으면 K가 된다.
    if((N-SUM)%K==0) std::cout << K-1;
    else std::cout << K;

    return 0;
}