#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int priority;
    int request_time;
    int run_time;
    int idx; // 호출 순서를 저장해 동점자 우선순위 유지

    Node(int p, int rqt, int rt, int i) : priority(p), request_time(rqt), run_time(rt), idx(i) {}
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
       if (a.priority != b.priority) return a.priority > b.priority; // 우선순위 비교 (낮은게 높음)
       return a.idx > b.idx; // 호출 순서 비교 (먼저 호출된게 높음)
    }
};

vector<long long> solution(vector<vector<int>> program) {
    int n = program.size();
    // 요청 시간 기준으로 정렬
    sort(program.begin(), program.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    // 대기시간 결과 저장 (0번 : 종료시각, 1~10번: 점수별 대기 합)
    vector<long long> answer(11, 0);
    int idx = 0;
    long long current_time = 0; // 현재 시간

    priority_queue<Node, vector<Node>, Compare> pq;

    while(idx < n || !pq.empty()) {
        // 요청된 프로그램을 큐에 추가
        while (idx < n && program[idx][1] <= current_time) {
            pq.push(Node(program[idx][0], program[idx][1], program[idx][2], idx));
            idx++;
        }

        if (pq.empty()) {
            // 대기 중인 프로그램이 없으면 다음 요청 시간으로 이동
            current_time = program[idx][1];
            continue;
        }

        // 우선순위가 가장 높은 프로그램을 실행
        Node current = pq.top();
        pq.pop();

        // 대기시간 계산 : 실행 시작 시각 - 요청 시각
        long long wait_time = current_time - current.request_time;
        answer[current.priority] += wait_time;

        // 프로그램 실행 후 종료 시각 업데이트
        current_time += current.run_time;
    }

    answer[0] = current_time; // 종료 시각 저장
    return answer;
}