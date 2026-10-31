#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

vector<int> itor;
vector<int> itoc;

int rtoi(int r){ return (lower_bound(itor.begin(), itor.end(), r) - itor.begin());}
int ctoi(int c){ return (lower_bound(itoc.begin(), itoc.end(), c) - itoc.begin());}

class Seg
{
    private:
        int n;
        vector<int> tree;

        void upd(int node, int l, int r, int idx)
        {
            if(idx<l || r<idx) return;
            if(l == r){
                tree[node]++;
                return;
            }

            int mid = l+r>>1;
            upd(2*node, l, mid, idx);
            upd(2*node+1, mid+1, r, idx);

            tree[node] = tree[2*node]+tree[2*node+1];
        }

        int qry(int node, int l, int r, int ql, int qr)
        {
            if(r<ql || qr<l) return 0;
            if(ql<= l && r <=qr) return tree[node];
            int mid = l+r>>1;
            
            return qry(2*node, l, mid, ql, qr) + qry(2*node+1, mid+1, r, ql, qr);
        }

    public:
        Seg(int _n)
        {
            this->n = _n;
            tree.resize(4*n);
        }

        void upd(int idx) {upd(1, 0, n, idx);}
        int qry(int ql, int qr) {return qry(1, 0, n, ql, qr);}

};

int main()
{
    FASTIO;
    
    int H, W, N, Q;
    cin >> H >> W >> N >> Q;

    vector<pair<int, int>> rc(N);
    for(int i = 0; i<N; i++){
        int r, c;
        cin >> r >> c;
        rc[i] = {r, c};

        itor.push_back(r);
        itoc.push_back(c);
    }

    vector<array<int,3>> qry(Q);
    for(int i = 0; i<Q; i++){
        cin >> qry[i][0] >> qry[i][1] >> qry[i][2]; 

        if(qry[i][0] == 1){
            itor.push_back(qry[i][1]);
            itor.push_back(qry[i][2]);
        }
        else{
            itoc.push_back(qry[i][1]);
            itoc.push_back(qry[i][2]);
        }
    }

    sort(itor.begin(), itor.end());
    sort(itoc.begin(), itoc.end());

    Seg rseg(N+2*Q);
    Seg cseg(N+2*Q);
    for(int i = 0; i<N; i++){
        auto[r, c] = rc[i];

        rseg.upd(rtoi(r));
        cseg.upd(ctoi(c));
    }

    
    for(int i = 0; i<Q; i++){
        auto[cmd, l, r] = qry[i];
        
        if(cmd == 1){
            cout << rseg.qry(rtoi(l), rtoi(r)) <<"\n";
        }
        else{
            cout << cseg.qry(ctoi(l), ctoi(r)) << "\n";
        }
    }

    return 0;
}