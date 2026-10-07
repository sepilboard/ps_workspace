#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<char> chk(n+1, false);
    vector<int> stk;
    for(int i = 1; i<=n; i++){
        char c;
        cin >> c;

        if(c == '1'){
            stk.push_back(i);
        }
        else if(c == '2'){
            if(stk.empty()) chk[i] = true;
            else{
                int cur = stk.back();
                stk.pop_back();
                chk[cur] = true;
            }
        }
        else{
            chk[i] = true;
        }
    }

    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(chk[i]) continue;
        ans.push_back(i);
    }
    cout << ans.size() <<"\n";
    for(int a: ans) cout << a << " ";
    cout << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}