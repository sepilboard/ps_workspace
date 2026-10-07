#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void encrypt()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<char>> g(n, vector<char>(5));
    for(int i = 0; i<n; i++){
        int cur = s[i] - 'A';
        for(int sft = 0; sft<5; sft++){
            if(cur & (1<<sft)) g[i][sft] = '#';
            else g[i][sft] = '.';
        }
    }
    
    cout << n << " " << 5 <<"\n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<5; j++){
            cout << g[i][j];
        }
        cout << "\n";
    }
}

void decrypt()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> g[i][j];
        }
    }

    vector<char> ans(n);
    for(int i = 0; i<n; i++){
        int num = 0;
        for(int j = 0; j<m; j++){
            if(g[i][j] == '.') continue;
            num |= (1<<j);
        }
        ans[i] = 'A'+num;
    }

    cout << n << "\n";
    for(char c: ans) cout << c;
    cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string cmd;
    cin >> cmd;
    if(cmd == "encrypt") encrypt();
    else decrypt();

    return 0;
}