#include <string>
#include <vector>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int x = 0, y = 0;
int dir = 0; // 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽

vector<int> solution(string command) {
    for(char c : command) {
        if(c == 'R') dir = (dir + 1) % 4; // 오른쪽으로 회전
        if(c == 'L') dir = (dir + 3) % 4; // 왼쪽으로 회전

        if(c == 'G') {
            x += dx[dir]; // 현재 방향으로 이동
            y += dy[dir];
        }
        if(c == 'B') {
            x -= dx[dir]; // 반대 방향으로 이동
            y -= dy[dir];
        }
    }

    return {x, y};
}