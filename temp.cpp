#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dp[100][100][100][100][3];

int main()
{
    FASTIO;
    int N, Y, P, B;

    cin >> N >> Y >> P >> B;

    dp[0][0][0][0][0] = 1;
    for(int i = 1; i<=N; i++){
        for(int y = 0; y<=Y; y++){
            for(int p = 0; p<=P; p++){
                for(int b = 0; b<=B; b++){
                    if(y + p + b != i) continue;
                    
                    // 마지막 공이 검은색
                    if(b){
                        dp[i][y][p][b][0] += dp[i-1][y][p][b-1][0];
                        dp[i][y][p][b][0] += dp[i-1][y][p][b-1][1];
                        dp[i][y][p][b][0] += dp[i-1][y][p][b-1][2];
                    }

                    // 마지막 공이 노란색
                    if(y){
                        dp[i][y][p][b][1] += dp[i-1][y-1][p][b][0];
                        dp[i][y][p][b][1] += dp[i-1][y-1][p][b][1];
                    }

                    // 마지막 공이 보라색
                    if(p){
                        dp[i][y][p][b][2] += dp[i-1][y][p-1][b][0];
                        dp[i][y][p][b][2] += dp[i-1][y][p-1][b][2];
                    }
                }
            }
        }
    }


    int ans = 0;
    for(int c = 0; c<3; c++){
        ans += dp[N][Y][P][B][c];
    }
    cout << ans << "\n";
    
    return 0;
}