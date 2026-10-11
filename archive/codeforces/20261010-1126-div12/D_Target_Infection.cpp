#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    ll m, k;   
    cin >> N >> m >> k;

    vector<pair<ll, int>> vtx;
    for(int i = 0; i<N; i++){
        ll l, r;
        cin >> l >> r;
        vtx.push_back({l-m, 1});
        vtx.push_back({r-m+1, -1});
        vtx.push_back({l, 1});
        vtx.push_back({r+1, 1});
    }
    sort(vtx.begin(), vtx.end());
    
    ll cur = -m;
    int delta = 0;
    int idx = 0;
    int n = vtx.size();
    
    ll cnt = 0;
    while(idx<n){
        ll nxt = vtx[idx].first;
        
        ll ncnt = cnt + (nxt-cur)*delta;
        if(delta != 0 && min(cnt, ncnt) <= k && k<=max(cnt, ncnt)){
            cout << cur+(k-cnt)/delta <<"\n";
            return;
        }

        cur = nxt;
        cnt = ncnt;

        while(idx<n && vtx[idx].first == cur){
            delta += vtx[idx].second;
            idx++;
        }
    }
    cout << "-1\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}