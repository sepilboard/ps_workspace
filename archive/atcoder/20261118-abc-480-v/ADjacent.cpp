#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

char g[2][2];

int main()
{
    FASTIO;
    
    int pos[2];
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A'){
                pos[0] = i;
                pos[1] = j;
            }
        }
    }

    if(g[(pos[0]+1)%2][pos[1]] == 'D' || g[pos[0]][(pos[1]+1)%2] == 'D'){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}