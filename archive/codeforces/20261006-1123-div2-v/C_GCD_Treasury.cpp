#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    
    int mx = x;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    ll ans = 0;
    for(int g = 1; g*g<=mx; g++){
        if(g != 1 && x%g == 0){
            ll cnt = 0;
            for(int i = 0; i<n; i++){
                if(a[i]%g) continue;
                cnt += a[i];
            }
            ans = max(ans, cnt);
        }
        if(mx/g != 1 && x%(mx/g) == 0){
            ll cnt = 0;
            for(int i = 0; i<n; i++){
                if(a[i]%(mx/g)) continue;
                cnt += a[i];
            }
            ans = max(ans, cnt);
        }
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