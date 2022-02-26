#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs ( int s , vector<int> g[] , int *vis )
{
	vis[s]= 1;
	cout<<s<<" ";
	for ( int i = 0 ; i < g[s].size() ; i ++ )
	{
		if( vis[g[s][i]] == 0 )
			dfs( g[s][i],g,vis );
	}
 }

int main() {
	// no of vertices and edges
	int e,v;
	cin>>e>>v;

	// input of graph
	vector<int> adj[v+1];
	for ( int i = 0 ; i < e ; i ++ )
	{
		int u , v ;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	// call dfs 
	for ( int i = 1 ; i < v+1 ; i ++ )
	{
		int vis [v+1]; // visited list 
		memset(vis,0,sizeof(vis));
		dfs ( i , adj , vis );
		cout<<endl;
	}

	// for (int v = 1; v <= n; ++v) {
    //     for (auto x : adj[v])
    //         cout << " " << x;
    //     printf("\n");
    // }
		
	return 0;
}