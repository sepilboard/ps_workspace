#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

char a[10][10];

int main()
{
    FASTIO;

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin >> a[i][j];
        }
    }

    int ans = 100;
    for(int i = 0; i<5; i++){
        int cnt = 0;
        for(int j = 0; j<5; j++){
            if(a[i][j] == '.') cnt++;
        }

        ans = min(ans, cnt);
    }
    
    for(int i = 0; i<5; i++){
        int cnt = 0;
        for(int j = 0; j<5; j++){
            if(a[j][i] == '.') cnt++;
        }

        ans = min(ans, cnt);
    }

{
    int cnt = 0;
    for(int i = 0; i<5; i++){
        if(a[i][i] == '.') cnt++;
    }
    ans = min(ans, cnt);
}
{
    int cnt = 0;
    for(int i = 0; i<5; i++){
        if(a[4-i][i] == '.') cnt++;
    }
    ans = min(ans, cnt);
}

    cout << ans << "\n";
    return 0;
}