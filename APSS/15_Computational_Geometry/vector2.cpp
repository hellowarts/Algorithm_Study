#include<bits/stdc++.h>

// PI 값은 180도 이기 때문에 acos(0) => 90도 * 2 => 180도 로 설정
const double PI = 2.0 * acos(0.0);

// 2차원 벡터를 나타내는 구조체
struct vector2 {
    double x, y;
    // 생성자를 explicit로 선언하여 묵시적 변환을 막는다.
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    // 벡터의 덧셈
    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    // 벡터의 뺄셈
    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    // 벡터의 실수로의 곱셈
    vector2 operator * (double rhs) const {
        return vector2(x * rhs, y * rhs);
    }
    
    // 두 벡터의 비교
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator < (const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }

    // 벡터의 길이
    double norm() const { return hypot(x, y); }
    // 방향이 같은 단위 벡터(unit vector)를 반환한다.
    // 영벡터에 대해 호출한 경우 반환 값은 정의되지 않는다.
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }
    // x축의 양의 방향으로 부터 이 벡터까지 반시계 방향으로 잰 각도
    double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

    // 내적 / 외적 구현
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
    // 이 벡터를 rhs에 사영한 결과  (사영)
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};