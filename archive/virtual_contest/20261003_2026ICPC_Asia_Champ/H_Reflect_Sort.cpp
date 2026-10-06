#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



signed main()
{
    FASTIO;
    
    int n;
    cin >> n;
       
    vector<ll> a(n+1);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    vector<ll> pref_diff(n+1, 0LL);
    for(int i = 1; i<n; i++){
        pref_diff[i] = pref_diff[i-1] + abs(a[i]-a[i-1]);
    }

    ll ans = 1e+18;
    for(int i = 0; i<n; i++){
        // cout << i<<": " << a[i] + (pref_diff[n-1]-pref_diff[i]) <<"\n";
        ll an = 2*a[i] - a[n-1];

        // if(an == )
        if(an - pref_diff[n-1] <= 0) continue;
        
        ans = min(ans, an);
    }

    cout << ans << "\n";


    return 0;
}