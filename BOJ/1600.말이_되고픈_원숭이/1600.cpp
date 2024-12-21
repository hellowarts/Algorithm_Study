#include<bits/stdc++.h>
static int K, W, H;
static int map[201][201];

int main(void) {
    std::cin >> K;
    std::cin >> W >> H;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) 
            std::cin >> map[i][j];
    }
    
    return 0;
}