#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    
    vector<char> s(n+1);
    vector<int> zcnt(n+1, 0);
    vector<int> ocnt(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin >> s[i];

        zcnt[i] = zcnt[i-1];
        ocnt[i] = ocnt[i-1];
        if(s[i] == '0') zcnt[i]++;
        else ocnt[i]++;
    }

    if(s[1] == '1'){
        cout << zcnt[n] <<"\n";
        return;
    }
    
    int ans = 1e+9;
    for(int i = 0; i<=n; i++){
        ans = min(ans, ocnt[i]+zcnt[n]-zcnt[i]);
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