#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    string s;
    cin >> s;

    N = s.length();
    vector<char> str(3*N);
    
    for(int i = 0; i<N; i++){
        str[i] = str[i+N] = str[i+2*N] = s[i];
    }

    if(N == 1){
        cout << "0\n";
        return;
    }

    int idx = 0;
    vector<int> lnk;
    while(idx<N){
        int cnt = 1;
        while(true){
            if(idx == N-1 || s[idx] != s[idx+1]){
                idx++;
                lnk.push_back(cnt);
                break;
            }
            else{
                idx++;
                cnt++;
            }
        }
    }

    if(lnk.size() != 1 && s.front() == s.back()){
        lnk[0] += lnk.back();
        lnk.pop_back();
    }

    int ans = 0;
    bool flag = true;
    for(int e: lnk){
        if(lnk.size() != 1 && flag && e%2 == 0){
            flag = false;
            ans += e/2 -1;
        }
        else{
            ans += e/2;
        }
    }

    cout << ans << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}