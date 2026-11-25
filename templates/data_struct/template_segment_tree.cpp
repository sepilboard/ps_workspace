template<typename _typ, typename OpType, _typ e> class Seg{
private:
    _typ n;
    vector<_typ> tree;
    OpType Op;
    
    void update_val(int node, int l, int r, int idx, _typ val){
        if(r < idx || idx < l) return;
        if(l == r){
            tree[node] = val;
            return;
        }
        
        int mid = (l + r)/2;
        update_val(node*2, l, mid, idx, val);
        update_val(node*2+1, mid+1, r, idx, val);
        tree[node] = Op(tree[node*2], tree[node*2+1]);
    }

    void update_diff(int node, int l, int r, int idx, _typ diff){
        if(r < idx || idx < l) return;
        if(l == r){
            tree[node] += diff;
            return;
        }

        int mid = (l + r)/2;
        update_diff(node*2, l, mid, idx, diff);
        update_diff(node*2+1, mid+1, r, idx, diff);
        tree[node] = Op(tree[node*2], tree[node*2+1]);
    }

    _typ range_query(int node, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr) return tree[node];
        if(qr < l || r < ql) return e;

        int mid = (l + r)/2;
        _typ l_val = range_query(node*2, l, mid, ql, qr);
        _typ r_val = range_query(node*2+1, mid+1, r, ql, qr);
        return Op(l_val,r_val);
    }

public:
    Seg(int n) : n(n){
        tree.resize(4*n);
        for(int i = 0; i<tree.size(); i++) tree[i] = e;
    }

    void upd_val(int idx, _typ val){
        update_val(1, 1, n, idx, val);
    }

    void upd_diff(int idx, _typ diff){
        update_diff(1, 1, n, idx, diff);
    }

    _typ qry(int ql, int qr){
        return range_query(1, 1, n, ql, qr);
    }
};

struct Operator {
    int operator()(int a, int b) const{
        return a + b;
    }
};





