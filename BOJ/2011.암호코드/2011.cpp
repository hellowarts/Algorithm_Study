#include<bits/stdc++.h>
static std::string number;
int cache[5001];

int main(void) {
    std::cin >> number;
    if(number[0] == '0') {
        std::cout << 0;
        return 0;
    }
    int N = number.length();
    cache[0] = cache[1] = 1;
    for(int i=2; i<=N; i++) {
        if(number[i-1] != '0')
            cache[i] = cache[i-1] % 1000000;
        int tmp = int(number[i-1]-'0')+int(number[i-2]-'0')*10;
        if(10 <= tmp && tmp <= 26 )
            cache[i] = (cache[i] + cache[i-2]) % 1000000;
    }
    std::cout << cache[N];
}