# [골드 3] ABBC - 25381
[문제 링크](https://www.acmicpc.net/problem/25381)

## 문제 분류
순서 정하기 

### 알고리즘
그리디

### 문제 리뷰
<p>문제를 읽으면 C를 먼저 지워야 최대의 경우가 나옴을 알 수 있다.</p>
<p>이때 문자열에서 B를 지우는 것이 어렵기 때문에 B를 지울 수 있다면 해당 위치에 B 대신 다른 문자 ('X')를 넣음으로써 삭제를 대신하였다.</p> 
<p>앞에 여러 B문자가 나왔다면 뒤의 C도 여러개 삭제할 수 있으므로 B가 나올 때 마다 그 위치를 큐에 저장했다.</p>
<p>예를 들어 BBCC 같은 경우 1번 B와 3번 C, 2번 B와 4번 C로 묶어서 삭제할 수 있다.</p>
<p>큐에 B가 저장 되어 있고 현재 문자가 C인 경우에 해당 B 위치 문자를 X로 바꾸고 결과값을 1 더해 주었다.</p>
<p>B와 C에 대해서 삭제를 진행 한 후 이와 비슷하게 A와 B에 대해서 삭제를 진행하면 된다.</p>
<p>이때도 A를 큐에 담은 후 큐에 A가 존재하고 현재 문자가 B인 경우에 결과값을 1 더해준다.</p>

### 정리
+ 배열의 데이터를 직접 삭제하는데 너무 신경쓰지 않아도 된다. 다른 문자로 대체해도 괜찮은지를 살펴보자