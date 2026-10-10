#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<tuple<int, int, int>> adj[100'005];

struct Compare{ 
    bool operator()(array<ll, 3> a, array<ll, 3> b){ 
        if(a[0] == b[0]) return a[1]< b[1];
        return a[0] > b[0];
    } 
}; 

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

    vector<ll> dist(n+1, 1e+18);
    vector<ll> mnh(n+1, 1e+9);

    dist[1] = 0;
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, Compare> pq;
    pq.push({dist[1], mnh[1], 1});
    while(!pq.empty()){
        auto[d, h, cur] = pq.top();
        pq.pop();

        if(d != dist[cur] || h != mnh[cur]) continue;
        for(auto[nxt, nd, nh]: adj[cur]){
            if(dist[nxt] > d+nd){
                dist[nxt] = d+nd;
                mnh[nxt] = min(mnh[cur], (ll)nh);
                pq.push({dist[nxt], mnh[nxt], nxt});
            }
            if(dist[nxt] == d+nd && mnh[nxt]<min(mnh[cur], (ll)nh)){
                dist[nxt] = d+nd;
                mnh[nxt] = min(mnh[cur], h);
                pq.push({dist[nxt], mnh[nxt], nxt});
            }
        }
    }

    vector<int> ans(n+1);
    for(int i = 1; i<=n; i++){
        if(dist[i]<=mnh[i]) cout << '1';
        else cout << '0';
    }
    cout << "\n";

    // for(int i = 1; i<=n; i++){
    //     cout << mnh[i] <<" ";
    // }
    
    
    return 0;
}