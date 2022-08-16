int lowbound( vector<int> & arr , int low , int high  , int num ) 
{
    if ( arr.size() == 1 )
    {
        if ( arr[0] >= num )
            return 0 ;
        else
            return 1 ;
    }
    if ( low >= high )
        return low ;
    
    int mid = low + ( high - low )/2 ;
    if ( arr[mid] < num )
        return lowbound(arr , mid+1 , high , num ) ;
    return lowbound(arr , low , mid , num ) ;
}