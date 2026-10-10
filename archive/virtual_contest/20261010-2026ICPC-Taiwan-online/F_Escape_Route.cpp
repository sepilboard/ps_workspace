#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<tuple<int, int, int>> adj[100'005];

signed main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int x, y, t, h;
        cin >> x >> y >> t >> h;
        adj[x].push_back({y, t, h});
        adj[y].push_back({x, t, h});
    }

    vector<int> need(n+1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    need[1] = 1e+9;
    pq.push({need[1], 1});
    while(!pq.empty()){
        auto[nd, cur] = pq.top();
        pq.pop();
        
        if(need[cur] != nd) continue;

        for(auto[nxt, t, h]: adj[cur]){
            int nnd = min(need[cur]-t, h-t);
            if(need[nxt]>nnd) continue;
            need[nxt] = nnd;
            pq.push({need[nxt], nxt});
        }
    }

    for(int i = 1; i<=n; i++){
        if(need[i] != -1) cout << "1";
        else cout << "0";
    }
    
    return 0;
}