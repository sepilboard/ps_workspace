#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


int N, Q;

signed main()
{
    FASTIO;
    
    cin >> N >> Q;
    
    vector<int> a(N);
    vector<int> b(N);
    vector<int> pos(N);

    for(int i = 0; i<N; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i<N; i++){
        cin >> b[i];
        b[i]--;
    }
    for(int i = 0; i<N; i++){
        pos[a[i]] = i;
    }
    
    for(int i = 0; i<N; i++){
        cout << pos[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i<N; i++){
        cout << pos[b[i]] << " ";
    }
    cout << "\n";

    int inv_cnt = 0;
    for(int i = 0; i<N; i++){
        if(b[i] == 0) continue;
        if(pos[b[i]-1]>pos[b[i]]){
            inv_cnt++;
        }
        cout << b[i] <<": " << pos[b[i]] <<"\n";
    }
    
    cout << "ok\n"; return 0;
    
    cout << 1LL*inv_cnt*N - (N-1) - pos[b[N-1]] << "\n";
    cout << 1LL*inv_cnt <<"\n";

    for(int q = 0; q<Q; q++){
        int c, x, y;
        cin >> c >> x >> y;
        x--;
        y--;

        
        int prv = (x != 0 && pos[x-1]>pos[x]) + (y != 0 && pos[y-1]>pos[y]);
        swap(pos[x], pos[y]);
        int cur = (x != 0 && pos[x-1]>pos[x]) + (y != 0 && pos[y-1]>pos[y]);
        inv_cnt += cur-prv;
        
        cout << 1LL*inv_cnt*N - (N-1) - pos[b[N-1]] << "\n";
        cout << 1LL*inv_cnt*N <<"\n";
        cout << "ok\n"; return 0;
    }


    return 0;
}