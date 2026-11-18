#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int N;
    cin >> N;
    vector<tuple<ll, ll, ll>> q13;
    vector<tuple<ll, ll, ll>> q24;

    for(int i = 0; i<N; i++){
        ll x, y, v;
        cin >> x >> y >> v;

        if(x*y<=0) q24.push_back({x, y, v});
        if(x*y>=0) q13.push_back({x, y, v});
    }

    sort(q13.begin(), q13.end(), [](auto fs, auto sc){
        auto[fx,fy, fv] = fs;
        auto[sx,sy, sv] = sc;

        return (fx+fy)*sv < (sx+sy)*fv;
    });

    sort(q24.begin(), q24.end(), [](auto fs, auto sc){
        auto[fx,fy, fv] = fs;
        auto[sx,sy, sv] = sc;

        return (fx-fy)*sv < (sx-sy)*fv;
    });

    long double ans = 0;
    if(!q13.empty()){
        auto[x, y, v] = q13[0];

        for(int i = 1; i<q13.size(); i++){
            auto[nx, ny, nv] = q13[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
        for(int i = 0; i<q24.size(); i++){
            auto[nx, ny, nv] = q24[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
    }
    if(!q13.empty()){
        auto[x, y, v] = q13.back();

        for(int i = 0; i<q13.size(); i++){
            auto[nx, ny, nv] = q13[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
        for(int i = 0; i<q24.size(); i++){
            auto[nx, ny, nv] = q24[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
    }

    if(!q24.empty()){
        auto[x, y, v] = q24[0];

        for(int i = 1; i<q24.size(); i++){
            auto[nx, ny, nv] = q24[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
        for(int i = 0; i<q13.size(); i++){
            auto[nx, ny, nv] = q13[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
    }
    if(!q24.empty()){
        auto[x, y, v] = q24.back();

        for(int i = 0; i<q24.size(); i++){
            auto[nx, ny, nv] = q24[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
        for(int i = 0; i<q13.size(); i++){
            auto[nx, ny, nv] = q13[i];
            
            ans = max(ans, (abs(nx-x)+abs(ny-y))/(long double)(v+nv));
        }
    }

    cout.precision(7);
    cout << fixed;
    cout << ans <<"\n";
    
    return 0;
}