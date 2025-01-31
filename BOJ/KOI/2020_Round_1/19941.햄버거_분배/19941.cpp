#include<bits/stdc++.h>

static int N, K;
static char pos[20001];
bool visited[20001];

int main(void) {
    
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> pos[i];
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        if(pos[i] == 'P') {
            for(int j = i - K; j <= i + K; j++) {
                // 만약 현재 위치가 범위 밖이면 넘어간다.
                if(j < 0 || j >= N) continue;
                // 자리에 햄버거가 있고 먹은적이 없다면 먹는다.
                if(pos[j] == 'H' && !visited[j]) {
                    visited[j] = true;
                    answer++;
                    break;
                }
            }
        }
    }

    std::cout << answer;

    return 0;
}