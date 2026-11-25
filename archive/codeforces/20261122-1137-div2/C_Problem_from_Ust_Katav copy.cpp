#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];
    }

    vector<ll> imos(N+2, 0LL);
    int l = 1, r = N+1;
    while(l<r){
        imos[l++] += 1;
        imos[r--] -= 1;
    }

    for(int i = 1; i<=N; i++){
        imos[i] += imos[i-1];
    }

    ll ans = N*(N+1)/2;
    for(int i = 2; i<N; i++){
        if(a[i-1]>a[i] && a[i]<a[i+1]){
            ans -= imos[i];
            ans += 2;
        }

        cout << i << ": " << ans << "\n";
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