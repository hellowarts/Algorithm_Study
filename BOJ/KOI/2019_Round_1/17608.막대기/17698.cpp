#include<bits/stdc++.h>
static int N;
static int sticks[100001];

int main(void) {
    std::cin >> N;
    for(int i=0; i<N; i++) {
        std::cin >> sticks[i];
    }

    int answer = 0;
    int max = 0;
    for(int i=N-1; i>=0; i--) {
        if(sticks[i] > max){
            max = sticks[i];
            answer++;
        }
    }
    
    std::cout << answer;

    return 0;
}