// 문제: 와일드 카드 (문제 ID: WILDCARD, 난이도: 중)
#include<bits/stdc++.h>
/*
*(와일드 카드) 처리 방법
- ? 같은 경우 항상 문자 하나와 대응되기 때문에 풀이가 쉽지만,
  * 같은 경우 다음 문자가 몇 개가 나올지 모르는 상황이기에 해결이 필요하다.
    아이디어로 패턴 *이 나타낼 때까지 대응 여부를 확인하고 *이 나타나면 
    해당 부분 부터의 패턴과 문자열 부터를 입력으로 가지는 부분 문제로 나눈다.
*/

// 와일드 카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
// bool match(const std::string& w, const std::string& s) {
//     // w[pos]와 s[post]를 맞춰나간다.
//     int pos = 0;
//     while(pos < s.size() && pos < w.size() &&
//             (w[pos] == '?' || w[pos] == s[pos]))
//         ++pos; 
//     // 2. 패턴 끝에 도달해서 끝난 경우 : 문자열도 같이 끝나야 대응
//     if(pos == w.size()) return pos == s.size();
//     // 4. *를 만나서 끝난 경우 : 재귀 호출 시작
//     if(w[pos] == '*') {
//         for(int skip = 0; pos+skip <= s.size(); ++skip) {
//             if(match(w.substr(pos+1), s.substr(pos+skip)))
//                 return true;
//         }
//     }
//     // 이외 모든 경우는 실패 처리
//     return false;
// }

/*
종료하는 경우의 수
1. s[pos]와 w[pos]가 대응되지 않는다 : 실패 처리
2. w 끝에 도달함 : 패턴에 *이 하나도 없는 경우, 패턴과 문자열의 길이가 일치할 때만 성공 처리
3. s 끝에 도달함 : 패턴은 아직 남아있지만 문자열은 끝난 상태, 남은 패턴이 모두 *이 아닌 이상 실패 처리 (*이어도 차피 4로 넘어감감)
4. w[pos]가 * : 와일드 카드 처리를 위한 재귀적 아이디어를 여기에 적용한다. 
    이때 w의 pos + 1 이후를 패턴으로 하고 s의 pos + skip 이후를 문자열로 하여 재귀 중 단 하나라도 답이 있으면 참으로 한다.
*/

/*
중복되는 부분 문제 
- 이 코드 또한 패턴: ******a, 원문: aaaaaaaaaaaab 같은 경우만 보아도 절대로 정답이 될 수 없는 경우를 위해 많은 경우의 수를 검사하게 된다.
    고로 메모제이션을 이용하여 패턴의 위치까지와 원문의 위치까지의 가능 대응 여부를 담는 배열을 생성하여 계산된 값을 저장한다.
*/

int cache[101][101];
std::string W, S;
int matchMemoized(int w, int s) {
    // 메모제이션
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    // while(s < S.size() && w < W.size() &&
    //     (W[w] == '?' || W[w] == S[s])){
    //     ++s;
    //     ++w;
    // }
    if(w < W.size( ) && w < W.size() && 
        (W[w] == '?' || W[w] == S[s])) 
        return ret = matchMemoized(w+1, s+1);
    //  2. 패턴 끝에 도달해서 끝난 경우 : 문자열도 같이 끝나야 대응
    if(w == W.size()) return ret = (s == S.size());
    // 4. *를 만나서 끝난 경우 : 재귀 호출 시작
    // if(W[w] == '*') {
    //     for(int skip = 0; s+skip <= S.size(); ++skip) {
    //         if(matchMemoized(w+1, s+skip)) 
    //             return ret = 1;
    //     }
    // }
    if(W[w] == '*') {
        return ret = matchMemoized(w+1, s) || 
            (s < S.size() && matchMemoized(w, s+1));
    }
    return ret = 0;
}

int C, N;
int main(void) {
    std::cin >> C;
    while(C--) {
        std::vector<std::string> answer;
        W = "";
        S = "";
        std::cin >> W;
        std::cin >> N;

        while(N--) {
            memset(cache, -1, sizeof(cache));
            std::cin >> S;
            if(matchMemoized(0, 0)) answer.push_back(S);
        }
        
        std::sort(answer.begin(), answer.end());
        for(std::string s : answer) std::cout << s << "\n";
    }
}