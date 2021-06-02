/*
    Auther: ghoshashis545 Ashis Ghosh
    College: Jalpaiguri Govt Enggineering College
*/
#include <bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class type1>
// using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

#define ll int
#define int long long
#define ld long double
#define ff first
#define ss string 
#define se second
#define endl "\n"
#define ub upper_bound
#define lb lower_bound
#define clr(a,x) memset(a,x,sizeof(a))
#define alt(v) v.begin(),v.end()
#define ralt(v) v.rbegin(),v.rend()
#define pb emplace_back
#define mp make_pair
#define fab(i,a,b) for(int i=(a);i<(b);i++)
#define fba(i,a,b) for(int i=(b);i>=(a);i--)
// int mod=1000000007;
int mod=998244353;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

bool test  = 0;
const int inf = 1e18;
const int N = 1e5+5;


int tree[4*N],lazy[4*N];

int getsum(int nd,int st,int end,int li,int ri)
{
    if(lazy[nd])
    {
        tree[nd]+=(st-end+1)*lazy[nd];
        if(st!=end)
        {
            lazy[2*nd]+=lazy[nd];
            lazy[2*nd+1]+=lazy[nd];
        }
        lazy[nd]=0;
    }
    if(st>=li && end<=ri)
    return tree[nd];
    int m=st+(end-st)/2;
    if(ri<=m)
    return getsum(2*nd,st,m,li,ri);
    else if(li>m)
    return getsum(2*nd+1,m+1,end,li,ri);
    else
    {
        int x=getsum(2*nd,st,m,li,ri);
        int y=getsum(2*nd+1,m+1,end,li,ri);
        tree[nd] = x+y;
        return tree[nd];
    }
}


void update(int nd,int st,int end,int li,int ri,int val)
{
 
    if(lazy[nd])
    {
        tree[nd]+=(st-end+1)*lazy[nd];
        if(st!=end)
        {
            lazy[2*nd]+=lazy[nd];
            lazy[2*nd+1]+=lazy[nd];
        }
        lazy[nd]=0;
    }
    
    if(st>=li and end<=ri)
    {
        tree[nd]+=(end-st+1)*val;
        if(st!=end)
        {
            lazy[2*nd]+=val;
            lazy[2*nd+1]+=val;
        }
        lazy[nd]=0;
        return ;
    }
    int m=st+(end-st)/2;
    if(ri<=m)
        update(2*nd,st,m,li,ri,val);
    else if(li>m)
        update(2*nd+1,m+1,end,li,ri,val);
    else
    {
        update(2*nd,st,m,li,ri,val);
        update(2*nd+1,m+1,end,li,ri,val);
    }
    tree[nd] = tree[2*nd]+tree[2*nd+1];
}
 

void solve()
{

    int n,q;
    cin >> n >>q;
    clr(tree,0);
    clr(lazy,0);
    
    while(q--)
    {
        int t,l,r,x;
        cin >>t >>l;
        l++;
        if(t == 1)
        {
            cin >> r >> x;
            update(1,1,n,l,r,x);
        }
        else
            cout<<getsum(1,1,n,l,l)<<"\n";
    }

    

}
 
 
 
    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //precompute();
    int t=1;
    if(test)
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
} 
