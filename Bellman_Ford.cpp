#include<bits/stdc++.h>
using namespace std;
int inf = 100000000 ;
vector<int> dist ( 100 , inf ) ;  
bool cycle = false ;

class Solution{
	public:
    void bellman_ford(int V, vector<vector<int>> &adj ) {
        // source is at zero distance
        dist[0] = 0 ;
        for ( int i = 1 ; i <= V-1 ; i ++ )
        {
            for ( auto it : adj )
            {
                if (  dist[it[0]]+it[2] < dist[it[1]] )
                    dist[it[1]] = dist[it[0]]+it[2] ;  
            }
        }
        
        // for negative cycle
        for ( auto it : adj )
        {
            if ( dist[it[0]]+it[2] < dist[it[1]] )
                cycle = true ;
        }
    }
};

int main()
{
    // Adjcency List
    vector<vector<int>> adj ;
    
    int V , E ; // Vertex and Edges
    cin>>V>>E ;
    
    // Taking input of all edges
    for ( int i = 0 ; i < E ; i ++ )
    {
        int u , v , w ;//  from , to , weight ;
        cin>>u>>v>>w ;
        adj.push_back({u,v,w}) ;
    }
    Solution so ;
    so.bellman_ford( V, adj ) ;
    
    // Print minimum distance from source node
    for ( int i = 0 ; i < V ; i++ )
        cout<<i<<":"<<dist[i] <<endl;
        cout<<endl;
    // for negative cycle 
    if ( cycle )
        cout<<"Negative" ;
    else
        cout<<"No Negative Cycle" ;
    
    return 0 ;

}