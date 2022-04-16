#include <bits/stdc++.h>
using namespace std;

void addEdge ( vector<pair<int,int>> graph[] , int to , int from , int wt )
{
	graph[to]  .push_back({from,wt});
	graph[from].push_back({to  ,wt});
}

void printgraph( vector<pair<int,int>> graph[] , int vertex )
{
	for ( int v = 0 ; v < vertex ; v ++ )
	{
		for ( auto i : graph[v] )
		{
			cout<< v << " " << i.first << " " << i . second <<endl ;
		}
	}
}

int main() {
	
	int vertex , edges  ;
	cin>> vertex >> edges ;

	// taking input of graph
	vector<pair<int,int>> graph[vertex] ;
	for ( int i = 0 ; i < edges ; i ++ )
	{
		int to , from , wt ;
		cin>>to>>from>>wt ;
		addEdge(graph , to , from , wt ) ;
	}
	// printing of graph 
	printgraph( graph , vertex ) ;

	return 0;
}