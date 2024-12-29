# 8장 동적 계획법
## 8.1 도입
<p>동적 계획법은 쉽게 생각해 분할 정복처럼 문제를 더 작은 문제들로 나눈 다음 나누어진 답을 통해 원래 문제의 답을 계산해 나간다.</p>
<p>이때 분할 정복과 다른 점은 부분문제의 값을 계산할 때 중복되는 문제(overlapping subporblem)를 없애기 위해 한 번 계산된 결과를 재활용하여 속도의 향상을 꾀한다.</p>

### 8.1.1 메모이제이션을 적용할 수 있는 경우
<p>프로그래밍에서의 함수는 수학에서
의 함수와 달리 입력 값에 따라 나오는 출력 값이 달라질 수 있다.</p>

```cpp
int counter = 0;
int count() {
    return counter++;
}
```
<p>위 함수는 입력을 받지 않아도 호출 될 때 마다 매번 다른 결과를 반환한다. 물론 bino(), bino2() 함수와 같이 입력이 같으면 출력도 항상 같은 함수도 작성할 수 있다.</p>
<p>이처럼 함수의 반환 값이 그 입력 값만으로 결정되는지의 여부를 참조적 투명성(referential transparency)라고 부르고 위 특성을 지는 함수를 참조적 투명 함수(referential transparent function)이라고 부른다.</p>
<p>당연히도 메모이제이션은 참조적 투명 함수의 경우에만 적용할 수 있다.</p>

### 8.1.2 메모이제이션 구현 패턴
<p>메모이제이션을 이용하여 문제를 풀 때 한 가지 패턴을 정해두고 구현하면 작성하기도, 버그를 찾기도 쉬워진다.</p>
<p>아래 코드를 참조하면 어떻게 참조적 투명 함수를 메모이제이션 함수로 바꿔 구현하는지 쉽게 확인할 수 있다.</p>

``` cpp
// 1. 전부 -1로 초기화 한다.
int cache[2500][2500];
void cache_init(){
    memset(cache, -1, sizeof(cache));
}
int someObscureFunction(int a, int b) {
    // 2. 항상 기저 사례를 먼저 처리한다.
    if(...) return ...;
    // 3. cache[a][b]에 대한 참조형 ret을 생성하여 불필요한 코드 작성을 줄인다.
    int& ret = cache[a][b];
    if(ret != -1) return ret;
    // 4. 여기에서 답을 계산
    ...
    return ret;
}
```

1. 함수의 반환 값이 항상 0 이상인 점을 이용하여 cache[][]를 -1로 초기화 하여 -1의 유무로 계산된 반환 값인 지를 구분한다.
2. 기저 사례를 먼저 처리하여 접근 범위를 벗어나는 오류를 막는다.
3. ret 이라는 참조형을 이용하여 cache가 다차원 배열일 때 인덱스 순서를 바꿔쓰는 실수를 사전에 차단한다.
4. ret의 값이 -1이 아닐 때만 값을 계산한다.
5. C/C++에서 다차원 배열을 초기화 할 때 for문을 이용하는 것 보다 memset을 활용하는 것이 더욱 빠르기 때문에 이를 이용한다.

### 8.1.3 메모이제이션의 시간 복잡도 분석
<p>메모이제이션을 사용하는 알고리즘의 시간 복잡도는 다음과 같이 간단하게 계산할 수 있다.</p>

+ (존재하는 부분 문제의 수) X (한 부분 문제를 풀 때 필요한 반복문의 수행 횟수)

<p>예시로 이항 계수를 계산하는 bino2() 함수의 경우 r의 최대치는 n이므로 존재하는 부분 문제의 수는 최대 O($$n^2$$)이다.</p>
<p>각 부분 문제를 계산할 때 걸리는 시간은 반복문이 없으므로 O(1)이고 즉 위 식에 따라 전체 시간 복잡도는 O($$n^2$$) X O(1) = O($$n^2$$)이 된다.</p>
<p>물론 위 식은 수행 시간의 상한을 간단히 계산할 수 있는 방법일 뿐, 항상 정확하지는 않다.</p>

### 8.1.4 동적 계획법 레시피
1. 주어진 문제를 완전 탐색을 이용해 해결
2. 중복된 부분 문제를 한 번만 계산하도록 메모이제이션을 적용

## 8.2 전통적 최적화 문제들
<p>동적 계획법의 가장 일반적인 사용처는 최적화 문제의 해결이다.</p>
<p>특히 최적화 문제에 특정 성질이 성립할 경우에는 단순히 메모이제이션을 적용하기 보다 좀 더 효율적으로 동적 계획법을 구현할 수 있다.</p>


## 용어 정리
+ 중복되는 부분 문제(overlapping subporblem) : 두 번 이상 계산되는 부분 문제
+ 조합 폭발 (combinatorial explosion) : 분할의 깊이가 깊어질수록 연산 수가 지수적으로 증가되는 현상
+ 참조적 투명성(referential transparency) : 함수의 반환 값이 그 입력 값만으로 결정되는지의 여부
+ 참조적 투명 함수(referential transparent function) : 참조적 투명성을 만족하는 함수