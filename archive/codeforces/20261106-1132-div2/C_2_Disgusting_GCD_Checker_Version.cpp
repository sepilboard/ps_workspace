#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<int> prime;
vector<char> is_p;
int sg;

void solve()
{
    int a, b;
    cin >> a >> b;

    if(a == b){
        cout << "0\n";
        return;
    }

    vector<int> ans;
    int x = b-a;
    if(x%2 == 0){
        ans.push_back(1);
        x-=1;
    }

    if(x >= 200'000){
        int cnt = x/(1<<14);
        int r = x%(1<<14);
        
        // cout << x << "\n";

        for(int i = 0; i<cnt; i++){
            ans.push_back(sg);
        }
        for(int p: prime){
            if(is_p[r-p]){
                ans.push_back(p);
                ans.push_back(r-p);
                break;
            }
        }   
    }
    else{
        for(int p: prime){
            if(is_p[x-p]){
                ans.push_back(p);
                ans.push_back(x-p);
                break;
            }
        }
    }

    cout << ans.size() <<"\n";
    for(int e: ans){
        cout << e << " ";
    }
    cout << "\n";
}

signed main()
{
    FASTIO;

    is_p.assign(200'001, true);
    is_p[1] = false;
    for(int i = 2; i<=200'000; i++){
        if(!is_p[i]) continue;
        prime.push_back(i);
        for(ll j = 1LL*i*i; j<=200'000; j+=i){
            is_p[j] = false;
        }
    }

    sg = *lower_bound(prime.begin(), prime.end(), (1<<14));

    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}