struct Dsu{
    vector<ll>par, siz;
    void Init(ll n){
        par.resize(n+5);
        siz.resize(n+5,1);
        for(int i =0; i<= n; i++) par[i] = i;
    }
    ll Find(ll n){
        if(par[n] == n) return n;
        else return par[n] = Find(par[n]);
    }
    bool Check(ll a, ll b){
        a = Find(a); b = Find(b);
        if(a == b) return false;
        return true;
    }
    bool Union(ll a, ll b){
        a = Find(a); b = Find(b);
        if(a == b) return false;
        if(siz[a] > siz[b]) swap(a,b);
        par[a] = b;
        siz[b] += siz[a];
        return true;
    }
};
