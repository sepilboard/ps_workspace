#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, Q;
char s[200'005];

bool v[200'005];

int remain = 0;
int black = 0;
vector<int> brg;

signed main()
{
    FASTIO;
    
    cin >> n >> Q;
    for(int i = 1; i<=n; i++) cin >> s[i];

    s[0] = '0';
    s[n+1] = '0';

    for(int i = 1; i<=n; i++){
        if(s[i-1] =='0' && s[i] == '1') black++;
        else{
            if(s[i-1] == '0' && s[i] == '0' &&s[i+1] == '0'){
                if(!v[i]){
                    v[i+1] = true;
                    remain++;
                }
            }
        }
    }

    int eidx = 0;
    for(int i = 1; i<=n; i++){
        if(s[i-1] == '1' && s[i] == '0'){
            eidx = i-1;
        }
        if(eidx != 0 && s[i-1] == '0' && s[i] == '1'){
            brg.push_back(i-eidx-1);
        }
    }

    sort(brg.begin(), brg.end());
    vector<int> psum(brg.size()+1, 0);

    for(int i = 1; i<(int)psum.size(); i++){
        psum[i] = psum[i-1]+brg[i-1];
    }

    // cout << remain;

    for(int q = 0; q<Q; q++){
        int cnt;
        cin >> cnt;

        if(cnt>black){
            if(black + remain < cnt) cout << "-1\n";
            else cout << cnt-black <<"\n";
        }
        else if(cnt<black){
            if(cnt == 0){
                cout << "-1\n";
            }
            else{
                cout << psum[black-cnt] <<"\n";
            }
        }
        else cout << "0\n";
    }
    
    
    return 0;
}