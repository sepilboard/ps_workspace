#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int base = 30'000;
int cnt[60'001];

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    for(int i = 1; i<=n-4; i++){
        int cur = base + a[i] + a[i+2] - a[i+4];
        cnt[cur]++;
    }
    
    ll ans = 0;
    for(int i = 1; i<=n-4; i++){
        int cur = base + a[i] + a[i+2] - a[i+4];
        int imp1 = -1e+9;
        int imp2 = -1e+9;
        if(i+6<=n) imp1 = base + a[i+2] + a[i+4] - a[i+6];
        if(i+8<=n) imp2 = base + a[i+4] + a[i+6] - a[i+8];

        cnt[cur]--;
        ans += cnt[cur] - (imp1 == cur) - (imp2 == cur);

        // cout << i << ": " << cur <<"," << imp1 <<"," << imp2 <<"\n";
    }
    
    cout << ans << "\n";

    for(int i = 1; i<=n-4; i++){
        int cur = base + a[i] + a[i+2] - a[i+4];
        cnt[cur] = 0;
    }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}