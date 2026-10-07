#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i = 1; i<=n; i++) cin >> a[i];
    for(int i = 1; i<=n; i++) cin >> b[i];

    vector<int> gunsil(n+1, 0);
    vector<int> twist(n+1, 0);
    
    gunsil[1] = 1+(a[1] == b[1]);
    for(int i = 2; i<=n; i++){
        gunsil[i] = gunsil[i-1] + 2 + (int)(b[i-1] == a[i]) + (int)(a[i] == b[i]);
    }

    for(int i = 2; i<=n; i++){
        twist[i] = twist[i-1] + 2 + (int)(a[i-1] == b[i]) + (int)(a[i] == b[i-1]);
    }

    int ans = gunsil[n];
    for(int i = 1; i<n; i++){
        int tans = gunsil[i] + (int)(twist[n]-twist[i]) + 1+(int)(a[n] == b[n]);
        ans = max(ans, max(tans-(1+(a[i] == b[i])), tans-(1+(a[i]==b[i+1]))));
        // cout << i <<": " << tans-(1+a[i] == b[i]) <<"," << tans-(1+a[i]==b[i+1]) << "\n";
    }

    cout << ans << "\n";

    // cout << gunsil[1];
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}