#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> cnt(n+1, 0);
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        cnt[a]++;
    }

    for(int i = 0; i<=n; i++){
        if(k<=(cnt[i]+1)/2 && cnt[i]/2<k){
            cout << "YES\n";
            return;
        }
        if(cnt[i]/2<k){
            cout << "NO\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}