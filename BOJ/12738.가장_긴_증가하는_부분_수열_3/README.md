# [Gold 2] 가장 긴 증가하는 부분 수열 3 - 12738
[문제 링크](https://www.acmicpc.net/problem/12738)

### 분류
DP, LIS

### 문제 리뷰
<p>LIS 문제로 <a href="C:\Users\Void\TH_Lab\AL_Study\APSS\8_Dynamic_Programing\Example_problem\LIS.cpp">알고리즘 문제 해결 전략 LIS 문제</a>를 해결한 후 풀었기에 쉽게 풀 수 있었다.</p>
<p>참고로 '가장 긴 증가하는 부분 수열 2' 문제도 비슷하게 이진 탐색을 응용하는 문제인 것 같은데 해당 문제를 3번 문제와 같은 알고리즘으로 풀어버려 3번만 리뷰를 한다.</p>
<p>아이디어는 배열 C를 이용하여 LIS를 저장해 나가되 왼쪽의 수의 크기가 작을 수록 LIS의 길이를 늘리기 쉽다는 성질을 이용하여 만약 같은 길이의 LIS여도 왼쪽 위치의 값이 더욱 작은 배열이 존재 하면 해당 배열로 교체하여 LIS를 늘리는 식으로 문제를 해결한다.</p>
<p>예를 들어 {5,6,7,1,2} 라는 수열이 존재 할때 이 수열의 길이가 2인 LIS는 {5,6}, {6,7}, {1,2} 가 존재할 것이다. 그런데 만약 전체 수열이 뒤에 {3, 4}라는 수열을 더욱 가지고 있었다면 LIS를 늘리기 위해 {5,6}, {6,7}, {1,2} 중 {1,2}를 가지고 있는 것이 더욱 유리하게 된다.</p>
<p>따라서 이진 탐색을 통해 전체 순열의 값들을 현재 C 배열의 값들과 이진 탐색으로 비교하다가 전체 C 배열보다 값이 높다면 C 배열에 추가, 작다면 C배열의 해당 위치의 값과 교환하여 더 유리한 값으로 교환한다.</p>

### 정리

```cpp
int LIS() {
    std::vector<int> C; // 증가 부분 수열의 마지막 값을 관리하는 배열
    for(int num : A) {
        auto pos = std::lower_bound(C.begin(), C.end(), num);
        if(pos == C.end()) C.push_back(num);
        else *pos = num;
    }
    return C.size();
}
```