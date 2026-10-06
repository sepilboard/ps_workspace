#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    vector<char> is_p(n, true);
    vector<int> nxt_p(n, 0);
    is_p[1] = false;
    for(int i = 2; i<n; i++){
        if(!is_p[i]) continue;
        for(int j = i+i; j<n; j++){
            is_p[j] = false;
            nxt_p[j] = i;
        }
    }

    int x = 100;
    vector<pair<int, int>> vec;
    while(nxt_p[x] != 0){
        while()
    }

    return 0;
}