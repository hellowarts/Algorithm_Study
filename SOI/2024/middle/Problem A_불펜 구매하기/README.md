# 문제 A: 불펜 구매하기

## 문제 설명

이번 봄 운동회를 앞둔 세종이는 신나는 마음에 불펜을 사러 문구점에 들어갔다.  
문구점에서는 불펜 1개를 a원에 판매하고 있으며, 현재 세트를 구매하면 b개를 주는 a+b 이벤트가 진행 중이다.  

세종이는 최소 w개의 불펜을 구매하려고 한다. 세종이가 원하는 만큼 불펜을 구매하기 위해  
필요한 금액은 얼마인지 구하는 프로그램을 작성하시오.

---

## 입력 설명

- 첫 번째 줄: 불펜의 금액 a, 세종이가 원하는 불펜의 개수 w (공백으로 구분)  
- 두 번째 줄: 문구점의 이벤트 정보 (a + b 형태의 b값, 공백으로 구분)  

제한 사항:
- 1 ≤ w ≤ 10,000,000,000
- 1 ≤ a ≤ 100,000
- 0 ≤ b ≤ 100,000

---

## 출력 설명

- 세종이가 필요한 금액의 **최소값**을 출력한다.

---

## 부분 문제

- Subtask 1 (35점): 1 ≤ k, w, a ≤ 100,000, b = 1
- Subtask 2 (65점): 추가 제한 조건 없음

---

## 입력 예시 1
<pre>
10 6
2 1
</pre>

## 출력 예시 1
<pre>40</pre>