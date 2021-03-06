/*
Dijkstra's Algorithm 
*/
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
const int nax = 1e4+5;
const int mod = 1e9+7;

template<typename T>
class graph{
	unordered_map<T, list<pair<T,ll>>> m;
public:
	void addEdge(T a, T b, ll cost){
		m[a].pb({b, cost});
		m[b].pb({a, cost});
	}
	void Dijkstra(T src){
		unordered_map<T, ll> dist;//maintains the min dist for each node

		for(auto x:m){ dist[x.fi]=INT_MAX;}// initializing with maxx

		set<pair<ll, T>> s;// to store min weighted node is ascending order
		s.insert({0, src});//inserting src with dist 0
		dist[src]=0;

		while(!s.empty()){
			auto p = *s.begin();//smallest weighed node
			s.erase(p);
			T node = p.si;
			ll nodeWeight = p.fi;

			//iterating over children of smallest weighed node and
			//relaxing them if possible
			for(auto child:m[node]){
				if(dist[child.fi] > nodeWeight + child.si){
					//checking if this node is already present in set
					auto ptr = s.find({dist[child.fi], child.fi});
					if(ptr != s.end()){
						s.erase(ptr);
					}
					dist[child.fi] = nodeWeight + child.si;
					//updating into set
					s.insert({dist[child.fi], child.fi});
				}
			}
		}
		for(auto node:m){
			cout<<"Distance from "<<src<<" to "<<node.fi<<" is "<<dist[node.fi]<<endl;
		}

	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll m;
	cin>>m;
	graph<char> g;
	for(int i=0; i<m; i++){
		char u, v;
		ll w;
		cin>>u>>v>>w;
		g.addEdge(u, v, w);
	}
	g.Dijkstra('A');
}