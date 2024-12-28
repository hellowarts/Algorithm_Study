#include<bits/stdc++.h>
static int N, M;
std::vector<int> a;

int main(void) {
    std::cin >> N >> M;
    a.resize(N);
    for(int i=0; i<N; i++) std::cin >> a[i];

    for(int i=0; i<N-M+1; i++) {
        int V;
        std::cin >> V;
        std::sort(a.begin(), a.begin()+M);
        a.erase(a.begin() + V - 1);
    }
    std::sort(a.begin(), a.end());
    for(int answer : a) {
        std::cout << answer << ' ';
    }
}