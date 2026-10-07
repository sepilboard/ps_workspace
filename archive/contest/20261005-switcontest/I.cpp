#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll L, R, K;

ll cnt(ll x)
{
    if(x <= 0){
        return 0;
    }

    ll temp_r = x;
    ll p = 0;
    while(temp_r>K){
        temp_r /= K;
        p++;
    }

    ll ret = pow(K, p);
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    return 0;
}