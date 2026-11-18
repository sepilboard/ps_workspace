#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


void solve()
{
    int N;
    string s;

    cin >> N >> s;
    
    vector<char> stk;
    bool rvs = false;
    for(int i = N-1; i>=0; i--){
        if(rvs){
            stk.push_back((s[i]=='O'? 'M':'O'));
        }
        else{
            stk.push_back(s[i]);
        }

        if(stk.back() == 'O'){
            rvs = !rvs;
        }
    }

    while(!stk.empty()){
        cout << stk.back();
        stk.pop_back();
    }
    cout << "\n";
}

int main()
{
    FASTIO;
    
    int tc, k; cin >> tc >> k;
    while(tc--){
        cout << "YES\n";
        if(k) solve();
        else{
            int n, s;
            cin >> n >> s;
        }
    }
    return 0;
}