// 문제: Quantization (문제 ID: QUANTIZE, 난이도: 중)
#include<bits/stdc++.h>
/*
구현 아이디어
- 문제 자체를 표현하려고 하면 필요한 메모리와 시간 복잡도를 확보할 수 없기 때문에 문제의 형태를 파악해야 한다.
  예를 들어 아래와 같은 예시가 있다 가정하자 

  {1, 2, 3, 4} 
 
  위 데이터를 2개의 데이터로 양자화 하는데 당연히 {2, 2, 3, 2}와 같은 형태가 될 수 없음을 우리는 쉽게 알 수 있다.
  즉 양자화를 할 때는 연속된 숫자들을 묶어서 처리해야 한다. 
  고로 입력에 주어진 수들을 정렬한 뒤, 인접한 수 끼리 묶음으로 적절히 분할하고,
  각 묶음을 한 숫자로 표현하여 오류를 최소화 해야 한다.
  이때의 재귀식 표현은 아래와 같다.

  quantize(from, parts) = min(size = 1 ~ n)[(minError(from, from + size-1) + quantize(from + size, parts-1))]

  이제 해당 묶음의 오차 제곱을 구할 minError를 구하기 위해서 양자화될 숫자를 구하기 위해
  묶음의 모든 값의 평균을 이용하면 오차를 최소화 할 수 있음을 이해해야 한다. (식을 전개해서 나올 수 있다.)
  이때 미리 부분합을 정의하면 a~b까지의 합을 아래와 같이 구할 수 있다.
  
  pSum[b] - pSum[a-1]

  이것을 b - a + 1로 나누면 평균 m을 상수 시간 내에 구할 수 있게 된다.
  정확한 계산식이 떠오르지 않는다면 책의 p248~249를 참고하여라라
 */

 const int INF = 987654321;
 // A[]: 양자화해야 할 수열, 정렬한 상태
 // pSum[]: A[]의 부분합을 저장
 // PSqSum[]: A[]의 제곱의 부분합을 저장
 int n;
 int A[101], pSum[101], pSqSum[101];

 // A를 정렬하고 각 부분합을 계산한다.
 void precalc() {
    std::sort(A, A+n);
    pSum[0] = A[0]; pSqSum[0] = A[0]*A[0];
    for(int i=1; i<n; i++) {
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
    }
}

// A[lo] ~ A[hi] 구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산
int minError(int lo, int hi) {
    // 부분 합을 이용하여 A[lo] ~ A[hi]까지의 합, 제곱합을 구한다.
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqsum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
    // 평균을 반올림한 값으로 이 수들을 표현
    int m = int(0.5 + (double)sum / (hi - lo + 1));
    // sum (A[i]-m)^2을 전개한 결과를 부분 합으로 표현
    int ret = sqsum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}

int cache[101][11];
int quantize(int from, int parts) {
    // 기저 사례: 모든 숫자를 다 양자화했을 때
    if(from == n) return 0;
    // 기저 사례: 숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰 값을 반환
    if(parts == 0) return INF;
    int& ret = cache[from][parts];
    if(ret != -1) return ret;
    ret = INF;
    // 조각의 길이를 변화시켜 가며 최소치를 찾는다.
    for(int partSize = 1; from + partSize <= n; ++partSize) {
        ret = std::min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
    } 
    return ret;
}

int main(void) {
    int T;
    std::cin >> T;
    while(T--) {
        memset(cache, -1, sizeof(cache));
        int S;
        std::cin >> n >> S;
        for(int i=0; i<n; i++) {
            std::cin >> A[i];
        }
        precalc();
        std::cout << quantize(0, S) << "\n";
    }
}