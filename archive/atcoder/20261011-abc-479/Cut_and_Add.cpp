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

    vector<int> parent(N+1);
    parent[1] = 1;
    vector<int> ordr;

    auto dfs_ordr = [&](int cur, int prv, auto&& self) -> void {
        ordr.push_back(cur);
        parent[cur] = prv;
        
        for(auto[nxt, idx]: adj[cur]){
            if(nxt == prv) continue;
            self(nxt, cur, self);
        }
    };

    dfs_ordr(1, -1, dfs_ordr);

    vector<int> cnt(N+1, 1);
    for(int i = N-i; i>=0; i--){
        cnt[parent[i]] += cnt[i];
    }
    
    vector<ll> x(N+1, 0LL);
    for(int i = 1; i<N; i++){
        auto[a, b] = edg[i];        
        if(a != 1 && cnt[a]>N/2){
            x[1] += i;
        }
        if(b != 1 && cnt[b]>N/2){
            x[1] += i;
        }
    }

    auto dfs = [&](int cur, int prv, auto&& self) -> void {
        
        for(auto[nxt, idx]: adj[cur]){
            if(nxt == prv) continue;
            if(prv != -1){
                if(cnt[cur]>N/2){
                    x[cur] = x[prv] + idx;
                }
                else{
                    x[cur] = x[prv] - idx;
                }
            }
            self(nxt, cur, self);
        }
    };

    dfs(1, -1, dfs);
    for(int i = 1; i<=N; i++){
        cout << x[i] << " ";   
    }
    
    
    return 0;
}