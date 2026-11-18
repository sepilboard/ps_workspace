#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    string s;
    cin >> s;
    int m;
    cin >> m;

    int N = s.length();
    vector<int> pcnt(N+1);
    
    for(int i = N-1; i>=0; i--){
        pcnt[i] = pcnt[i+1] + (s[i]=='K' || s[i] == 'C');
    }

    ll ans = 0;
    for(int i = N-1; i>=0; i--){
        if(s[i] != 'A') continue;

        int use = min(m, pcnt[i]);
        m -= use;
        
        ans += pcnt[i]-use;
    }

    cout << ans << "\n";
    
    return 0;
}