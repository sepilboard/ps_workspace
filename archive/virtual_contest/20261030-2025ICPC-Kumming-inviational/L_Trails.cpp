#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    ll p, q;
    cin >> N >> p >> q;

    map<int, int> mp;
    for(int i = 0; i<N; i++){
        int x, y;
        cin >> x >> y;

        if(mp.count(x)){
            mp[x] = min(mp[x], y);    
        }
        else{
            mp[x] = y;
        }
    }

    ll ans = 0;
    ll sum = p*(p+1)/2;
    for(int i = 0; i<=q; i++){
        ans += sum + p*i;
    }

    for(auto[x, y]: mp){
        
    }
    
    
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}