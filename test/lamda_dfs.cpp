#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



signed main()
{
    FASTIO;
    
    int n = 5;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i<=n; i++){
        adj[i].push_back(i+1);
    }
    adj[5][0] = 1;
    vector<char> vst(n+1, false);

    auto dfs = [&](auto &&self, int cur) -> void {
        if(vst[cur]) return;
        vst[cur] = true;

        cout << cur << " ";

        for(int nxt: adj[cur]){
            self(self, nxt);
        }
    };

    dfs(dfs, 1);

    return 0;
}