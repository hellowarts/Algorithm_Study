#include <string>
#include <vector>

using namespace std;

vector<int> alphabet(26, 0);

string solution(string input_string) {
    string answer = "";

    char prev_char = '\0';
    for(char c : input_string) {
        if(c == prev_char) continue;
        alphabet[c - 'a']++;
        prev_char = c;
    }
    for(int i = 0; i < 26; i++) {
        if(alphabet[i] > 1) {
            answer += (char)(i + 'a');
        }
    }

    return answer;
}