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


int sum[4*N],pref[4*N],suff[4*N],mxsum[4*N];
int a[N];

void build(int n,int st,int end)
{
    if(st==end)
    {
        sum[n] = a[st];
        pref[n] = a[st];
        suff[n] = a[st];
        mxsum[n] = a[st];
        return;
    }
    int m=(st+end)/2;
    build(2*n,st,m);
    build(2*n+1,m+1,end);
    sum[n] = sum[2*n] + sum[2*n+1];
    pref[n] = max({pref[2*n],sum[2*n]+pref[2*n+1]});
    suff[n] = max({suff[2*n]+sum[2*n+1],suff[2*n+1]});
    mxsum[n] = max({mxsum[2*n],mxsum[2*n+1],suff[2*n]+pref[2*n+1]});
}
void update(int n,int st,int end ,int pos,int val)
{
    if(st==end && st==pos)
    {
        sum[n] = val;
        pref[n] = val;
        suff[n] = val;
        mxsum[n] = val;
        return;
    }
    int m=(st+end)/2;
    if(pos<=m)
        update(2*n,st,m,pos,val);
    if(pos>m)
        update(2*n+1,m+1,end,pos,val);
    sum[n] = sum[2*n] + sum[2*n+1];
    pref[n] = max({pref[2*n],sum[2*n]+pref[2*n+1]});
    suff[n] = max({suff[2*n]+sum[2*n+1],suff[2*n+1]});
    mxsum[n] = max({mxsum[2*n],mxsum[2*n+1],suff[2*n]+pref[2*n+1]});
    return;
}
// int query(int n,int st,int end,int l,int r)
// {  
//     if(l<=st && end<=r)
//     return tree[n];
//     int m=(st+end)/2;
//     if(r<=m)
//     return query(2*n,st,m,l,r);
//     else if(l>m)
//     return query(2*n+1,m+1,end,l,r);
//     else
//     {
//         int p1,p2;
//         p1=query(2*n,st,m,l,r);
//         p2=query(2*n+1,m+1,end,l,r);
//         return func(p1,p2);
//     }
// }


void solve()
{

    int n,q;
    cin >> n >>q;
    for(int i = 1; i <= n; ++i){
        cin >>a[i];
    }

    build(1,1,n);
    cout<<max(0LL,mxsum[1])<<"\n";

    while(q--)
    {
        int i,v;
        cin >> i >> v;
        update(1,1,n,i+1,v);
        cout<<max(mxsum[1],0LL)<<"\n";
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
