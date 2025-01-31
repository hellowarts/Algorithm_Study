#include <bits/stdc++.h>

int main(void) {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;

        int buttons[5] = {0,};
        // ADDH 수행
        buttons[0] = N / 60;
        N %= 60;

        // N이 35보다 작거나 같으면 ADDT와 (MINO or ADDO) 조합이 유리.
        if(N <= 35) {
            // 일의 자리가 5보다 크다면 ADDT를 한 번 더 누른 후 MINO를 누르는게 유리
            if(N % 10 > 5) {
                buttons[1] += N / 10 + 1;
                buttons[4] += 10 - N % 10; 
            }
            // 일의 자리가 5보다 작거나 같으면 ADDT 십의 자리와 같게 누르고 ADDO를 누르는게 유리
            else {
                buttons[1] += N / 10;
                buttons[3] += N % 10;
            } 
        }
        // N이 35보다 크다면 ADDH를 한 번 더 수행한 후 MINT와 (MINO or ADDO) 조합이 유리.
        else {
            buttons[0]++;
            // 일의 자리가 5보다 크거나 같다면 MINT를 한 번 더 누른 후 MINO를 누르는게 유리
            if(N % 10 >= 5) {
                buttons[2] += 6 - (N / 10 + 1);
                buttons[4] += 10 - N % 10; 
            }
            // 일의 자리가 5보다 작다면 MINT를 맞게 누르고 ADDO를 누르는게 유리
            else {
                buttons[2] += 6 - N / 10;
                buttons[3] += N % 10;
            } 
        }
        

        for (int i = 0; i < 5; i++) {
            std::cout << buttons[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
