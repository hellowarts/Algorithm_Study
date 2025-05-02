#include <bits/stdc++.h>

int N;
std::vector<std::pair<int, int>> meetings;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

// 최소 회의실 개수 계산 (sweeping)
int min_room_count(const std::vector<std::pair<int, int>>& meetings) {
    std::vector<std::pair<int, int>> events;
    for (auto& m : meetings) {
        events.push_back({m.first, 1});   // 시작: +1
        events.push_back({m.second, -1}); // 종료: -1
    }
    std::sort(events.begin(), events.end());

    int current = 0, max_rooms = 0;
    for (auto& e : events) {
        current += e.second;
        if (current > max_rooms) max_rooms = current;
    }
    return max_rooms;
}

// 회의 최대 개수 계산 (greedy - 끝나는 시간 기준)
int max_meeting_count(std::vector<std::pair<int, int>> meetings) {
    std::sort(meetings.begin(), meetings.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0, last_end = -1;
    for (auto& m : meetings) {
        if (m.first >= last_end) {
            ++count;
            last_end = m.second;
        }
    }
    return count;
}

int main() {
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        int s, e;
        std::cin >> s >> e;
        meetings.push_back({s, e});

        if (is_prime(i)) {
            std::cout << max_meeting_count(meetings) << "\n";
        } else {
            std::cout << min_room_count(meetings) << "\n";
        }
    }

    return 0;
}
