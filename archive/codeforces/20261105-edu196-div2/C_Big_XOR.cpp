#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> cnt(60, 0);
    for(int i = 1; i<=N; i++){
        int bit = 1;
        for(int shift = 0; bit<=i; shift++){
            if(i&bit){
                cnt[shift]++;
            }
            bit <<= 1;
        }
    }

    
    vector<int> ans(N+1, 0);
    int pw = 31 - __builtin_clz(N)+1;

    // for(int i = 0; i<=pw; i++){
    //     cout << cnt[i] <<" ";
    // } cout << "\n";

    for(int i = pw; i>=1; i--){
        // cout << i <<": ";
        if(cnt[i]%2 == 0){
            // cout << "!";
            cnt[i-1]--;
            ans[1<<(i-1)] = 1;
        }
        // cout << "\n";
    }

    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
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