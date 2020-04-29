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
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		vector<ll>pre(n),post(n);
		sort(all(v));
		pre[0]=0;
		for(int i=1;i<n;i++){
			if(v[i]==v[i-1]){
				pre[i]=pre[i-1];
			}
			else{
				pre[i]=pre[i-1]+(v[i]-v[i-1])*i;
			}
			// cout<<i<<" "<<pre[i]<<endl;
		}
		post[n-1]=0;
		ll ans=LLONG_MAX;
		for(int i=n-2;i>=0;i--){
			if(v[i]==v[i+1]){post[i]=post[i+1];}
			else{
				post[i]=post[i+1]+(v[i+1]-v[i])*(n-1-i);
			}
			ans=min(ans,pre[i]+post[i]);
		}
		cout<<ans<<endl;
	}
}