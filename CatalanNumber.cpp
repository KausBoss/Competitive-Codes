#include <bits/stdc++.h>

using namespace std;
#define ll long long 			
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e6+5;
const int mod = 1e9+7;

ll dp[nax];

ll catalan(ll n){
	//base case
	if(n == 0 || n== 1){
		return 1;
	}
	//recursive case
	if(dp[n]!=-1){ return dp[n];}
	ll ans=0;
	for(ll i=1; i<=n; i++){
		ans += catalan(i-1)*catalan(n-i);
	}
	return dp[n] = ans;
}
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	for(ll i=0; i<n; i++){
		cout<<catalan(i)<<endl;
	}	
}