#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


vector<int> adj[200'001];

int main()
{
    FASTIO;
    
    int N;
    cin >> N;

    for(int i = 1; i<N; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> color(N+1);
    for(int i = 1; i<=N; i++){
        cin >> color[i];   
    }

    vector<char> vst(N+1, false);
    queue<pair<int, int>> q;
    int last = 1;
    int dia = 0;
    
    q.push({last, 0});
    vst[last] = true;
    while(!q.empty()){
        auto[cur, d] = q.front();
        q.pop();
        
        last = cur;

        for(int nxt: adj[cur]){
            if(vst[nxt]) continue;
            vst[nxt] = true;
            q.push({nxt, d+1});
        }
    }

    vector<int> parent(N+1);

    fill(vst.begin(), vst.end(), false);
    vst[last] = true;
    q.push({last, 0});
    while(!q.empty()){
        auto[cur, d] = q.front();
        q.pop();
        
        last = cur;
        dia = d;

        for(int nxt: adj[cur]){
            if(vst[nxt]) continue;
            vst[nxt] = true;
            parent[nxt] = cur;
            q.push({nxt, d+1});
        }
    }
    // cout << dia <<"!\n";
    // 지름 끝

    if(dia%2){
        vector<int> cnt1(N+1);
        vector<int> cnt2(N+1);

        fill(vst.begin(), vst.end(), false);
        vst[last] = true;
        q.push({last, 0});
        while(!q.empty()){
            auto[cur, d] = q.front();
            q.pop();
            
            last = cur;
            if(d == dia){
                cnt1[color[cur]]++;
            }

            for(int nxt: adj[cur]){
                if(vst[nxt]) continue;
                vst[nxt] = true;
                q.push({nxt, d+1});
            }
        }

        fill(vst.begin(), vst.end(), false);
        vst[last] = true;
        q.push({last, 0});
        while(!q.empty()){
            auto[cur, d] = q.front();
            q.pop();
            
            last = cur;
            if(d == dia){
                cnt2[color[cur]]++;
            }

            for(int nxt: adj[cur]){
                if(vst[nxt]) continue;
                vst[nxt] = true;
                q.push({nxt, d+1});
            }
        }

        ll ans = 0LL;
        for(int i = 1; i<=N; i++){
            ans += 1LL* cnt1[i]*cnt2[i];
        }

        cout << ans << "\n";
        return 0;
    }

    // cout << "ok\n"; return 0;
    // 짝수
    vector<int> path;
    for(int v = last; v != 0; v = parent[v]){
        path.push_back(v);
    }

    int center = path[dia/2];
    vector<ll> prv(N+1, 0);
    ll ans = 0LL;
    for(int e : adj[center]){
        queue<tuple<int,int,int>> q;
        q.push({e, center, 1});

        vector<int> ccolor;

        while(!q.empty()){
            auto[v, p, d] = q.front();
            q.pop();

            if(d == dia/2){
                ans += prv[color[v]];
                ccolor.push_back(color[v]);
                continue;
            }

            for(int nxt : adj[v]){
                if(nxt == p) continue;
                q.push({nxt, v, d+1});
            }
        }

        for(int c : ccolor){
            prv[c]++;
        }
    }
    
    cout << ans <<"\n";

    
    return 0;
}