# [골드 4] 다이어트 - 19942
[문제 링크](https://www.acmicpc.net/problem/19942)

### 분류
비스마스킹, 브루트포스

### 문제 리뷰
<p>브루트포스로 풀이하면 될 것 같지만 선택할 수 있는 경우가 n개로 정해져 있지 않기 때문에 n개의 음식에 대해 공집합을 제외한 모든 부분 집합에 대해 경우의 수를 모두 따져 보아야 한다.</p>
<p>이런 경우에 사용할 수 있는게 바로 비트마스킹으로 위 문제에서는 크게 3가지 코드에 주목할만 하다.</p>

1. 1 << N
2. for(int i=0; i < (1 << N); i++)
3. if(i & (1 << j)) 

<p>우선 1번의 경우에는 1이라는 값을 비트로 변환 한 후 N만큼 비트를 왼쪽으로(<-방향으로) 이동시키라는 뜻이다.</p>
<p>만약 1 << 3 이라는 연산이 있다면 이진수 0001이 1000으로 비트가 옮겨지며 $$2^3$$값이 되는걸 확인할 수 있다.</p>
<p>고로 1 << N의 뜻은 $$2^N$$이라는 뜻이 되고 이를 이해하면 다음 2번 코드를 이해핼 수 있게된다.</p>
<p>2번 같은 경우 반복문으로 0 ~ $$2^N$$ - 1까지의 값을 i에 넣으며 반복함을 알 수 있다.</p>
<p>만약 i의 값을 이진수로 표현하고 N의 값을 3이라고 두어보자 그럼 다음과 같은 i 값들이 들어가며 반복될 것이다.</p>

+ i = 000 : 0
+ i = 001 : 1
+ i = 010 : 2
+ i = 011 : 3
+ i = 100 : 4
+ i = 101 : 5
+ i = 110 : 6
+ i = 111 : 7

<p>위와 같이 N의 값이 3이라면 3비트의 표현으로 만들 수 있는 숫자들이 i의 범위가 됨을 알 수 있다.</p>
<p>이때 각각의 비트 자리들을 음식의 종류로써 생각을 해보자</p>
<p>예를 들어 101 같은 경우 $$2^2$$ 자리 비트와 $$2^0$$ 자리 비트에 1이 들어 있으므로 이를 음식 2와 음식 0을 선택한 경우로 생각하는 것이다.</p>
<p>그러면 자연스럽게 우리는 위 for문을 통해 음식 {0, 1, 2}번에 대해 고를 수 있는 모든 경우 즉 모든 부분집합의 표현을 위 비트연산으로 표현할 수 있음을 알 수 있게 될 것이다.</p>
<p>마지막으로 3번 코드를 확인해 보면 비트 i 값과 비트 (1 << j) 값을 &연산 함을 알 수 있고 그 값을 if문의 조건으로 두고 있다.</p>
<p>즉 모든 i의 비트 중에서 j비트가 포함되어 있다면 i에 저장되어 있는 음식의 경우의 수에 해당한다는 뜻이 된다.</p>
<p>이를 통해 i경우 별로 해당하는 음식을 정확하게 구분할 수 있고 위 비트 정보를 저장함으로써 마지막에 선택한 음식 번호를 출력할 때도 역시 사용할 수 있게 된다.</p>

### 정리 
+ 모든 부분집합에 대한 문제는 비트마스킹으로 해결
1. 1 << N
2. for(int i=0; i < (1 << N); i++)
3. if(i & (1 << j)) 