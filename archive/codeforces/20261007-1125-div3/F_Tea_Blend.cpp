#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<char> is_p;
vector<int> prime;
void eratos(int N)
{
    is_p.assign(N+1, true);
    
    for(int i = 2; i<=N; i++){
        if(!is_p[i]) continue;
        
        prime.push_back(i);
        for(ll j = 1LL*i*i; j<=N; j+=i){
            is_p[j] = false;
        }
    }
}

int cnt[1'000'001];

void solve()
{
    int N;
    cin >> N;

    vector<int> a(N+1);
    for(int i = 1; i<=N; i++){
        cin >> a[i];
        
        int res = 1;
        for(int p: prime){
            if(a[i] == 1 || is_p[a[i]]) break;
            if(a[i]%p) continue;
            
            int temp = 0;
            while(a[i]%p == 0){
                temp ^= p;
                a[i] /= p;
            }
            if(temp != 0) res *= p;
        }
        if(is_p[a[i]]){
            res *= a[i];
        }
        a[i] = res;
    }

    // for(int i = 1; i<=N; i++){
    //     cout << a[i] <<" ";   
    // } cout << "\n";

    for(int i = 1; i<=N; i++){
        cnt[a[i]]++;
    }

    ll ans = 0LL;
    set<int> st;
    vector<int> b(N+1);
    for(int i = 1; i<=N; i++){
        b[i] = a[i];
        for(int p: prime){
            if(a[i] == 1 || is_p[a[i]]) break;
            if(a[i]%p) continue;
            
            if(st.count(a[i])){
                st.erase(a[i]);
            }
            else{
                st.insert(a[i]);
            }
            a[i] /= p;
        }
        if(is_p[a[i]]){
            if(st.count(a[i])){
                st.erase(a[i]);
            }
            else{
                st.insert(a[i]);
            }
        }

        ll tot = 0;
        if(st.size()<8){
            for(int p: st){
                tot *= p;
                if(tot>1'000'000) break;
            }
        }

        if(tot<=1'000'000){
            ans += N-cnt[tot];
        }
    }

    cout << ans << "\n";

    for(int i = 1; i<=N; i++){
        cnt[b[i]]--;
    }
}

signed main()
{
    FASTIO;
    eratos(1'000'000);
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}