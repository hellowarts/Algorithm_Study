# 8장 동적 계획법
## 8.1 도입
<p>동적 계획법은 분할 정복처럼 문제를 더 작은 문제들로 나눈 다음 나누어진 답을 통해 원래 문제의 답을 계산해 나간다.</p>
<p>이때 분할 정복과 다른 점은 부분문제의 값을 계산할 때 중복되는 문제(overlapping subporblem)를 없애기 위해 한 번 계산된 결과를 재활용하여 속도의 향상을 꾀한다.</p>
<p>이때 한 번 계산된 값을 저장하는 기법을 메모이제이션(memoization) 기법이라고 한다.</p>

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

### 8.2.1 최적 부분 구조
<p>최적 부분 구조(optimal substructure)란 각 부분 문제의 최적해만 있다는 전체 문제의 최적해를 쉽게 얻어낼 수 있는 구조를 뜻한다.</p>
<p>즉 이전 문제에서의 선택과 상관 없이 현재의 부분 문제를 최적으로만 풀기만 한다면 전체 문제의 최적해도 알 수 있게 된다.</p>
<p>그렇기에 <a href="https://github.com/hellowarts/Algorithm_Study/blob/main/APSS/8_Dynamic_Programing/Example_problem/TRIANGLEPATH.cpp">예제: 삼각형 위의 최대 경로</a> 에서도 부분 문제를 결정할 때 필요하지 않은 sum 정보를 삭제함으로써 문제를 풀이할 수 있었다.</p>
<br>
<p>최적 부분 구조를 가지는 문제 예시로 만약 서울에서 부산까지 가는 최단 경로를 구하고자하고 이 최단 경로가 대전을 경유한다고 가정하자.</p>
<p>그렇다면 이 문제는 아래와 같이 나뉘어 질 것이다.</p>

+ (서울, 대전) + (대전, 부산)

<p>우리는 직관적으로 두 구간의 최단 경로를 찾아서 둘을 이으면 항상 서울에서 부산으로 가는 최단 경로를 얻을 수 있음을 알 수 있다.</p>
<p>안되는 경우도 알아보자 만약 위 예시에서 고속도로 통행료의 합이 3만원을 초과하지 않는 최단 경로를 구한다고 하자 경로는 아래와 같다.</p>

+ 경로 A: 통행 시간 2시간, 통행료 1만원
+ 경로 B: 통행 시간 1시간, 통행료 2만원

<p>위 같은 경우 전 경로가 아무리 최단 경로여도 통행료 떄문에 문제의 정답이 되지 않거나 경로 A와 같은 오히려 시간이 오래 걸리는 경로를 최적해로 결정할 수 있어진다.</p>
<p>따라서 위와 같이 작은 문제의 최적해만으로 전체 문제의 최적해를 구할 수 없는 경우도 존재 한다.</p>

### 8.2.2 최적화 문제 동적 계획법 레시피
1. 모든 답에 대해 최적해의 점수를 반환하는 완전 탐색 알고리즘 설계
2. 앞으로 남은 선택들에 해당하는 점수만을 반환하도록 부분 문제의 정의 바꾼다.
3. 재귀 호출의 입력에 꼭 필요한 입력만 남긴다. 이전 선택에 관련된 정보를 꼭 필요하지 않는다면 없앤다.
4. 입력이 배열이거나 문자열이면 적절한 변환을 통해 메모이제이션이 가능하도록 바꾼다.
5. 메모이제이션을 적용한다.

위 과정을 <a href="https://github.com/hellowarts/Algorithm_Study/blob/main/APSS/8_Dynamic_Programing/Example_problem/TRIANGLEPATH.cpp">예제: 삼각형 위의 최대 경로</a> 에 적용하면 다음과 같다.

1. 모든 경로를 만들어 보고 전체 합 중 최대치를 반환하는 path1() 제작
2. path1()이 전체 경로의 최대 합을 반환하는 것이 아닌 (y, x) 이후로 만난 숫자들의 최대 합만을 바꾸도록 재정의
3. 재정의 후 이전에 한 선택에 필요한 정보인 sum 정보는 제거
4. 해당 없음
5. 메모이제이션 적용하여 path2() 제작

## 8.3 경우의 수와 확률
<p>DP는 최적화 문제를 풀기 위해 고안되었지만 경우의 수를 세거나 확률을 계산하는 문제에도 흔히 사용된다.</p>
<p>경우의를 계산하는 문제는 많은 경우 재귀식을 이용하기 때문 (예시: <a href="https://github.com/hellowarts/Algorithm_Study/blob/main/APSS/8_Dynamic_Programing/binomial_coefficient.cpp">이항 계수 계산</a>)</p>

### 8.3.1 경우의 수 계산하기 레시피
1. 모든 답을 세는 완전 탐색 알고리즘 설계 각 재귀 호출이 각 단계에서 고르는 선택지는 다음 속성이 포함되어야 함
+ 모든 경우는 이 선택지들에 포함됨
+ 어떤 경우도 두 개 이상의 선택지에 포함되지 않음 (서로 곂치지 않음)
2. 이전에 대한 결정 요소는 남기지 않음으로 데이터를 줄임
3. 메모이제이션을 적용

## 용어 정리
+ 중복되는 부분 문제(overlapping subporblem) : 두 번 이상 계산되는 부분 문제
+ 조합 폭발 (combinatorial explosion) : 분할의 깊이가 깊어질수록 연산 수가 지수적으로 증가되는 현상
+ 참조적 투명성(referential transparency) : 함수의 반환 값이 그 입력 값만으로 결정되는지의 여부
+ 참조적 투명 함수(referential transparent function) : 참조적 투명성을 만족하는 함수
+ 최적 부분 구조(optimal substructure) : 각 부분 문제의 최적해만 있다는 전체 문제의 최적해를 쉽게 얻어낼 수 있는 구조