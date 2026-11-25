#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<ll> a(N+1);
    vector<ll> psum(N+1, 0LL);
    for(int i = 1; i<=N; i++){
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }   

    ll lo = 0, hi = 1e+18;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;

        ll sec = 0LL;
        for(int i = 1; i<=N; i++){
            if(psum[i] > mid || psum[N]-psum[i-1] > mid){
                sec += a[i];
            }
        }
        
        if(sec > mid) lo = mid;
        else hi = mid;
    }

    cout << hi << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}