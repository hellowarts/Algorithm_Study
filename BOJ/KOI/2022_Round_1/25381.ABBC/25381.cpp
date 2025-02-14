#include<bits/stdc++.h>

int main(void) {

    std::string S;
    std::queue<int> q1, q2;
    std::cin >> S;
    
    int result = 0;
    for(int i=0; i<S.size(); i++) {
        if(S[i] == 'B') q1.push(i);
        else if(!q1.empty() && S[i] == 'C') {
            result++;
            S[q1.front()] = 'X';
            q1.pop();
        }
    }
    for(int i=0; i<S.size(); i++) {
        if(S[i] == 'A') q2.push(i);
        else if(!q2.empty() && S[i] == 'B') {
            result++;
            q2.pop();
        }
    }
    std::cout << result;

    return 0;
}