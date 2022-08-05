#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 256
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
long long getrand(long long a, long long b){
    return a + rng() % (b - a + 1);
}

string getbit(int x)
{
    string s;
    for(int i=7;i>=0;i--)
    {
        if(x&(1<<i))
            s+='1';
        else s+='0';
    }
    return s;
}
int toVal(string s)
{
    int ans=0;
    for(char u:s)
    {
        if(u=='1') ans*=2,ans++;
        else ans*=2;
    }
    return ans;
}

int cur;


int ask(string s)
{
//    int r=getrand(0,7);
//    rotate(s.begin(),s.begin()+r,s.end());
//    int v=toVal(s);
//    int n=__builtin_popcount(cur^v);
//    cur^=v;
//
//    //cout<<s<<' '<<n<<endl;
//
//    return n;

    cout<<s<<endl;
    int n;
    cin>>n;
    return n;
}



set<int>pos;


void solve(int cs)
{

    cur=128;
    //cur=getrand(1,255);
    map<int,int>vote;

    pos.clear();
    vector<int>v;
    for(int i=1;i<=255;i++)
    {
        v.push_back(i);
    }

    int q=0;
	string s;
    int n;
    while(true)
    {
        q++;
        //assert(q<=300);
        int which=1,mx=0;
        which=getrand(0,(int)v.size()-1);
        which=v[which];

        //dbg(which);
        s=getbit(which);
        n=ask(s);

        if(n==0)
            break;
        vote.clear();
        mx = 0;
	    for(int u:pos)
	    {
            for(int r=1;r<=8;r++)
            {
                rotate(s.begin(),s.begin()+1,s.end());
                int v=toVal(s);
                if(__builtin_popcount(u^v)==n)
                {
                    vote[u^v]++;
                    mx = max(mx, vote[u^v]);
                }
            }
	    }
        v.clear();
        for(auto a: vote){
            if(a.second == mx) v.push_back(a.first);
        }
        
    }
    //dbg(q);
}
main()
{
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        solve(cs);
    }
}
