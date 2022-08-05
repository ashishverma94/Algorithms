#include<bits/stdc++.h>
using namespace std ;

int precedence( string op )
{
	if ( op == "^" )
		return 3 ;
	else if ( op == "*" || op == "/" )
		return 2 ;
	else 
		return 1 ;
}

void join( stack<string> &sign , stack<string> &alpha)
{
	string second = alpha.top() ;
	alpha.pop() ;
	string first = alpha.top() ;
	alpha.pop() ;
	string op = sign.top() ;
	sign.pop() ;
	
	alpha.push( first + second + op ) ;
}

int main()
{
	string infix = "a+b*(c^d-e)^(f+g*h)-i" ;
	cout<< "Infix Expression is  :"<<infix<<endl;
	stack<string> sign , alpha ;
	
	for ( auto ch : infix )
	{
        string i = "";
        i += ch ;
		if ( int(i[0]) >= 97 && int(i[0]) <= 122 )
			alpha.push(i) ;
		else if ( i == "(" )
			sign.push(i) ;
		else if ( i== ")" )
		{
			while( sign.top() != "(" )
				join( sign , alpha ) ;
			sign.pop() ;
		}
		else
		{
			int prec = precedence( i ) ;
			while( !sign.empty() && precedence( sign.top()) >= prec && sign.top() != "(" )
				join( sign , alpha ) ;
			sign.push(""+i) ;
		}
	}	
	while( sign.size() > 0 )
		join( sign , alpha ) ;
	
	cout<<"Postfix expression is:"<<alpha.top()<<endl; ;
	return 0 ;
}