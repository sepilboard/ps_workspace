#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    ll lo = -1e+10, hi = 2e+18;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        ll cur_k = k;
        for(int i = 0; i<n; i++){
            if(a[i] == b[i] && b[i] == c[i]){
                if(a[i]+b[i]+c[i]<mid){
                    cur_k = -1;
                    break;
                }
            }
            if(a[i]+b[i]+c[i] >= mid) continue;

            ll need = 0LL;
            if(a[i] <= b[i] && b[i] <= c[i]){
                need = 2*(min(c[i]-b[i], min(b[i]-a[i], c[i]-a[i]))+1);
            }
            need += mid - (a[i]+b[i]+c[i]);
            cur_k -= need;

            if(cur_k<0) break;
        }

        if(cur_k<0) hi = mid;
        else lo = mid;
    }

    cout << lo << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}