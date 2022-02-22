// Disjoint set Data Structure
#include <bits/stdc++.h>

using namespace std;
vector<int> dsuf;
// It is used to check weather two element '
// belong to same set or not 

// find operaton to find parent 
int find(int v)
{
	if ( dsuf[v]==-1)
		return v;
	return find(dsuf[v]);
}

// Union operation to unite to nodes 
void unionOperation(int fromP, int toP )
{
	fromP=find(fromP);
	toP = find(toP);
	dsuf[fromP] = toP;
}

// function to check cycle in graph
bool isCyclic(vector<pair<int,int>> & edgeList )
{
	for ( auto p :edgeList )
	{
		int fromP = find(p.first );
		int toP   = find(p.second );

		if ( fromP == toP )
			return true;
 		unionOperation(fromP,toP);
	}
	return false;
}

int main() {

	int E,V; // no of edges and vertces
	cin>>E>>V;

	dsuf.resize(V+1,-1);
	vector<pair<int,int>> edgeList;

	for(int i = 1 ; i <= E ; i ++ )
	{
		int from , to ;
		cin>>from>>to;

		edgeList.push_back({from,to});
	}

	if ( isCyclic(edgeList))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	for ( auto i : dsuf )
	cout<<i<<" ";
	return 0;
}