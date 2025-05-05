#include <string>
#include <vector>

using namespace std;

string getGene(int generation, long long idx) {
    if(generation == 1) return "Rr"; // 초기 잡종
    
    // 부모의 인덱스 계산 (1~4 -> 1, 5~8 -> 2, ...)
    long long parentIdx = (idx + 3) / 4; // 1-based index

    string parent = getGene(generation - 1, parentIdx);
    int pos = (idx - 1) % 4; // 0-based index, 자식의 위치

    if (parent == "RR") return "RR";
    if (parent == "rr") return "rr";

    // 부모가 Rr인 경우 자식의 위치에 따라 결정
    if(pos == 0) return "RR"; 
    if(pos == 3) return "rr";
    return "Rr"; // pos 1, 2인 경우
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for(const auto& query : queries) {
        int n = query[0];
        long long p = query[1];
        answer.push_back(getGene(n, p));
    }
    return answer;
}