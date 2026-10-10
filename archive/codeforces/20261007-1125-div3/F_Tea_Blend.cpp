#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    
    vector<ll> a(n+1);
    vector<vector<int>> oprime(n+1);
    map<ll, int> ccnt;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        ll mx = a[i];
        for(ll j = 2; j*j<=mx; j++){
            if(a[i]%j) continue;
            int cnt = 0;
            while(!(a[i]%j)){
                cnt++;
                a[i] /= j;
            }
            if(cnt&1){
                oprime[i].push_back(j);
            }
        }
        if(a[i] != 1){
            oprime[i].push_back(a[i]);
            a[i] = 1;
        }
        for(int op: oprime[i]){
            a[i] *= op;
        }
        
        ccnt[a[i]]+=1;
    }

    vector<ll> pref(n+1, 1);
    for(int i = 1; i<=n; i++){
        pref[i] = pref[i-1]*a[i];

        for(int op: oprime[i]){
            if(pref[i]%op) continue;
            int cnt = 0;
            while(!(pref[i]%op)){
                cnt++;
                pref[i] /= op;
            }
            if(cnt&1){
                pref[i] *= op;
            }
        }
    }
    
    ll ans = 0LL;
    for(int i = 1; i<=n; i++){
        ans += ccnt[pref[i]];
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