#include<bits/stdc++.h>

static int k;
int S = 0;

static int p[14];
std::vector<bool> visited;

void DFS(int depth, int num) {
    if(depth == k) {
       if(0 < num && num <= S) 
            visited[num] = true;
        return;
    }

    int numL = num + p[depth];
    int numR = num - p[depth];

    DFS(depth+1, numL);
    DFS(depth+1, numR);
    DFS(depth+1, num);
}

int main(void) {
    std::cin >> k;
    for(int i=0; i<k; i++) {
        std::cin >> p[i];
        S += p[i];
    }
    visited.resize(S+1, false);

    DFS(0, 0);

    int answer = 0;
    for(int i=1; i<=S; i++) {
        if(!visited[i]) answer++;
    }
    std::cout << answer;

    return 0;
}