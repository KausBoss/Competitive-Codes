#include <bits/stdc++.h>

using namespace std;
#define ll long long int
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
const int nax = 1e3+5;
const int mod = 1e9+7;

string func(){
	int n;
	cin>>n;
	vector<int> a(n);
	F(a, n);
	vector<int> freq(nax, 0);
	freq[a[0]]=1;
	for(int i=1; i<n; i++){
		if(a[i] != a[i-1] && freq[a[i]] != 0){
			return "NO";
		}
		freq[a[i]]++;
	}
	map<int,int> diff;
	for(int i=1; i<nax; i++){
		if(freq[i]!=0){
			if(diff.count(freq[i])){
				return "NO";
			}
			diff[freq[i]]=1;
		}
	}
	return "YES";
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cout<<func()<<endl;
	}
}