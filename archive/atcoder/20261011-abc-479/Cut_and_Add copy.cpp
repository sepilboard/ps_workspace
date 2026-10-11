#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> adj(N+1, vector<pair<int, int>>());
    vector<tuple<int, int>> edg(N);
    vector<int> idg(N+1, 0);
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        edg[i] = {a, b};
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        idg[a]++;
        idg[b]++;
    }

    queue<int> q;
    vector<int> cnt(N+1, 1);
    for(int i = 1; i<=N; i++){
        if(idg[i] == 1){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto[nxt, idx]: adj[cur]){
            if(idg[nxt] != 1){
                cnt[nxt]+=cnt[cur];
                if(--idg[nxt] == 1){
                    q.push(nxt);
                }
            }
        }
    }

    int s = 0;
    int mxcnt = -1;
    for(int i = 1; i<=N; i++){
        if(mxcnt<cnt[i]){
            s = i;
            mxcnt = cnt[i];
        }
    }

    vector<ll> x(N+1);
    x[s] = 1LL*N*(N-1)/2;
    auto dfs = [&](int cur, int prv, ll sum, auto&& self) -> void {
        x[cur] = x[s] - sum;
        
        for(auto[nxt, idx]: adj[cur]){
            if(nxt == prv) continue;
            self(nxt, cur, sum+idx, self);
        }
    };
    
    dfs(s, -1, 0, dfs);
    
    for(int i = 1; i<=N; i++){
        cout << x[i] << " ";
    }
    cout << "\n";
    
    return 0;
}