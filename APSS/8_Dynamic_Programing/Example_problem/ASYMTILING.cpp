// 문제: 비대칭 타일링 (문제 ID: ASYMTILING, 난이도: 하)
#include<bits/stdc++.h>
/*
문제풀이 전략 
-  우리는 앞서 TILE2 문제에서 2 X n 크기의 사각형을 채우는 방법의 수를 구하는 문제를 풀었다.
- 이 문제는 비대칭 타일링을 구하는 문제로 달리 말하면 전체 타일링의 경우의 수에서 대칭 타일링의 경우의 수를 빼주면 된다.
- 대칭 타일링의 경우의 수의 첫 번째 단계는 n이 짝수인 경우와 홀수인 경우로 나눠 보는 것이다.
- n이 홀수인 경우, 타일링 방법이 대칭이기 위해서는 항상 세로줄 세로 타일이 하나 있어야 한다.
- n이 짝수인 경우는 세로줄 둘을 가로 타일로 덮는 경우와 그냥 절반으로 나뉜 경우 2가지가 존재한다.
- 이때 홀수로 나누건 짝수로 나누건 나누어진 오른쪽, 왼쪽 파일은 모두 대칭이어야 함을 알 수 있다.
- 그렇기에 각 경우에서의 tiling 개수를 전체 tiling개수에서 적절히 빼 주면 된다.
*/

const int MOD = 1000000007;
int cache[101];
// 2 X n 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.
int tiling(int width) {
    // 기저 사례: 너비가 1이하하면 바로 끝난다.
    if(width <= 1) return 1;
    // 메모이제이션
    int& ret = cache[width];
    if(ret != -1) return ret;
    return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

// 2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다.
int asymmetric(int width) {
  // 홀수인 경우 전체 타일링에서 절반의 타일링을 빼준다.
  if(width % 2 == 1) 
    return (tiling(width) - tiling(width/2) + MOD) % MOD;
  // 짝수인 경우 전체 타일링에서 절반의 타일링과, 절반의 타일링에서 가운데에 가로 2줄이 있는 경우를 빼 준다.
  int ret = tiling(width);
  ret = (ret - tiling(width/2) + MOD) % MOD;
  ret = (ret - tiling(width/2 - 1) + MOD) % MOD;
  return ret;
}

int main(void) {
  int C;
  std::cin >> C;
  while(C--) {
      memset(cache, -1, sizeof(cache));
      int n;
      std::cin >> n;
      std::cout << asymmetric(n) << "\n";
  }
}