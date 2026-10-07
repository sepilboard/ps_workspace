#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve()
{
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 1; i<N; i++){
        if(s[i-1] != s[i]) cnt++;
    }
    cout << (cnt+1)/2 <<" ";

    for(int q = 0; q<Q; q++){
        int i;
        cin >> i;
        i--;
        
        // int prv = 0;
        // int cur = 0;
        // if(i!= 0 && s[i-1] != s[i]) prv++;
        // if(i!=N-1 && s[i]!=s[i+1]) prv++;
        int prv = (i!= 0 && s[i-1] != s[i]) + (i!=N-1 && s[i]!=s[i+1]);
        if(s[i] == '0') s[i] = '1';
        else s[i] = '0';

        // if(i!= 0 && s[i-1] != s[i]) cur++;
        // if(i!=N-1 && s[i]!=s[i+1]) cur++;
        int cur = (i!= 0 && s[i-1] != s[i]) + (i!=N-1 && s[i]!=s[i+1]);
        cnt += cur-prv;
        cout << (cnt+1)/2 << " ";
    }
    cout << "\n";
}

signed main()
{
    FASTIO;
    int tc = 1; cin >> tc;
    while(tc--) solve();
    return 0;
}