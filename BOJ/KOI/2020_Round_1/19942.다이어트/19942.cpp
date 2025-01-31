#include<bits/stdc++.h>

static int N;
static int mp, mf, ms, mv;
static int p[16], f[16], s[16], v[16], cost[16];

int main(void) {
    std::cin >> N;
    std::cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++) {
        std::cin >> p[i] >> f[i] >> s[i] >> v[i] >> cost[i];
    }

    int answer = INT_MAX;  // 최소 비용 저장
    int answer_combination = 0;  // 최소 비용일 때 선택한 아이템들의 조합

    for(int i = 0; i < (1 << N); i++) {
        int sum_p = 0, sum_f = 0, sum_s = 0, sum_v = 0, sum_cost = 0;

        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                sum_p += p[j];
                sum_f += f[j];
                sum_s += s[j];
                sum_v += v[j];
                sum_cost += cost[j];
            }
        }
        
        if(sum_p >= mp && sum_f >= mf && sum_s >= ms && sum_v >= mv) {
            if(answer > sum_cost) {
                answer = sum_cost;
                answer_combination = i;
            }
            else if(answer == sum_cost) {
                answer = sum_cost;
                std::string lhs = "", rhs = "";
                for(int j=0; j<N; j++) {
                    if(i & (1 << j)) lhs += (char)(j + 1);
                    if(answer_combination & (1 << j)) rhs += (char)(j + 1);
                }
                if(lhs < rhs) answer_combination = i;
            }
        } 
    }

    if (answer == INT_MAX) {
        std::cout << -1;  // 조건을 만족하는 조합이 없는 경우
    } else {
        std::cout << answer << "\n";
        for (int i = 0; i < N; i++) {
            if (answer_combination & (1 << i)) {
                std::cout << i + 1 << " ";
            }
        } std::cout << "\n";
    }

    return 0;
}
