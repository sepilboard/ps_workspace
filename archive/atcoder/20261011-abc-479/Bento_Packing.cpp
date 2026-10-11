#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int n;
    ll w;
    cin >> n >> w;

    vector<pair<ll, ll>> ab(n);
    for(int i = 0; i<n; i++){
        cin >> ab[i].first >> ab[i].second;
    }

    int mxbit = (1<<n);
    ll ans = 0LL;
    for(int bit = 0; bit<mxbit; bit++){
        ll tans = 0LL;
        ll cur_b = 0LL;
        for(int i = 0; i<n; i++){
            if(bit&(1<<i)){
                tans += ab[i].first;
                cur_b += ab[i].second;
            }
        }

        if(cur_b<=w){
            ans = max(ans, tans);
        }
    }

    cout << ans << "\n";
    
    return 0;
}