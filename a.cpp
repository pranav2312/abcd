//	@Author : Gaurang_Kothiya
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bitset>
#include <cstdint>
#include <initializer_list>
 
 
using namespace std;
using namespace __gnu_pbds;
 
#define data_set(type) tree<type,null_type,less<type>,rb_tree_tag,tree_order_statistics_node_update>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define ld long double
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fe(x,v)   for(auto &x :v)
#define nf(i,x,n) for(int i=n;i>=x;i--)
#define all(a)   a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define ook(num) order_of_key(num)
#define fbo(num) find_by_order(num)
#define gcd(a,b) __gcd(a,b)
#define bits(n) __builtin_popcountll(n)
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define RE rend()
#define RB rbegin()
#define B begin()
#define E end()
#define acc(v, x) accumulate(all(v), x)
#define p(a,b) pair<a,b>
#define F first
#define S second
#define sz size()
#define v(x) vector<x>
#define m(a,b) map<a,b>
#define u_m(a,b) unordered_map<a,b>
#define mm(a,b) multimap<a,b>
#define s(a) set<a>
#define us(a) unordered_set<a>
#define ms(a) multiset<a>
#define maxy __LONG_LONG_MAX__
#define miny INT_MIN
#define PI 3.14159265358979323846
 
const int inf= 1e9 ;
const int inf64= 1e18 ;
const int MOD= 1e9 +7;
const int MOD2= 998244353;


 
void Solve()
{
	int n,m;
	cin>>n>>m;

	int a[n],b[n],c[m];
	f(i,0,n-1) cin>>a[i];
	f(i,0,n-1) cin>>b[i];
	f(j,0,m-1) cin>>c[j];

	m(int,v(int)) need;
	m(int,bool) have;
	m(int,int) extra;
	m(int,int) comes;

	f(i,0,n-1){
		if(a[i]!=b[i]){
			need[b[i]].pub(i);
		}
		else{
			extra[a[i]]=i;
			have[b[i]]=true;
		}
	}

	f(j,0,m-1) comes[c[j]]++;

	fe(x,comes){
		int rt=x.F;
		if(x.S < need[rt].sz){
			cout<<"NO\n";
			return;
		}
	}

	int ans[m]={0};
	int flag=-1;

	nf(j,0,m-1){

		if(need[c[j]].sz ==0 ){
			if(flag != -1) ans[j]=flag;
			else{
				if(have[c[j]]==false){
					cout<<"NO\n";
					return;
				}
				else{
					ans[j]=extra[c[j]];
					flag=ans[j];
				}
			}
		}
		else{
			int ret= need[c[j]].back();
			(need[c[j]]).pob();
			ans[j]=ret;
			if(flag==-1) flag=ret;
		}
	}

	fe(x,need){
		v(int) vec=x.S;
		if(vec.sz >0){
			cout<<"NO\n";
			return;
		}
	}

	cout<<"YES\n";
	f(i,0,m-1) cout<<ans[i]+1<<" ";
	cout<<"\n";
}
 
 
 
signed main()
{
	speed
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int q=1;
	cin>>q;	
 
	while(q--)
	Solve();
 
	return 0;
}