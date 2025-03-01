# [실버 4] 박 터뜨리기 - 19939
[문제 링크](https://www.acmicpc.net/problem/19939)

### 분류
수학, 그리디

### 문제 리뷰
<p>그리디 문제이지만 등차 수열의 합 공식을 적용하면 몇 개의 if문으로 간단히 해결 가능한 문제이다.</p>
<p>각 상자에는 최소 한 개 이상의 공이 들어가야 하므로 상자안의 공 개수는 최소 1~k개의 공이 등차 수열로 이루어져야 할 것이다.</p>
<p>이 때의 공의 전체 개수는 N X (N + 1) / 2 공식으로 한 번에 구할 수 있고 위 전체 개수 보다 N의 값이 작다면 나누어 담을 수 없는 경우가 된다.</p>
<p>N의 값이 최소 등차수열의 합보다 크다고 하다면 나머지 공들을 처리해야 한다. 이때 공의 개수가 상자의 개수의 배수만큼 남게 되면 각 상자별로 똑같은 양의 공이 추가되게 된다.</p>
<p>이는 최대, 최소의 공의 차이도 같게 된다는 뜻으로 결국 최대, 최소의 값은 K-1로 같게 된다.</p>
<p>그러나 남은 공의 개수가 K의 배수가 아닐 경우 공의 개수가 곂치지 않게 하기 위해서는 반드시 남은 공을 뒤 상자 부터 추가해야 한다.</p>
<p>그렇게 되면 최대의 상자가 최소보다 반드시 1개 더 많은 추가 공을 얻게 된다.</p>
<p>고로 이 떄의 최대 최소의 차이는 K개가 되고 총 3개의 if문으로 풀이할 수 있다.</p>