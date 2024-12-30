// 문제: 합친 LIS (문제 ID: JLIS, 난이도: 하)
#include<bits/stdc++.h>
/*
문제 해결 아이디어
- 단순히 두 LIS를 합치는 방향으로는 문제를 해결할 수 없다.
  당장 3번째 예시만 하더라도 첫 번째 순열에서 최선의 선택인 10, 20, 30이 아닌 1, 2를 선택해야하기 때문이다.
    고로 우리는 LIS 문제에서의 정의식을 참조하여 새로운 정의식을 다음과 같이 정의해야 한다.
    - jlis(indexA, indexB) : A[inexA]와 B[indexB]에서 시작하는 합친 증가 부분 수열의 최대 길이
      jlis(indexA, indexB) = max(max(jlis(nextA, indexB)+1)
                                 max(jlis(indexA, nextB)+1))
*/

// 입력이 32비트 부호 있는 정수의 모든 갑3ㅅ을 가질 수 있으므로
// 인위적인 최소치는 64비트여야 한다.
const long long NEGINF = std::numeric_limits<long long>::min();
int n, m, A[101], B[101];
int cache[102][102];
// min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로 시작하는
// 합친 증가 부분 수열의 최대 길이를 반환한다.
// 단 indexA == indexB == -1 혹은 A[indexA] != B[indexB]라고 가정한다.
int jlis(int indexA, int indexB) {
    // 메모이제이션
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;
    // A[indexA], B[indexB]가 이미 존재하므로 2개는 항상 있다.
    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElment = std::max(a, b);
    // 다음 원소를 찾는다.
    for(int nextA = indexA+1; nextA < n; ++nextA){
        if(maxElment < A[nextA]) 
            ret = std::max(ret, jlis(nextA, indexB)+1);
    }
    for(int nextB = indexB+1; nextB < m; ++nextB){
        if(maxElment < B[nextB]) 
            ret = std::max(ret, jlis(indexA, nextB)+1);
    }
    return ret;
}

int main() {
    int C;
    std::cin >> C;
    while (C--) {
        memset(cache, -1, sizeof(cache));
        std::cin >> n >> m;
        for(int i=0; i<n; i++) std::cin >> A[i];
        for(int i=0; i<m; i++) std::cin >> B[i];
        std::cout << jlis(-1, -1) - 2 << "\n";
    }
    return 0;
}