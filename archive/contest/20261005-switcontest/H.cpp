#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int pw = 1;
    for(int i = 0; i<n; i++) pw *= 2;
    
    if(pw<k) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}