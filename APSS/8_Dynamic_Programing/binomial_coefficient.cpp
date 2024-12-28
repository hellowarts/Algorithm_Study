#include<bits/stdc++.h>
// 재귀 호출을 이용한 이항 계수의 계산
int bino(int n, int r){
    // 기저 사례: n=r(모든 원소를 다 고르는 경우) 혹은 r=0(고를 원소가 없는 경우)
    if(r == 0 || n == r) return 1;
    return bino(n-1, r-1) + bino(n-1, r);
}
// 캐시는 미리 -1로 초기화
int cache[30][30];
void init_cache() {
    memset(cache, -1, sizeof(cache));
}
int bino2(int n, int r) {
    // 기저 사례
    if(r == 0 || n == r) return 1;
    // 한 번 계산했던 값이면 곧장 반환
    if(cache[n][r] != -1) return cache[n][r];
    // 직접 계산한 뒤 배열에 저장
    return cache[n][r] = bino(n-1, r-1) + bino(n-1, r);
}