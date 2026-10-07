#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> cnt(101, 0);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> ans;
    for(int i = 0; i<n; i++){
        for(int num = 100; num>=1; num--){
            if(!cnt[num]) continue;

            ans.push_back(num);
            cnt[num]--;
        }
    }

    for(int e: ans){
        cout << e << " ";
    }
    cout << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}