#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

#define MOD 998244353

vector<ll> facto;

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

void solve()
{
    int N;
    cin >> N;

    vector<ll> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];
        
    }
    
    sort(a.begin()+1, a.end());
    vector<ll> pref(N+1);
    for(int i = 1; i<=N; i++){
        pref[i] = (pref[i-1]+a[i])%MOD;
    }

    ll ans = 0;
    for(int i = 1; i<=N; i++){
        ll cur = (pref[N]-pref[i]+MOD)%MOD;
        cur = (cur - (a[i]*(N-i)%MOD) + MOD)%MOD;
        cur = cur*facto[N-1]%MOD;
        cur = cur*pw(N-i, MOD-2)%MOD;

        ans = (ans+cur)%MOD;
    }

    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    facto.resize(200'001);
    facto[0] = 1;
    for(int i = 1; i<=200'000; i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }

    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}