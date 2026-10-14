#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    for(int i = 0; i<M; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int mx_edg = -1;
    int s = 0;
    for(int i = 1; i<=N; i++){
        if(adj[i].size() == 0){
            cout << "Brain Melt\n";
            return;
        }

        // cout << adj[i].size() << " " << mx_edg <<"\n";
        if((int)adj[i].size()>mx_edg){
            mx_edg = adj[i].size();
            s = i;
        }
    }

    vector<char> vst(N+1, false);
    vst[s] = true;
    for(int nxt: adj[s]){
        vst[nxt] = true;
    }
    
    // cout << s << "\n";
    for(int i = 1; i<=N; i++){
        if(!vst[i]){
            cout << "Many\n";
            return;
        }
    }
    for(int i = 1; i<=N; i++){
        if(i == s) continue;
        if((int)adj[i].size() != 1){
            cout << "Many\n";
            return;
        }
    }
    
    cout << "2\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}