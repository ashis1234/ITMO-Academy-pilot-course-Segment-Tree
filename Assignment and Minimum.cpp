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
int mod=1000000007;
// int mod=998244353;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

bool test  = 0;
int n;
const int N = 1e5+5;

int tree[4*N],lazy[4*N];
void push(int nd,int ss,int se){
	int x = lazy[nd];
	if(x != -1){
		tree[nd] = x;
		lazy[nd] = -1;
	}
	if(ss != se and x != -1)
		lazy[2*nd] = lazy[2*nd+1] = x;
}

void update(int nd,int ss,int se,int l,int r,int val)
{
	push(nd,ss,se);
	if(ss > r or se < l)
		return ;
	if(l <= ss and se <= r)
	{
		lazy[nd] = val;
		push(nd,ss,se); 
		return;
	}
	int mid = (ss+se)/2;
	update(2*nd,ss,mid,l,r,val);
	update(2*nd+1,mid+1,se,l,r,val);
	tree[nd] = min(tree[2*nd] , tree[2*nd+1]);
}

int query(int nd,int ss,int se,int l,int r)
{
	push(nd,ss,se);
	if(ss > r or se < l)
		return 1e9;
	if(l <= ss and se <= r){
		return tree[nd];
	}
	int mid = (ss+se)/2;
	return min(query(2*nd,ss,mid,l,r) , query(2*nd+1,mid+1,se,l,r));
}

void solve()
{
	int q;
	cin >> n >> q;
	clr(tree,0);
	clr(lazy,-1);
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
    int t1 = 1;
    if(test)
    cin>>t1;
    while(t1--)
    {
        solve();
    }
    return 0;
} 
