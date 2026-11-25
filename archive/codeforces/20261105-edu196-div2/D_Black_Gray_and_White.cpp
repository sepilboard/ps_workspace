#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    
    vector<vector<int>> adj(N+1, vector<int>());
    for(int i = 1; i<N; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(N%2 == 0){
        cout << N+1 <<"\n";
        return;
    }
    
    auto chk = [&](int root, int k) -> bool {
        for(int rchild: adj[root]){
            vector<char> vst(N+1, false);
            vst[root] = true;
            queue<int> q;
            q.push(rchild);
            vst[rchild] = true;
            vector<int> subtree;
            subtree.push_back(rchild);
            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int nxt: adj[cur]){
                    if(vst[nxt]) continue;
                    vst[nxt] = true;
                    subtree.push_back(nxt);
                    q.push(nxt);
                }
            }

            for(int sub: subtree){
                if(vst[sub] != vst[k-sub]){
                    return true;
                }
            }
        }
        return false;
    };

    if(chk(1, N+2)){
        cout << N+2 <<"\n";
        return;
    }

    if(chk((N+1)/2, N+1)){
        cout << N+1 <<"\n";
        return;
    }
    
    // if(chk(N, N)){
    //     cout << N <<"\n";
    //     return;
    // }

    cout << N <<"\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}