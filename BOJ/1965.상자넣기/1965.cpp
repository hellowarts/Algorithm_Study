#include<bits/stdc++.h>
static std::vector<int> boxes;
static std::vector<int> cache;
static int n;

int count(int start) {
    if(start == 0) return 1;
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=0; i<start; ++i) {
        if(boxes[start] > boxes[i])
            ret = std::max(ret, count(i)+1);
    }
    return ret;
}

int main(void) {
    std::cin >> n;
    boxes.resize(n);
    cache = std::vector<int>(n, -1);
    for(int i=0; i<n; i++) std::cin >> boxes[i];
    
    int answer = 0;
    for(int i=0; i<n; i++) {
        answer = std::max(answer, count(i));
    }
    std::cout << answer;
} 