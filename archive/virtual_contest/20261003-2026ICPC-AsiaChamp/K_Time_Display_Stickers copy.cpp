#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    vector<int> cnt(10, 0);
    
    cin >> n;
    for(int i = 0; i<n; i++){
        char c;
        cin >> c;
        cnt[c]++;
    }

    int ans = 0;

    int one_cnt = cnt[6] + cnt[7] + cnt[8] + cnt[9];
    
    int zero_hour = 0;
    if(cnt[0] <= one_cnt){
        zero_hour += cnt[0];
        one_cnt -= cnt[0];
        cnt[0] = 0;
    }
    

    for(int i = 5; i>=0; i--){
        
    }
    
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}