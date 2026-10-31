#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<pair<int, int>> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i].first;   
        a[i].second = i;
    }   

    sort(a.begin(), a.end(), [](auto x, auto y){return abs(x.first)>abs(y.first);});

    int ocnt = N/2;
    int ecnt = N-ocnt;
    // for(int i = 0; i<N; i++){
    //     cout << a[i].first <<" ";   
    // }cout << "\n";

    // cout << ocnt << "," << ecnt << "\n";

    ll ans = 0LL;
    for(int i = 0; i<N; i++){
        auto[val, idx] = a[i];

        if(idx%2){
            if(val<0){
                if(ecnt>0){
                    ecnt--;
                    ans -= val;
                }
                else{
                    ocnt--;
                    ans += val;
                }
            }
            else{
                if(ocnt>0){
                    ocnt--;
                    ans += val;
                }
                else{
                    ecnt--;
                    ans -= val;
                }
            }
        }

        else{
            if(val<0){
                if(ocnt>0){
                    ocnt--;
                    ans -= val;
                }
                else{
                    ecnt--;
                    ans += val;
                }
            }
            else{
                if(ecnt>0){
                    ecnt--;
                    ans += val;
                }
                else{
                    ocnt--;
                    ans -= val;
                }
            }
        }
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