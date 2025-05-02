#include<bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;

    const std::string key = "1011";

    // 반복적으로 "1011"을 찾아서 "1"로 치환
    while (true) {
        std::size_t pos = s.find(key); // size_t는 unsigned int와 같음, 주로 배열의 크기나 인덱스를 나타낼 때 사용
        // string::npos == -1로 find() 함수가 찾지 못했을 때 반환하는 값
        if (pos == std::string::npos) break;
        
        // "1011"을 "1"로 치환
        // substr() 함수는 문자열의 일부를 추출하는 함수
        // s.substr(0, pos) : s의 처음부터 pos까지의 부분 문자열
        // s.substr(pos + key.length()) : pos + key.length()부터 끝까지의 부분 문자열
        s = s.substr(0, pos) + '1' + s.substr(pos + key.length());
    }

    // 최종 결과가 "1"이면 True, 아니면 False
    if (s == "1")
        std::cout << "True\n";
    else
        std::cout << "False\n";

    return 0;
}
