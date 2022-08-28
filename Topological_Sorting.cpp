#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+1 ;
vector<int> graph[N] ;

// Function to make Directed Acyclic graph
void prepgraph( vector<vector<int>> edges )
{
    for ( auto i : edges )
    {
        graph[i[0]].push_back(i[1]) ;
    }
}

// Topological sorting 
void dfs( int source , stack<int> &ans , vector<bool> &visited )
{
    visited[source] = true ;
    for ( auto i : graph[source] )
    {
        if ( visited[i] == false )
            dfs( i , ans , visited ) ;
    }
    ans.push( source ) ;
}

int main()
{
    vector<vector<int>> edges = {{5,0} , {4,0} , {5,2} , {2,3} , {4,1} , {1,3}} ;
    prepgraph( edges ) ;
    
    stack<int> ans ;
    vector<bool> visited( 6 , false ) ;
    
    // Run dfs on each node 
    for ( int i = 0 ; i < 6 ; i ++ )
    {
        if ( visited[i] == false )
        {   
            dfs( i , ans , visited ) ;
        }
    }
    
    // Printing topological sorted elements 
    while(!ans.empty()) 
    {
        cout<<ans.top() <<" " ;
        ans.pop() ;
    }
    
    return 0 ;     
}