#include <string>
#include <vector>

using namespace std;

int answer = 0;
int Student_Size = 0;
int Sport_Size = 0;

void dfs(vector<vector<int>>& ability, vector<bool>& visited, int idx, int cnt) {
    if(idx == Sport_Size) {
        answer = max(answer, cnt);
        return;
    }

    for(int i=0; i < Student_Size; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(ability, visited, idx + 1, cnt + ability[i][idx]);
        visited[i] = false;
    }
}

int solution(vector<vector<int>> ability) {
    Student_Size = ability.size();
    Sport_Size = ability[0].size();
    vector<bool> visited(Student_Size, false);
    dfs(ability, visited, 0, 0);

    return answer;
}