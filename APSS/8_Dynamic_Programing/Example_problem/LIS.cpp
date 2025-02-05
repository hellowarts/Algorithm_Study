// 예제: 최대 증가 부분 수열 (문제 ID: LIS, 난이도: 하)
#include <bits/stdc++.h>
/*
구현 아이디어
- 최대 증가 부분 수열을 찾기 위해 수열 첫 글자 A[j]를 골랐다고 하자.
  이때 A[j]로 시작하는 최대 증가 부분 수열은 A[j] 이후의 수열 중 
  A[j] 보다 큰 숫자들로 이루어진 부분 수열 B에 대한 LIS의 재귀 호풀이 될 것이다.
  즉 B의 LIS를 구할 때 A[j] 이전의 선택한 숫자들을 알 필요가 없으므로
  위 문제도 최적 부분 구조가 성립함을 알 수 있다.
*/

// 재귀적 구현 코드
// int lis(const std::vector<int>& A) {
//     // 기저 사례: A가 텅 비었을 때
//     if(A.empty()) return 0;
//     int ret = 0;
//     for(int i=0; i<A.size(); ++i) {
//         std::vector<int> B;
//         for(int j=i+1; j<A.size(); ++j) {
               // 선택한 A[i] 보다 큰 수들로 이루어진 새로운 수열 B 생성
//             if(A[i] < A[j]) B.push_back(A[j]);
//         }
//         ret = std::max(ret, 1 + lis(B));
//     }
//     return ret;
// }

/*
메모이제이션 적용
- 메모이제이션을 당장 적용하기에는 위 코드의 입력이 배열인 것을 알 수 있다.
  그렇기에 A라는 배열 데이터를 좀 더 간단한 표현으로 바꿔야 한다.
  다음은 A의 2가지 표현이다. 
    1. 원래 주어진 수열 S
    2. 원래 주어진 수열의 원소 S[i]에 대해, S[i+1...] 부분 수열에서 S[i]보다 큰 수들만을 포함하는 부분 수열
    여기서 2번 정의는 이전에 선택한 수들의 정의에 포함되지 않는 것이 중요하다.
    고로 부분 문제의 정의를 수열 S의 start 이후 부터의 LIS로 정의한다면 다음과 같다.
    lis(start) = S[start]
*/

// 메모이제이션을 적용한 코드
// int n;
// int cache[502], S[501];
// // S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환
// int lis2(int start) {
//     int& ret = cache[start+1];
//     if(ret != -1) return ret;
//     // 항상 S[start]는 있기 때문에 길이는 최하 1
//     ret = 1;
//     // 0부터 시작함을 구현하기 위해 가상의 값 -1에 대한 경우를 추가한다.
//     for(int next = start+1; next < n; ++next){
//         if(start == -1 || S[start] < S[next]) {
//             ret = std::max(ret, lis2(next)+1);
//         }
//     }
//     return ret;
// }

// 더 빠른 해법
int lis_fast(const std::vector<int>& S) {
    std::vector<int> C; // 증가 부분 수열의 마지막 값을 관리하는 배열
    for(int num : S) {
        // C에서 num이 들어갈 위치를 이진 탐색으로 찾음
        auto pos = std::lower_bound(C.begin(), C.end(), num);
        if(pos == C.end()) {
            // num이 C의 마지막 값보다 크면 추가
            C.push_back(num);
        }
        else {
            // num이 C[pos]을 대체
            *pos = num;
        }
    }
    return C.size(); // LIS의 길이
}

int main() {
    int C;
    std::cin >> C;
    while (C--) {
        int n;
        std::cin >> n;
        std::vector<int> S(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> S[i];
        }
        std::cout << lis_fast(S) << "\n";
    }
    return 0;
}