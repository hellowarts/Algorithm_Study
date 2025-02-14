#include<bits/stdc++.h>

static int N;
static int array[1000001];

int main(void) {

    std::cin >> N;
    for(int i = 0; i < N; i++) 
        std::cin >> array[i];
    
    long long even_result = 0;
    long long odd_result = 0;

    long long even_count = 0;
    long long odd_count = 0;
    
    for(int i = 0; i < N; i++) {
        if(array[i] % 2 == 0) {
            even_count++;
            even_result += odd_count;
        }
        else {
            odd_count++;
            odd_result += even_count;
        }
    }
    std::cout << std::min(even_result, odd_result);

    return 0;
}