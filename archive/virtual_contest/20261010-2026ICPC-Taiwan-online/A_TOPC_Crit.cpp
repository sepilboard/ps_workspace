#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

ll a, b, c;

signed main()
{
    FASTIO;
    cin >> a >> b >> c;
    if(b-a == c-b){
        cout << "secret " << b-a <<"\n";
    }
    else{
        cout << "not secret\n";
    }
    
    return 0;
}