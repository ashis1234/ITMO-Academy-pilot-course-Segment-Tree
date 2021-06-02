#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
#define ld long double
#define ff first
#define ss string 
#define se second
#define psi pair<ss,int>
#define psl pair<ss,ll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpsi vector<psi>
#define vpsl vector<psl>
#define vpll vector<pll>
#define vpii vector<pii>
#define alt(v) v.begin(),v.end()
#define pb emplace_back
#define mp make_pair
#define tc(t) cin>>t;while(t--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fab(i,a,b) for(ll i=(a);i<(b);i++)
#define fba(i,a,b) for(ll i=(b);i>=(a);i--)
#define arr(i,n) fab(i,0,n)
ll const N=100005;
ll tree[4*N];
ll a[N];
ll func(ll p1,ll p2)
{
    return min(p1,p2);
}
void build(ll n,ll st,ll end)
{
    if(st==end)
    {
        tree[n]=a[st-1];
        return;
    }
    ll m=(st+end)/2;
    build(2*n,st,m);
    build(2*n+1,m+1,end);
    tree[n]=func(tree[2*n],tree[2*n+1]);
}
void update(ll n,ll st,ll end ,ll pos,ll val)
{
    if(st==end && st==pos)
    {
        tree[n]=val;
        //cout<<n<<" "<<tree[n]<<endl;
        a[pos-1]=val;
        return;
    }
    ll m=(st+end)/2;
    if(pos<=m)
    update(2*n,st,m,pos,val);
    if(pos>m)
    update(2*n+1,m+1,end,pos,val);
    tree[n]=func(tree[2*n],tree[2*n+1]);
    return;
}
ll query(ll n,ll st,ll end,ll l,ll r)
{  
    if(l<=st && end<=r)
    return tree[n];
    ll m=(st+end)/2;
    if(r<=m)
    return query(2*n,st,m,l,r);
    else if(l>m)
    return query(2*n+1,m+1,end,l,r);
    else
    {
        ll p1,p2;
        p1=query(2*n,st,m,l,r);
        p2=query(2*n+1,m+1,end,l,r);
        return func(p1,p2);
    }
}
 


int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll i,n,m,x,y;
        int c;
        cin>>n>>m;
        fab(i,0,n)
        cin>>a[i];
        build(1,1,n);
        fab(i,0,m)
        {
            cin>>c>>x>>y;
            if(c==2)
            {
                cout<<query(1,1,n,x+1,y)<<endl;
            }
            else
                update(1,1,n,x+1,y);
        }
    }
    return 0;
    
}























