#include <bits/stdc++.h>

using namespace std;

int main() {
	//m=no of nodes and n = no of edges 
	int m , n , source ;
	cin>>n>>m;

	vector<pair<int,int>> g[n+1] ; // graph

	// input of graph
	for ( int i = 0 ; i < m ; i ++ )
	{
		int a,b,wt;
		// first = node ; second = distance
		cin>>a>>b>>wt;
		g[a].push_back({b,wt});
		g[b].push_back({a,wt});
	}

	source = 1; // source is first node

	// priority queue act as min heap
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
	//priority_queue<pair<int,int>> pq; // also work
	//arry to store distances from source
	vector<int> distTo(n+1,INT_MAX);

	distTo[source]=0;

	// priority queue contain {distance , node}
	pq.push({ 0,source }); //source inserted

	while(!pq.empty())
	{
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int,int>> :: iterator it;

		for( it = g[prev].begin(); it != g[prev].end() ; it++ )
		//for(auto it : g[prev]){
		{
			int next = it->first;
			int nextDist = it->second;

			if ( distTo[prev] + nextDist < distTo[next] )
			{
				distTo[next] = nextDist + distTo[prev] ;
				pq.push({distTo[next],next});
			}
		}
	}

	// printing all distances
	for ( int i = 1 ; i < distTo.size() ; i ++ )
		cout<<i<<" "<<distTo[i]<<endl;

	return 0;
}