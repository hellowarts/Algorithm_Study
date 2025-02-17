#include<bits/stdc++.h>

static int N;
static int arr[2501];
int DP[2501];

int main(void) {

    std::cin >> N;
    for(int i = 1; i<=N; i++) 
        std::cin >> arr[i];
    
    for(int i=2; i<=N; i++) {
        // 1번 작업을 적용할 수 있는 수
        int remain = DP[i-1];
        int x = arr[i];
        for(int j=i-1; j; j--) {
            x = arr[j] - x;
            // 1번 쟉업을 수행할 때 값이 음수가 되어선 안된다.
            if(x < 0) break;
            // 1번 작업을 적용할 수 있는 경우 (인접한 두 수가 같은 경우) DP 업데이트
            if(!x && remain <= DP[j-1])
                remain = DP[j-1] + 1; 
        }
        DP[i] = remain;
    }

    // 최대 횟수 N번에서 1번을 적용할 수 있는 횟수를 빼면 답이 된다.
    std::cout << N - DP[N];

    return 0;
}