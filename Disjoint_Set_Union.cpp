#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;

int parent[N] , sz[N] ;

/* Disjoint Set Union-
	has three function-
	1) Make() -> add a node 
	2) Find() -> tell the parent 
	3) Union() -> make union of elements 
*/
void Make( int v )
{
	parent[v] = v ;
	sz[v] = 1 ;
}

int Find( int v )
{
	if ( parent[v] == v )
		return v ;
	return parent[v] = Find( parent[v]) ;
}

void Union( int a , int b )
{
	a = Find(a);
	b = Find(b);

	if ( a != b )
	{
		if ( sz[a] < sz[b] )
			swap(a,b) ;
		parent [b] = a ;
	}
}

int main() {
	// Your code goes here;

	// n = vertex ; k = edges ;
	int n , k ;
	cin >> n >> k ;

	for ( int i = 0 ; i < n ; i ++ )
	{
		Make(i) ;
	}

	// joining all edges 
	while( k-- )
	{
		int u , v ;
		cin >> u >> v ;
		Union(u , v ) ;
	}

	int connected_components = 0 ;

	for ( int i = 0 ; i < n ; i ++ )
	{
		if ( Find(i) == i )
			connected_components ++ ;
	}

	cout<< connected_components ;

	return 0;
}

/* Time Complexity = O(alpha(N))
almost constant */