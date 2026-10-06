#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int x, k;
    int a, b;
    int mask;

__builtin_popcount(x); // 1인 비트의 개수
__builtin_clz(x);      // 최상위 비트부터 연속된 0의 개수 (x == 0 사용 금지)
__builtin_ctz(x);      // 최하위 비트부터 연속된 0의 개수 (x == 0 사용 금지)
__builtin_ffs(x);      // 가장 오른쪽 1의 위치 (1-idx, x == 0이면 0)
__builtin_parity(x);   // 1인 비트 개수의 홀짝 (짝수 0, 홀수 1)

31 - __builtin_clz(x); // 가장 왼쪽 1의 인덱스 = floor(log2(x))
__builtin_ctz(x);      // 가장 오른쪽 1의 인덱스

// C++20
popcount((unsigned int)x);       // 1인 비트의 개수
countl_zero((unsigned int)x);    // 왼쪽부터 연속된 0의 개수 (x == 0이면 32)
countr_zero((unsigned int)x);    // 오른쪽부터 연속된 0의 개수 (x == 0이면 32)
countl_one((unsigned int)x);     // 왼쪽부터 연속된 1의 개수
countr_one((unsigned int)x);     // 오른쪽부터 연속된 1의 개수
bit_width((unsigned int)x);      // 이진수 표현에 필요한 비트 수 (x == 0이면 0)
has_single_bit((unsigned int)x); // 양의 2의 거듭제곱인지 (x == 0이면 false)
bit_floor((unsigned int)x);      // x 이하의 가장 큰 2의 거듭제곱 (x == 0이면 0)
bit_ceil((unsigned int)x);       // x 이상의 가장 작은 2의 거듭제곱 (x == 0이면 1)
rotl((unsigned int)x, k);        // 자료형 전체 비트를 왼쪽으로 k칸 순환 이동
rotr((unsigned int)x, k);        // 자료형 전체 비트를 오른쪽으로 k칸 순환 이동

// 비트 연산: x, a, b, mask는 unsigned long long, 0 <= k < 64
(x >> k) & 1ULL;                 // k번 비트 확인
x |= 1ULL << k;                  // k번 비트를 1로 설정
x &= ~(1ULL << k);               // k번 비트를 0으로 설정
x ^= 1ULL << k;                  // k번 비트 반전
x & -x;                          // 가장 오른쪽 1만 남김 (lowbit)
x & (x - 1);                     // 가장 오른쪽 1 제거
x != 0 && (x & (x - 1)) == 0;    // 양의 2의 거듭제곱인지
__builtin_popcountll(a ^ b);     // a, b에서 서로 다른 비트의 개수

// 1인 비트만 순회: O(popcount(mask))
for(unsigned long long t = mask; t; t &= t-1){
    int k = __builtin_ctzll(t);  // 현재 1인 비트의 인덱스
}

// 모든 부분집합 순회 (공집합 포함): O(2^popcount(mask))
for(unsigned long long sub = mask; ; sub = (sub-1) & mask){
    // sub 처리
    if (sub == 0) break;
}


}