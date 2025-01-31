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

// (a, b) 를 포함하는 선과 (c, d)를 포함하는 선의 교점을 x에 반환한다.
// 두 선이 평행이면 false를 반환한다.
bool lineIntersection(const vector2& a, const vector2& b, const vector2& c, const vector2& d, vector2& x) {
    double det = (b - a).cross(d - c);
    // 두 선이 평행한 경우
    if(fabs(det) < 1e-9) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// (a, b)와 (c, d)가 평행한 두 선분일 때 이들이 한 점에서 겹치는지 확인한다.
bool parallelSegments(const vector2 a, const vector2 b, const vector2 c, const vector2 d, vector2& p) {
    if(b < a) std::swap(a, b);
    if(d < c) std::swap(c, d);
    // 한 직선 위에 없거나 두 선분이 겹치지 않는 경우는 우선 걸러낸다.
    if(ccw(a, b, c) != 0 || b < c || d < a) return false;
    // 두 선분이 겹치는 경우, 교차점을 하나 찾는다.
    if(a < c) p = c;
    else p = a;
    return true;
}
// p가 (a, b)를 감싸면서 각 변이 x, y와 평행한 최소 사각형 내부에 있는지 확인한다.
// a, b, p는 일직선 상에 있다고 가정한다.
bool inBoundingRectangle(const vector2 p, const vector2 a, const vector2 b) {
    if(b < a) std::swap(a, b);
    return p == a || p == b || (a < p && p < b);
}
// (a, b) 선분과 (c, d) 선분의 교점을 p에 반환한다.
// 교점이 여러 개일 경우 아무 점이나 반환한다.
// 두 선분이 교차하지 않는 경우 false를 반환한다.
bool segmentIntersection(const vector2 a, const vector2 b, const vector2 c, const vector2 d, vector2& p) {
    // 두 직선이 평행인 경우를 우선 예외로 처리한다.
    if(!lineIntersection(a, b, c, d, p)) {
        return parallelSegments(a, b, c, d, p);
    }
    // p가 두 선분에 포함되어 있는 경우에만 참을 반환한다.
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}