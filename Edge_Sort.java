//Program to sort edges of graph
import java.util.*;

class GFG {

 	public static void main(String[] args)
	{

 		ArrayList<Node> ar = new ArrayList< >();

		ar.add(new Node(1,1,2));
		ar.add(new Node(7,1,3));
		ar.add(new Node(4,3,4));
		ar.add(new Node(2,4,5));
		ar.add(new Node(10,1,4));
		ar.add(new Node(3,2,3));
		ar.add(new Node(5,1,5));

 		 
 		Collections.sort(ar, new Sortbyroll());

 	for (int i = 0; i < ar.size(); i++)
			System.out.println(ar.get(i));
	}
}

class Node {

 	int weight, u, v;

 	public Node(int weight, int u, int v)
	{
  		this.weight = weight;
		this.u = u;
		this.v = v;
	}
 
	public String toString()
	{
  		return this.weight + " " + this.u + " " + this.v;
	}
}

class Sortbyroll implements Comparator<Node> {

	public int compare(Node a, Node b)
	{

		return a.weight - b.weight;
	}
}
