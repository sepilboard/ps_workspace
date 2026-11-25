#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, x;
    cin >> N >> x;
    
    vector<int> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];   
        a[i] = (a[i]+x-1)/x-1;
    }
    sort(a.begin(), a.end());

    ll cnt = 1;
    ll ans = a[0];
    for(int i = 1; i<N-1; i++){
        if(a[i-1] == a[i]){
            cnt++;
        }
        else{
            ll diff = a[i]-a[i-1];
            ll use = min(diff, cnt);
            ans += diff - use;
            cnt = cnt - use + 1;
        }
        // cout << i << ":" << ans << "\n";
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