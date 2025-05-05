#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 사용 

    for(int a : ability) {
        pq.push(a); // 능력치 추가
    }

    // number번 만큼 교육 진행
    while(number--) {
        // 가장 낮은 2명의 능력치 가져오기
        int a = pq.top(); pq.pop(); 
        int b = pq.top(); pq.pop();

        // 두 사람의 합으로 능력치 업데이트
        int sum = a + b;
        pq.push(sum); 
        pq.push(sum); 
    }

    // 최종 능력치 총합
    int total = 0;
    while(!pq.empty()) {
        total += pq.top(); // 능력치 합산
        pq.pop();
    }
    return answer;
}