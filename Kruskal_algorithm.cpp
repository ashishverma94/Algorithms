#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
int parent[N] , sz[N] ;

void Make ( int v )
{
	parent[v] = v;
	sz[v] = 1 ;
}

int Find ( int v )
{
	if ( parent[v] == v )
		return parent[v] ;
	return parent[v] = Find(parent[v]) ;
}

void Union ( int a , int b )
{
	a = Find(a) ;
	b = Find(b) ;
	if ( a != b )
	{
		if( sz[a] < sz[b] )
			swap( a , b ) ;
		parent[b] = a;
		sz[a] += sz[b] ;
	}
}

// 	printing of graph 
void printGraph( vector<pair<int,pair<int,int>>> edges , int E )
{
	for ( auto i : edges )
	{
		cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl ;
	}
}

int main() {
	
	int V , E ;
	cin>> V >> E ;
	
	// vector for edges 
	// vector<pair< weight ,pair<to,from>>> edges ;
	// weight is first in pair because we have to sort 
	// edges by weight 
	vector<pair<int , pair<int,int>>> edges ;
	for ( int i = 0 ; i < E ; i ++ )
	{
		// taking input of all edges 
		int u , v , w ;
		cin>> u >> v >> w ;
		edges.push_back({ w , { u , v }}) ;

	}

	// printGraph(edges , E ) ;

	// sorting of all edges 
	sort( edges.begin() , edges.end()) ;

	for ( int i = 0 ; i < V ; i ++ )
		Make(i) ;

	int total_cost = 0 ;

	// applying kruskal for MST 
	for ( auto &edge : edges )
	{
		int wt = edge.first ;
		int u =  edge.second.first ;
		int v =  edge.second.second ;
		if ( Find(u) == Find(v) )
			continue ;
		total_cost += wt ;
		Union ( u , v ) ;
		
		// for printing edges of spanning tree 
		// cout<< u << " " << v ;
	}

	cout << total_cost ;

	return 0;
}