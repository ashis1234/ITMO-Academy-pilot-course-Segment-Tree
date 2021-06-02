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
const int inf = 1e14;
const int N = 1e5+5;

int timer = 1;
int sum[4*N];
int mx[4*N];

void build(int st,int end,int n)
{
    if(st == end){
        sum[n] = 0;
        mx[n] = inf;
        return;
    }
    int m = (st+end)/2;
    build(st,m,2*n);
    build(m+1,end,2*n+1);
}

void update(int n,int st,int end ,int l,int r,int val)
{
    
    if(st > r or end < l)
        return;
    if(l <= st and end <= r)
    {
        sum[n] += val;
        mx[n] = sum[n];
        if(st != end)
            mx[n] += min(mx[2*n],mx[2*n+1]);
        return;
    }
    int mid = (st + end)/2;
    update(2*n,st,mid,l,r,val);
    update(2*n+1,mid+1,end,l,r,val);
    mx[n] = min(mx[2*n],mx[2*n+1]) + sum[n];
}
 
int query(int n,int st,int end,int l,int r)
{  
    if(st > r or end < l)
        return inf;
    if(l <= st and end <= r)
        return mx[n];
    
    int mid = (st + end)/2;
    return min(query(2*n,st,mid,l,r),query(2*n+1,mid+1,end,l,r)) + sum[n];
}
 
 

void solve()
{

    int n,q;
    cin >> n >>q;

    while(q--)
    {
        int t,l,r,x;
        cin >>t >>l >> r;
        l++;
        if(t == 1)
        {
            cin >> x;
            update(1,1,n,l,r,x);
        }
        else
            cout<<query(1,1,n,l,r)<<"\n";        
        
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
