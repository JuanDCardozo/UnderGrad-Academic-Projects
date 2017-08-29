/** ***************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* CRUZ I.D: jcardozo
* Class: CMPS 12M
* Section: Mondays 6-8
* Date: 05/27/2015
* Dictionary.java
*
*****************************************************************************/

public class Dictionary implements DictionaryInterface{

	//----------------- Private---------------------

	//Node Class
	private class Node{
		String key;
		String value;
		Node left;
		Node right;
		
		//Node Constructor
		public Node(String k, String v){
			key = k;
			value = v;
			left = null;
			right = null;
		}
	}
	
	//----------------Private Dictionary Field----------
	private int numPairs;
	private Node root;
	
	//----------------Private Dictioanry Methods----------
	
	// findKey()
	// returns the Node containing key k in the subtree rooted at R, or returns
	// NULL if no such Node exists
        Node findKey(Node R ,String k){
		   if(R == null || k.compareTo(R.key)==0){ 
		      return R;
		   }else if( k.compareTo(R.key)<0 ) {
		       return (findKey(R.left, k));
		   }else{ // compareTo(R.right)
		       return (findKey(R.right, k));
		   }
	}
	
	// findParent()
	// returns the parent of N in the subtree rooted at R, or returns NULL 
	// if N is equal to R. (pre: R != NULL)
	Node findParent(Node N, Node R){
			String temp = "";
		   Node P=null;
		   if( N!=R ){
		      P = R;
		      while( P.left!=N && P.right!=N ){
		    	 temp = N.key;
		         if(temp.compareTo(P.key)<0)
		            P = P.left;
		         else
		            P = P.right;
		      }
		   }
		   return P;
		}
	
	// findLeftmost()
	// returns the leftmost Node in the subtree rooted at R, or NULL if R is NULL.
	Node findLeftmost(Node R){
		   Node L = R;
		   if( L!=null ) for( ; L.left!=null; L=L.left) ;
		   return L;
		}
	
	// printInOrder()
	// prints the (key, value) pairs belonging to the subtree rooted at R in order
	// of increasing keys to file pointed to by out.
	String  printInOrder(Node R){
		String s ="";
	   if( R!=null){
	      s += printInOrder(R.left);
	      s += R.key;
	      s += " ";
	      s += R.value;
	      s += "\n";
	      s+=printInOrder(R.right);
	   }
	   return s;
	}
	
	//---------------Public Dictionary -----------------
	
	// Dictionary Constructor
	public Dictionary(){
		numPairs = 0;
		root = null;
	}
	
	// isEmpty()
	   // returns true if this Dictionary is empty, false otherwise
	   // pre: none
	   public boolean isEmpty(){
		   return (numPairs == 0);
	   }

	   // size()
	   // returns the number of entries in this Dictionary
	   // pre: none
	   public int size(){
		   return numPairs;
	   }

	   // lookup()
	   // returns value associated key, or null reference if no such key exists
	   // pre: none
	   public String lookup(String key){
		   Node N;
		   N = findKey(root,key);
		   return (N == null ? null : N.value);
	   }

	   // insert()
	   // inserts new (key,value) pair into this Dictionary
	   // pre: lookup(key)==null
	   public void insert(String key, String value) throws KeyCollisionException{
		  Node N,A,B;
		  if(findKey(root,key)!=null){
		   throw new KeyCollisionException("Dictionary Error: cannot insert() duplicate key:"+key);
	   }
	   N = new Node(key,value);
	   B = null;
	   A = root;
	   while(A != null){
		   B = A;
		   if(key.compareTo(A.key) < 0){ 
			   A = A.left;
		   }else{
			   A = A.right;
		   }
	   }
	   if( B == null){
		   root = N;
	   }else if(key.compareTo(B.key) < 0){
		   B.left = N;
	   }else{
		   B.right = N;
	   }
	   numPairs++;
	   }

	   // delete()
	   // deletes pair with the given key
	   // pre: lookup(key)!=null
	   public void delete(String key) throws KeyNotFoundException{
	       Node N, S, P;
	       N = findKey(root,key);
		   if(N==null){
			   throw new KeyNotFoundException("Dictionary Error: cannot delete() non-existent key:"+key);
		   }
		  
		   if( N.left==null && N.right==null ){
		      if( N == root ){
		         root = null;
		      }else{
		         P = findParent(N, root);
		         if( P.right==N ){
		        	 P.right = null;
		         }else{
		        	 P.left = null;
		         }
		      }
		   }else if( N.right==null ){
		       if( N== root ){
		         root = N.left;
		         }else{
		        	 P = findParent(N, root);
		        	 if( P.right==N ){
		        		 P.right = N.left;
		        	 }else{
		        		 P.left = N.left;
		        	 }
		         }
		       }else if( N.left==null ){
			      if( N==root ){
			         root = N.right;
			      }else{
			         P = findParent(N,root);
			         if( P.right==N ){
			        	 P.right = N.right;
			         }else{
			        	 P.left = N.right;
			         }
			      }
			   }else{  // N->left!=NULL && N->right!=NULL
			      S = findLeftmost(N.right);
			      N.key = S.key;
			      N.value = S.value;
			      P = findParent(S, N);
			      if( P.right==S ){
			    	  P.right = S.right;
			      }else{
			    	  P.left = S.right;
			      }
			   }
		   numPairs--;
	   }

	   // makeEmpty()
	   // pre: none
	   public void makeEmpty(){
		   root = null;
		   numPairs = 0;
	   }

	   // toString()
	   // returns a String representation of this Dictionary
	   // overrides Object's toString() method
	   // pre: none
	   public String toString(){
		  return  printInOrder(root);
	   }
	
}