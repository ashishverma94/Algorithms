#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10 ;
typedef long long ll ;
vector<bool> isPrime(N,true) ;

// Seive of Eratosthenes
void MarkPrime ( )
{
	// 1 is not a prime number 
	isPrime[0] = isPrime[1] = false ;

	for ( ll i = 2 ; i < N ; i ++ )
		if ( isPrime[i] == true )
			for ( ll j = 2*i ; j < N ; j = j + i )
				isPrime[j] = false ;
}

// complexity is O(n*loglogN)

int main() {
	
	// call MarkPrime
	MarkPrime();

	// print all prime
	for ( int i  = 0 ; i <= 100 ; i ++ )
		cout<<i<<" "<< isPrime[i]<<endl ;

	return 0;
}