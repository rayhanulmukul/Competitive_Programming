#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long z=0, o=0, p01=0, p10=0;
    bool lazy=false;
};

struct SegTree {
    int n;
    vector<Node> st;
    SegTree(const string& s) { n = s.size(); st.resize(4*n); build(1,0,n-1,s); }

    static Node merge(const Node& L, const Node& R) {
        Node res;
        res.z = L.z + R.z;
        res.o = L.o + R.o;
        res.p01 = L.p01 + R.p01 + L.z * R.o;
        res.p10 = L.p10 + R.p10 + L.o * R.z;
        return res;
    }

    void apply(int p){
        swap(st[p].z, st[p].o);
        swap(st[p].p01, st[p].p10);
        st[p].lazy ^= 1;
    }

    void push(int p){
        if(!st[p].lazy) return;
        apply(p<<1);
        apply(p<<1|1);
        st[p].lazy = false;
    }

    void build(int p,int l,int r,const string& s){
        if(l==r){
            if(s[l]=='0'){ st[p].z=1; st[p].o=0; }
            else          { st[p].z=0; st[p].o=1; }
            st[p].p01 = st[p].p10 = 0;
            return;
        }
        int m=(l+r)>>1;
        build(p<<1,l,m,s);
        build(p<<1|1,m+1,r,s);
        st[p]=merge(st[p<<1],st[p<<1|1]);
    }

    void update(int p,int l,int r,int ql,int qr){
        if(qr<l || r<ql) return;
        if(ql<=l && r<=qr){ apply(p); return; }
        push(p);
        int m=(l+r)>>1;
        update(p<<1,l,m,ql,qr);
        update(p<<1|1,m+1,r,ql,qr);
        st[p]=merge(st[p<<1],st[p<<1|1]);
    }

    // 1-indexed inclusive range
    void toggle(int L,int R){ update(1,0,n-1,L-1,R-1); }

    long long answer() const { return st[1].p01; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    string s; cin>>s;
    int q; cin>>q;
    SegTree seg(s);
    while(q--){
        int l,r; cin>>l>>r;
        seg.toggle(l,r);
        cout<<seg.answer()<<"\n";
    }
    return 0;
}
