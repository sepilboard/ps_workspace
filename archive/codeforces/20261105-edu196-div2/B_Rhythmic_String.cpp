#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];   
    }

    int ans = 1e+9;
    for(int i = 0; i<N; i++){
        int cnt = 0;
        for(int j = 0; j<N; j++){
            if(a[j]%a[i]){
                cnt++;
            }
        }

        ans = min(ans, cnt);
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