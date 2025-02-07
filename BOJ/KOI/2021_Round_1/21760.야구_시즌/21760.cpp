#include<bits/stdc++.h>

int main(void) {

    int T;
    std::cin >> T;
    while(T--) {
        int N, M, k, D;
        std::cin >> N >> M >> k >> D;
        
        long long int A, B = 0;
        while(N*M*B*(k*(M-1)+M*(N-1))<=2*D) B++;
        if(B <= 1) {
            std::cout << "-1\n";
            continue;
        }
        A = N*M*(B-1)*(k*(M-1)+M*(N-1));
        std::cout << A / 2 <<  "\n";
    }

    return 0;
}