// 문제: 원주율 외우기 (문제 ID: PI, 난이도: 하)
#include<bits/stdc++.h>
/*
구현 아이디어
- 문제의 규칙에 의해 첫 조각의 길이는 3, 4, 5로 정해져 있다. 
  이때 3개의 부분 문제에 대한 최적해를 각각 구했다고 하면, 
  전체 문제의 최적해는 다음 세 경우 중 가장 작은 값이 될 것이다.

  1. 길이 3인 조각의 난이도 + 3글자 빼고 나머지 수열에 대한 최적해
  2. 길이 4인 조각의 난이도 + 4글자 빼고 나머지 수열에 대한 최적해
  3. 길이 5인 조각의 난이도 + 5글자 빼고 나머지 수열에 대한 최적해

  최적 부분 구조가 성립하기 때문에 앞의 부분이 어떤 식으로 쪼갰는지는 중요하지 않다.
  따라서 위 문제의 재귀식은 아래와 같이 정의가 가능하다.

  pi(begin) = min(pi(begin+3) + classify(begin, begin+2),
                 pi(begin+4) + classify(begin, begin+3),
                 pi(begin+5) + classify(begin, begin+4))
 */

const int INF = 987654321;
std::string N;

// N[begin]...N[end] 구간의 난이도를 반환한다.
int classify(int begin, int end) {
    // 숫자 조각을 가져온다.
    std::string M = N.substr(begin, end-begin+1);
    // 난이도 1: 모든 숫자가 같을 때
    if(M == std::string(M.size(), M[0])) return 1;
    // 등차수열 확인
    bool progressive = true;
    for(int i=0; i<M.size()-1; i++) {
        if(M[i+1] - M[i] != M[1] - M[0]) {
            progressive = false;
            break;
        }
    }
    // 난이도 2: 등차수열이고 공차가 1 아니면 -1이면 난이도 2
    if(progressive && std::abs(M[1] - M[0]) == 1) return 2;
    // 두 수가 번갈아 등장하는지 확인
    bool alternating = true;
    for(int i=0; i<M.size(); i++) {
        if(M[i] != M[i%2]) {
            alternating = false;
            break;
        }
    }
    // 난이도 4: 두 수가 번갈아 등장
    if(alternating) return 4;
    // 난이도 5 : 공차가 1이 아닌 등차수열의 난이도
    if(progressive) return 5;
    // 난이도 10: 이외
    return 10;
}

int cache[10002];
// 수열 N[begin...]를 외우는 방법 중 난이도의 최소 합을 출력한다.
int memorize(int begin) {
    // 기저 사례: 수열의 끝에 도달했을 경우
    if(begin == N.size()) return 0;
    // 메모이제이션
    int& ret = cache[begin];
    if(ret != -1) return ret;
    ret = INF;
    for(int L=3; L<=5; L++) {
        if(begin + L <= N.size()) {
            ret = std::min(ret, memorize(begin+L) + classify(begin, begin+L-1));
        }
    }
    return ret;
}

int main(void) {
    int C;
    std::cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        std::cin >> N;
        std::cout << memorize(0) << "\n";
    }

    return 0;
}