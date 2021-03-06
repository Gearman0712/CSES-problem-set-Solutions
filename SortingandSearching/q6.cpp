/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
bool comp(const pair<ll,ll>&a, const pair<ll,ll>&b){
	if(a.second==b.second)
		return a.first<b.first;
	return a.second<b.second;
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector< pair<ll,ll> >v(n);
		for(int i=0;i<n;i++){
			ll l,r;
			cin>>l>>r;
			v[i]=mp(l,r);
		}
		sort(all(v),comp);
		ll dp[n];
		dp[0]=1;
		set<ll>st;
		st.insert(v[0].second);
		map<ll,ll>mp;
		mp[v[0].second]=0;
		for(int i=1;i<n;i++){
			auto it = st.upper_bound(v[i].first);
			if(it==st.begin()){
				dp[i]=max(dp[i-1],1ll);
				mp[v[i].second]=i;
				st.insert(v[i].second);
			}
			else{
				it--;
				// cout<<"*"<<*it<<endl;
				dp[i]=max(dp[i-1],1+dp[mp[*it]]);
				st.insert(v[i].second);
				mp[v[i].second]=i;
			}
		}
		cout<<dp[n-1]<<endl;
	}
}