#include<bits/stdc++.h>
using namespace std ;

int partition ( vector<int> &arr , int start , int end ) 
{
    int pivot = arr[end] , space = start-1 ;
    
    for ( int j = start ; j < end ; j ++ )
    {
        if ( arr[j] < pivot )
        {
            space++;
            swap( arr[j] , arr[space] ) ;
        }
    }
    space++;
    swap( arr[end] , arr[space] ) ;
    return space ;
}
void QuickSort( vector<int> &arr , int start , int end )
{
    if ( start >= end )
        return ;
    
    int pi_idx = partition( arr , start , end ) ;
    QuickSort( arr , start , pi_idx-1 ) ;
    QuickSort( arr , pi_idx+1 , end   ) ;
}

int main()
{
    vector<int> arr = {6,2,9,3,5,1,16,5,8,1} ;
    QuickSort(arr , 0 , arr.size()-1 ) ;
    
    for( auto i : arr )
        cout<<i<<" " ;
    
    return 0 ;
}