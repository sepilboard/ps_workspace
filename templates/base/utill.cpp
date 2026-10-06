#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


struct Compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};


signed main()
{
    FASTIO;
    cout << fixed << setprecision(10);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    return 0;
}