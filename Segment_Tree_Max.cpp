#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 ;
int arr[N] , seg_tree[4*N] ;

int query ( int index , int low , int high , int l , int r )
{
    if ( low >= l && high <= r )
        return seg_tree[index] ;
    if ( high < l || low > r )
        return INT_MIN ;
    int mid = low + ( high-low) / 2 ;
    int left  = query( 2*index+1 , low ,    mid , l , r ) ;
    int right = query( 2*index+2 , mid+1 , high , l , r ) ;
    
    return max( left , right ) ;
}

void buildSegTree( int index , int low , int high )
{
    if ( low == high )
    {
        seg_tree[index] = arr[low] ;
        return ;
    }
    
    int mid = low + ( high-low) / 2 ;
    buildSegTree( 2*index+1 , low , mid ) ;
    buildSegTree( 2*index+2 , mid+1 , high ) ;
    
    seg_tree[index] = max( seg_tree[2*index+1] , seg_tree[2*index+2] ) ;
}

int main()
{
    // Filling Array
    int n ;
    cin>>n;
    
    for ( int i = 0 ; i < n ; i++ )
        cin>>arr[i] ;
        
    // Build Segment tree 
    buildSegTree( 0 , 0 , n-1 ) ;
    
    // Answer Queries
    int q ;
    cin>>q ;
    
    while(q--)
    {
        int l , r ;
        cin>>l>>r ;
        
        cout<<query( 0 , 0 , n-1 , l , r ) <<endl;
    }
    return 0 ;
}