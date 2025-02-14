#include<bits/stdc++.h>

const int INF = 987654321;

int main(void) {
    int N;
    std::cin >> N;
    int Min = INF;
    
    while(N--) {
        int A, B;
        std::cin >> A >> B;
        if(A <= B && B < Min) Min = B;
    }
    if(Min == INF) std::cout << -1;
    else std::cout << Min;

    return 0;
}