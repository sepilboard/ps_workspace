#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point
{
    ll x, y;
    // x좌표 우선, 같으면 y좌표 비교
    bool operator<(const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
};

/**
 * @brief A → B 기준으로 C의 방향
 * @return
 * - 양수: 반시계 (C가 왼쪽).
 * 
 * - 음수: 시계 (C가 오른쪽).
 * 
 * - 0: 세 점이 일직선.
 */
ll CCW(Point A, Point B, Point C)
{
    return (A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x);
}

/**
 * @brief 선분 AB와 CD의 교차 여부를 판정한다.
 * @param include_touch 한 점에서만 만나는 경우 포함 여부
 * @param include_overlap 일직선 위에서 구간이 겹치는 경우 포함 여부
 */
bool intersection(
    Point A, Point B, Point C, Point D,
    bool include_touch = true,
    bool include_overlap = true)
{
    int abc = CCW(A, B, C);
    int abd = CCW(A, B, D);
    int cda = CCW(C, D, A);
    int cdb = CCW(C, D, B);

    // 1. 네 점이 모두 일직선 위에 있는 경우
    //    길이가 0인 선분이 상대 직선 위에 있는 경우도 여기서 처리
    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0) {
        if (B < A) swap(A, B);
        if (D < C) swap(C, D);

        Point L = max(A, C);  // 겹치는 구간의 시작
        Point R = min(B, D);  // 겹치는 구간의 끝

        // 1-1. 겹치는 구간이 없음 → 만나지 않음
        if (R < L) return false;

        // 1-2. 길이가 있는 구간이 겹침
        //      일부 겹침 / 한 선분이 다른 선분에 포함 / 완전히 같음
        if (L < R) return include_overlap;

        // 1-3. 한 점에서만 만남 (L == R)
        //      끝점끼리 만남 / 점인 선분이 상대 선분 위에 있음
        return include_touch;
    }

    int ab = abc * abd;
    int cd = cda * cdb;

    // 2. 두 선분의 내부끼리 교차함 → 항상 포함
    if (ab < 0 && cd < 0) return true;

    // 3. 한 점에서만 만남
    //    3-1. 한 선분의 끝점이 상대 선분 내부에 있음 (T자)
    //    3-2. 두 선분의 끝점이 같음
    //    3-3. 점인 선분이 상대 선분 위에 있음
    if (ab <= 0 && cd <= 0) return include_touch;

    // 4. 만나지 않음
    //    세 점이 일직선이어도 상대 선분의 연장선에만 있으면 여기 해당
    return false;
}