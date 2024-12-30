#include<bits/stdc++.h>
static int N;
static std::vector<int> A;

int LIS() {
    std::vector<int> C; // 증가 부분 수열의 마지막 값을 관리하는 배열
    for(int num : A) {
        auto pos = std::lower_bound(C.begin(), C.end(), num);
        if(pos == C.end()) C.push_back(num);
        else *pos = num;
    }
    return C.size();
}

int main(void) {
    std::cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++) {
        std::cin >> A[i]; 
    }
    std::cout << LIS() ;
}