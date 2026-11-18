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

            int lval = qry(2*node, l, mid, ql, qr);
            int rval = qry(2*node+1, mid+1, r, ql, qr); 
            
            return lval + rval;
        }

    public:
        Seg(int n) : n(n)
        {
            tree.resize(4*n);
        }

        void upd(int idx) {upd(1, 0, n, idx);}
        int qry(int ql, int qr) {return qry(1, 0, n, ql, qr);}

};