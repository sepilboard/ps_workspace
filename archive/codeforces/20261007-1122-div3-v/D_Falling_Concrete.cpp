#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        a[i] = (a[i]-i);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());    
    // cout << "ok\n"; return;

    int ans = 0;
    int cur = 1;
    for(int i = 1; i<a.size(); i++){
        if(a[i-1]+1 != a[i]){
            ans = max(ans, cur);
            cur = 1;
            continue;
        }
        cur++;
    }
    ans = max(ans, cur);

    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}