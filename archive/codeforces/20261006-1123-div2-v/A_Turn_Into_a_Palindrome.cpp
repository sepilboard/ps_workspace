#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    char c;
    string s;
    cin >> n >> c;   
    cin >> s;

    int ans = 0;
    for(int i = 0; i<n/2; i++){
        if(s[i] == s[n-i-1]) continue;
        if(s[i] == c || s[n-i-1] == c) ans++;
        else ans += 2;
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