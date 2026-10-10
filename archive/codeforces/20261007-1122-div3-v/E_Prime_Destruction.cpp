#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<char> is_p;
vector<int> bpf;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    vector<ll> dp(n+1, -1);
    auto go = [&](auto&& self, int cur) -> ll {
        ll& ret = dp[cur];
        if(ret != -1)  return ret;

        if(cur<=k){
            return ret = 0;
        }

        ret = numeric_limits<ll>::max();
        int x = cur;
        while(x != 1){
            int p = bpf[x];
            ret = min(ret, 1 + self(self, cur/p)*p);
            while(x%p == 0) x /= p;
        }
        return ret;
    };

    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += go(go, a[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    FASTIO;

    is_p.resize(200'001, true);
    is_p[1] = false;
    bpf.resize(200'001, 1);
    for(ll i = 2; i<=200'000; i++){
        if(!is_p[i]) continue;
        bpf[i] = i;
        for(ll j = i*i; j<=200'000; j+=i){
            is_p[j] = false;
            bpf[j] = i;
        }
    }

    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}