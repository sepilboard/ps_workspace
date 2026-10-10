#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    
    map<int, ll> cnt;
    for(int j = 1; j*j<=300'000; j++){
        for(int i = 0; i<n; i++){
            if(a[i]%j) continue;
    
            cnt[j] += a[i];
            if(j*j>300'000)
            cnt[a[i]/j] += j;
        }
    }

    ll ans = 0LL;
    for(int j = 1; j*j<=300'000; j++){
        if(x%j) continue;
        if(j != 1) ans = max(ans, cnt[j]);
        if(x/j != 1) ans = max(ans, cnt[x/j]);
    }

    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}