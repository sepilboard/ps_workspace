#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;

    string a, b;
    cin >> a >> b;

    vector<int> cnt(26, 0);
    
    for(int i = 0; i<N; i++){
        cnt[a[i]-'a']++;
    }

    for(int i = 0; i<M; i++){
        // cout << int(b[i]-'a') <<"\n";
        cnt[b[i]-'a']--;   
    }

    for(int i = 0; i<26; i++){
        if(int('s'-'a') == i || int('i'-'a') == i || int('x'-'a') == i){
            if(cnt[i] != 1){
                cout << "NO\n";
                return;
            }
        }
        else{
            if(cnt[i] != 0){
                // cout << i <<": " << cnt[i] << "\n";
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}