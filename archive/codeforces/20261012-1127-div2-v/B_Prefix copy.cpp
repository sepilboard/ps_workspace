#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    
    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];        
    }

    vector<int> mn(N+1, 0);
    vector<int> mx(N+1, 0);
    int ans = -1e+9;
    for(int i = 1; i<=N; i++){
        mn[i] = min(a[i]-mx[i-1], min(a[i]+mn[i],a[i]));
        mx[i] = max(a[i]-mn[i-1], max(a[i]+mx[i],a[i]));
        ans = max(ans, mx[i]);
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