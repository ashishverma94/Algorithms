class DisjointSet {
	vector<int> rank , parent , size ;
public :
	DisjointSet( int n ){
		rank.resize(n+1 , 0 ) ;
		parent.resize(n+1) ;
		size.resize(n+1) ;
		for ( int i = 0 ; i <= n ; i++ )
		{
			parent[i] = i ;
			size[i] = 1 ;
		}
	}

	int findParent( int node ){
		if ( node == parent[node] )
			return node ;
		return parent[node] = findParent(parent[node]) ;
	}

	void unionByRank( int u , int v ){
		int parent_u = findParent(u) ;
		int parent_v = findParent(v) ;
		if ( parent_v == parent_u )
			return ;
		if ( rank[parent_v] < rank[parent_u] )
			parent[parent_v] = parent_u ;
		else if ( rank[parent_u] < rank[parent_v] )
			parent[parent_u] = parent_v ;
		else
		{
			parent[parent_v] = parent_u ;
			rank[parent_u]++ ;
		}
	}

	void unionBySize( int u , int v ){
		int parent_u = findParent(u) ;
		int parent_v = findParent(v) ;
		if ( parent_v == parent_u )
			return ;
		if ( size[parent_u] < size[parent_v] )
		{
			parent[parent_u] = parent_v ;
			size[parent_v] += size[parent_u] ;
		}
		else
		{
			parent[parent_v] = parent_u ;
			size[parent_u] += size[parent_v] ;
		}
	}
} ;

