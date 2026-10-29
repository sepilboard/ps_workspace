#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;   

    int cur = 0;
    vector<int> ans;
    for(int i = 0; i<N; i++){
        // cout << i << ": " << cur <<"\n";
        // cout << (1^2) <<"\n";
        if((cur^i) == 0){
            if(i == N-1){
                cout << "impossible\n";
                return;
            }
            ans.push_back(i+1);
            ans.push_back(i);
            cur ^= i+1;
            cur ^= i;
            i++;
        }
        else{
            ans.push_back(i);
            cur ^= i;
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