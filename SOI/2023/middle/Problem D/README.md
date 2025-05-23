# 문제 4: SJ24 편의점 배치2
시간 제한: 1초
메모리 제한: 256MB

## 문제의 배경
세종마을은 일직선으로 구성된 도로를 중심으로 발전한 마을이다. 이 마을에는 주민센터를 포함한 N개의 거주지가 구성된다. 주민센터의 좌표는 0이고 각 거주지의 좌표는 주민센터와의 거리로 표현된다.

아래는 예시로 5개의 거주지 좌표를 나타낸다:

주민센터	거주지 1	거주지 2	거주지 3	거주지 4
0	-2	-2	4	-18

이 세종마을에 정확히 2개의 SJ24 편의점을 설치하고자 한다. 편의점은 마을 어디에나 설치할 수 있으며, 같은 좌표에도 설치 가능하다.

각 주민은 가장 가까운 편의점까지의 거리를 계산하여 해당 편의점에서 물건을 구매한다. 같은 거리의 편의점이 2개 있다면, 아무 곳에서나 구매할 수 있다.

편의점의 설치 위치에 따라 주민들의 총 이동 거리(즉, 편의점까지의 거리 합계)를 최소화하려고 한다.
2개의 편의점을 적절히 배치해 모든 주민들의 이동 거리의 합을 최소로 만드는 프로그램을 작성하자.

## 입력 설명
첫 번째 줄: 거주지의 수 N이 주어진다.

두 번째 줄: 주민센터를 포함한 N개의 거주지의 좌표가 공백으로 주어진다.

## 입력값의 범위
공통 조건

3 ≤ N ≤ 200,000

각 좌표의 절댓값 ≤ 10¹²

부분 문제 조건

- 1: N ≤ 32 (16점)
- 2: N ≤ 10,000 (25점)
- 3: 추가 제한 없음 (59점)

## 출력 설명
2개의 편의점을 적절히 설치해 주민들의 거리 총합의 최소값을 출력한다.

## 입력 예시 1
<pre> 
5 
0 -2 -2 4 -18
</pre>

## 출력 예시 1
<pre>8</pre>

## 입력 예시 설명
편의점을 위치 0과 위치 -18에 설치할 수 있다.

이때 거리 총합은 다음과 같다:

0(주민센터) + 2(주민1) + 2(주민2) + 4(주민3) + 0(주민4) = 8

따라서 최소 거리는 8이다.