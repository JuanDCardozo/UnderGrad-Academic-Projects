/** ***************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* CRUZ I.D: jcardozo
* Class: CMPS 12M
* Section: Mondays 6-8
* Date: 04/13/2015
* Dictionary.java
* Creates a Dictionary with functions to alter it
*****************************************************************************/

public class Dictionary implements DictionaryInterface{

    // Private fields for dictionary
    private Node head;
    private int  numItems;

    //Dictionary Constructor
    Dictionary(){
	head = null;
	numItems =0;
    }

    // Node Class Constructor  
    private class Node{
	
		Node next;
		
		String key = "";
		String value = "";
                
	        // Node Constructor
		Node(String x,String y){
		   key +=x;
		   value +=y;
		   next = null;
		}
    }

    // Node findKey();
    // Return a reference to the Node containing its argument key,
    private Node findKey(String key){
		Node N = head;
		for(int i = numItems; i > 0; i-- ){
		    if(key.compareTo(N.key) == 0){
					return N;
				}
				N = N.next;
			}
		return null;
    }

    // isEmpty()
    // Returns true if there are no pairs, else false;
    public boolean isEmpty(){
		return (numItems == 0);
    }

    // size()
    // Returns the size of the list
    public int size(){
		return numItems;
    }

    // lookup()
    // Return value field if key matches the argument key, otherwise null
    public String lookup(String key){
		Node N = findKey(key);
		if(N != null){
			return N.value;
		}else{ // if key == null
			return null;
		}
    }	

    // insert()
    // inserts a node at the begining of the list
    public void insert(String key, String value){
	if(findKey(key) != null){
	    throw new  KeyCollisionException("cannot insert duplicate keys");
	}else{
	    Node newNode = new Node(key,value);
	    newNode.next = head;
	    head = newNode;
	    numItems++;
	}
    }

    // delete()
    // deletes the node with the spcified key
    public void delete(String key){
	if(findKey(key) ==  null){
	    throw new KeyNotFoundException("cannot delete non-existent key");
	}else{
	    Node N = head;
	    Node temp = N;
	    Node P  = findKey(key);
	    while(N.next != P){
		  N = N.next;
	    }
	    P = N;
  	    Node C = P.next;
	    P.next = C.next;
	    C.next = null;
	    numItems--;
	}
    }

    // makeEmpty()
    // Deletes everything in the list
    public void makeEmpty(){
		head = null;
		numItems = 0;
    }

    // toString()
    // Make into printable list
    public String toString(){
		String s ="";
		Node N = head;
		int listLength = size();
		while(listLength--  > 0){
		    
		    s=N.key+" "+N.value+"\n"+s;
		    N = N.next;
		}
		return s;
    }
}