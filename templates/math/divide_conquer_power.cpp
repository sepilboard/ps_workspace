typedef long long ll;
# define MOD 1'000'000'007

ll pw(ll x, ll y)
{
    if(x < 0) x += MOD;
    if(y == 0) return 1;
    ll ret = pw(x, y/2);
    if(y&1) return ret*ret%MOD*x%MOD;
    else return ret*ret%MOD;
}

ll pw(ll x, ll y)
{
    ll res = 1LL;
    while(y){
        if(y&1) res = res*x%MOD;
        x = x*x%MOD;
        y>>=1;
    }
    return res;
}