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
const int N = 2e5+5;


int sum[4*N];
int a[N],b[N];
int func(int p1,int p2)
{
    return p1+p2;
}
// void build(int n,int st,int end)
// {
//     if(st==end)
//     {
//         sum[n] = a[st];
//         return;
//     }
//     int m=(st+end)/2;
//     build(2*n,st,m);
//     build(2*n+1,m+1,end);
//     sum[n] = func(sum[2*n],sum[2*n+1]);

// }
void update(int n,int st,int end ,int pos)
{
    if(st==end && st==pos)
    {
        sum[n] = 1;
        return;
    }
    int m = (st+end)/2;
    if(pos<=m)
        update(2*n,st,m,pos);
    if(pos>m)
        update(2*n+1,m+1,end,pos);
    sum[n] = func(sum[2*n],sum[2*n+1]);
    return;
}

int query(int n,int st,int end,int l,int r)
{  
    if(l<=st && end<=r)
        return sum[n];
    int m=(st+end)/2;
    if(r<=m)
        return query(2*n,st,m,l,r);
    else if(l>m)
        return query(2*n+1,m+1,end,l,r);
    else
    {
        int p1,p2;
        p1 = query(2*n,st,m,l,r);
        p2 = query(2*n+1,m+1,end,l,r);
        return func(p1,p2);
    }
}
 

void solve()
{

    int n,x,l,r;
    cin >> n;
    clr(sum,0);

    int a[n+1] = {0};
    vector<int> ans(n+1);
    for(int i = 1;i <= 2*n; ++i)
    {
        cin >> x;
        if(a[x] != 0){
            ans[x] = (i - a[x] - 2*query(1,1,2*n,a[x],i)-1);
            update(1,1,2*n,a[x]);
        }
        a[x] = i;
    }
    for(int i = 1; i <= n; ++i)
        cout<<ans[i]<<" ";

    

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
