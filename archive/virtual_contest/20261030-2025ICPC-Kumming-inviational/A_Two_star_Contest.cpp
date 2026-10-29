#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, M, k;
    cin >> N >> M >> k;

    vector<int> s(N);
    vector<vector<int>> p(N, vector<int>(M));
    
    vector<tuple<int, int, ll, int>> vec;
    for(int i = 0; i<N; i++){
        cin >> s[i];
        ll sum = 0LL;
        int cnt = 0;
        for(int j = 0; j<M; j++){
            cin >> p[i][j];
            if(p[i][j] != -1) sum += p[i][j];
            else cnt++;
        }

        vec.emplace_back(s[i], i, sum, cnt);
    }
    
    sort(vec.begin(), vec.end());
    
    int psi;
    ll temp;
    ll prevMax = -1;
    {
        auto[si, idx, sum, cnt] = vec[0];
        for(int i = 0; i<M; i++){
            if(p[idx][i] == -1){
                p[idx][i] = 0;
                // cout << i <<": " << p[idx][i] <<"!\n";
            } 
        }
        psi = si;
        temp = sum;
    }

    for(int v = 1; v<N; v++){
        auto[si, idx, sum, cnt] = vec[v];
        if(psi != si){
            prevMax = temp;
            temp = 0;
        }

        if(sum>prevMax){
            for(int i = 0; i<M; i++){
                if(p[idx][i] == -1){
                    p[idx][i] = 0;
                } 
            }
            psi = si;
            temp = max(temp, sum);
            continue;
        }
        
        ll diff =  prevMax - sum+1;
        
        if((diff+k-1)/k > cnt){
            cout << "No\n";
            return;
        }
        sum += diff;
        
        for(int i = 0; i<M; i++){
            if(p[idx][i] == -1){
                int use = min(diff, (ll)k);
                diff -= use;
                p[idx][i] = use;
            }
        }
        psi = si;
        temp = max(temp, sum);
    }

    cout << "Yes\n";
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << p[i][j] <<" ";
        }
        cout << "\n";
    }
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}