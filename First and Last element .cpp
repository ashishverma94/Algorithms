
#include <bits/stdc++.h>
using namespace std;

int F_B_search( vector<int> &arr , int start ,int end , int x )
{
	int r=-1;
	if ( start <= end )
	{
		int mid = start + (end-start)/2 ;
		
		if ( (mid == 0 || arr[mid-1] < arr[mid] ) && arr[mid] == x )
			r = mid ;
		else if ( x > arr[mid] )
			return F_B_search( arr , mid+1 , end , x ) ;
		else
			return F_B_search( arr , start , mid-1 , x ) ;
	}
	return r ;
}

int L_B_search( vector<int> &arr , int start ,int end , int x )
{
	int r=-1;
	if ( start <= end )
	{
		int mid = start + (end-start)/2 ;
		
		if ( (mid == end || arr[mid+1] > arr[mid] ) && arr[mid] == x )
			r = mid ;
		else if ( x < arr[mid] )
			return L_B_search( arr , start , mid-1 , x ) ;
		else
			return L_B_search( arr , mid+1 , end , x ) ;
	}
	return r ;
}

int main()
{
    vector<int> arr = {1, 3 , 3 , 4 , 4 , 4 , 4 , 5 , 5 ,7 ,9, 9 } ;
	cout<<L_B_search(arr , 0 , arr.size() , 9) ;
	return 0;
}



