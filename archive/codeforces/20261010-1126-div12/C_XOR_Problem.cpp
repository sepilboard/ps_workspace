#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int mx = 1<<(31-__builtin_clz(n)+1);
    // cout << mx<<": ok\n"; return;

    vector<int> pref;
    for(int i = 0; i<(mx>>1); i++){
        pref.push_back(i);
    }
    for(int i = mx-1; i>=(mx>>1); i--){
        pref.push_back(i);
    }
    
    cout << (mx<<1)-1 <<"\n";
    for(int i = 0; i<(mx<<1)-1; i++){
        cout << (pref[(i+1)%mx]^pref[i%mx]) << " ";
    }
    cout << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}