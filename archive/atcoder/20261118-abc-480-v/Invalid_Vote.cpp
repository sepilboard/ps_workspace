#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    int N, M;
    cin >> N >> M;

    vector<string> c(N);
    vector<string> v(M);
    
    for(int i = 0; i<N; i++){
        cin >> c[i];
    }
    for(int j = 0; j<M; j++){
        cin >> v[j];
    }

    vector<int> chk(M, 0);

    for(int j = 0; j<M; j++){
        int exactly = 0;
        int cnt = 0;
        for(int i = 0; i<N; i++){
            if(c[i].length() != v[j].length()) continue;

            int dcnt = 0;
            for(int k = 0; k<c[i].length(); k++){
                if(c[i][k] != v[j][k]) dcnt++;
            }

            if(dcnt == 0){
                exactly++;
            }
            else if(dcnt == 1){
                cnt++;
            }
        }

        if(exactly>0){
            chk[j] = 2;
        }
        else if(cnt == 1){
            chk[j] = 1;
        }
    }


    for(int i = 0; i<N; i++){
        int ans = 0;
        for(int j = 0; j<M; j++){
            if(c[i].length() != v[j].length()) continue;
            if(!chk[j]) continue;
            
            if(chk[j] == 2){
                bool flag = true;
                for(int k = 0; k<c[i].length(); k++){
                    if(c[i][k] != v[j][k]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans++;
                }
            }
            else if(chk[j] == 1){
                int cnt = 0;
                for(int k = 0; k<c[i].length(); k++){
                    if(c[i][k] != v[j][k]) cnt++;
                }
    
                if(cnt<2){
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}