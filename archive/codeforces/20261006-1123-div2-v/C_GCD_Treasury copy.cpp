#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    vector<ll> cnt(300'001, 0);
    
    for(int i = 0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<char> vst(300'001, false);
    for(int i = 0; i<n; i++){
        int g = __gcd(a[i], x);
        if(vst[g]) continue;
        vst[g] = true;

        for(int j = 2*g; j<=300'000; j+=g){
            cnt[g] += cnt[j]*(j/g);
        }
    }

    ll ans = 0LL;
    for(int i = 0; i<n; i++){
        int g =__gcd(a[i], x);
        ans = max(ans, cnt[g] * a[i]);
    }
    cout << ans << "\n";

    for(int i = 1; i<=9; i++) cout << cnt[i] << " ";
    
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}