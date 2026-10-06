#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define MOD 1'000'000'007

ll pw(ll x, ll y)
{
    ll res = 1LL;
    while(y){
        if(y&1) res = res*x%MOD;
        x = x*x%MOD;
        y>>=1;
    }
    return res;
}

vector<ll> facto;
vector<ll> inv_facto;

void setup_comb(int n)
{
    facto.resize(n+1);
    inv_facto.resize(n+1);
    
    facto[0] = 1LL;
    for(int i = 1; i<=n; i++) facto[i] = facto[i-1]*i%MOD;
    inv_facto[n] = pw(facto[n], MOD-2);
    for(int i = n; i>0; i--) inv_facto[i-1] = inv_facto[i]*i%MOD;
}

ll nCr(int n, int r)
{
    if(r<0 || n<r) return 0LL;
    return facto[n]*inv_facto[r]%MOD*inv_facto[n-r]%MOD;
}

// nCr = r! / r!*(n-r)!
// nHr = n+r-1Cr
// 중복조합은 n+r-1까지 전처리 해야함