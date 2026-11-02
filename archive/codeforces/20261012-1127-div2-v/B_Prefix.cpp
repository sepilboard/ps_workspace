#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    
    vector<ll> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];        
    }

    ll ans = -2e+18;
    vector<array<ll, 3>> s(N+1, {0, 0, 0});
    vector<ll> mns(N+1, 0);
    vector<ll> mxs(N+1, 0);
    for(int i = 1; i<=N; i++){
        ll tans = max(a[i], max(a[i]+mxs[i-1], a[i]-mns[i-1]));
        ans = max(ans, tans);

        mns[i] = min(a[i], a[i]+2*mns[i-1]);
        mxs[i] = max(a[i], a[i]+2*mxs[i-1]);
    }
    cout << ans  << "\n";

    // for(int i = 1; i<=N; i++){
    //     cout << mxs[i] <<" ";   
    // }
    
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}