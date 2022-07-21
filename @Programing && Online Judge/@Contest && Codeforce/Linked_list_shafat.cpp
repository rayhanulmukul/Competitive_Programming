#include <bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int(x.size()))
#define sor(x)  sort(x.begin(), x.end())

#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
#define R0F(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) R0F(i,0,a)
#define each(a,x) for (auto& a: x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)

struct node
{
    int roll;
    node *next;
};
node *root = NULL;
void append(int roll){
    if(root == NULL){
        root = new node();
        root-> roll = roll;
        root-> next = NULL;
    }
    else{
        node *current_node = root;
        while(current_node->next != NULL){
            current_node = current_node-> next;
        }
        node *newnode = new node();
        newnode-> roll = roll;
        newnode-> next = NULL;

        current_node-> next = newnode;
    }
}
void print(){
    node *current_node = root;
    while (current_node!=NULL){
        cout << current_node->next;
    }
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    append(1);
    append(2);
    append(6);
    print()
    return 0;
}