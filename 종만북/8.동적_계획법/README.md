# 8장 동적 계획법
## 8.1 도입
<p>동적 계획법은 쉽게 생각해 분할 정복처럼 문제를 더 작은 문제들로 나눈 다음 나누어진 답을 통해 원래 문제의 답을 계산해 나간다.</p>
<p>이때 분할 정복과 다른 점은 부분문제의 값을 계산할 때 두 번 이상 계산되는 문제(overlapping subporblem)를 없애기 위해 한 번 계산된 결과를 재활용하여 속도의 향상을 꾀한다.</p>

### 8.1.1 메모제이션을 적용할 수 있는 경우
<p>프로그래밍에서의 함수는 수학에서
의 함수와 달리 입력 값에 따라 나오는 출력 값이 달라질 수 있다.</p>
<pre>
<code>
```cpp
int counter = 0;
int count() {
    return counter++;
}
```
</code>
</pre>
<p>위 함수는 입력을 받지 않아도 호출 될 때 마다 매번 다른 결과를 반환한다. 물론 bino(), bino2() 함수와 같이 입력이 같으면 출력도 항상 같은 함수도 작성할 수 있다.</p>
<p>이처럼 함수의 반환 값이 그 입력 값만으로 결정되는지의 여부를 참조적 투명성(referential transparency)라고 부르고 위 특성을 지는 함수를 참조적 투명 함수(referential transparent function)이라고 부른다.</p>
<p>당연히도 메모제이션은 참조적 투명 함수의 경우에만 적용할 수 있다.</p>

#### 용어 정리
+ 중복되는 부분 문제(overlapping subporblem) : 두 번 이상 계산되는 부분 문제
+ 조합 폭발 (combinatorial explosion) : 분할의 깊이가 깊어질 술록 연산 수가 지수적으로 증가되는 현상

+ 참조적 투명성(referential transparency) : 함수의 반환 값이 그 입력 값만으로 결정되는지의 여부
+ 참조적 투명 함수(referential transparent function) : 참조적 투명성을 만족하는 함수