/** ***************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* CRUZ I.D: jcardozo
* Class: CMPS 12M
* Section: Mondays 6-8
* Date: 05/17/2015
* List.java
* Creates a List with functions to alter it. It can be of anytype
*****************************************************************************/

public class Queue implements QueueInterface {
//------------------Private Fields and Methods------------------------
	
    
   // private inner Node class
   private class Node {
      Object item;
      Node next;

      Node(Object x){
         item = x;
         next = null;
      }
   }
    //Fields for the Queue Class
    private Node front;
    private int numItems;

 //------------------Public Fields and Methods------------------------ 

   // Queue()
   // constructor for the Queue class
   public Queue(){
      front = null;
      numItems = 0;
   }

   // isEmpty()
   // pre: none
   // post: returns true if this Queue is empty, false otherwise
   public boolean isEmpty(){
	   return(numItems == 0);
   }

   // length()
   // pre: none
   // post: returns the length of this Queue.
   public int length(){
	   return numItems;
   }

   // enqueue()
   // adds newItem to back of this Queue
   // pre: none
   // post: !isEmpty()
   public void enqueue(Object newItem){
       Node N; 
	   if(numItems == 0){
	         N = new Node(newItem);
	         N.next = front;
	         front = N;
	      }else{
	       N = front;
	    	  while(N.next != null){N = N.next;}
	    	  N.next = new Node(newItem);
	      }
	      numItems++;
   }

   // dequeue()
   // deletes and returns item from front of this Queue
   // pre: !isEmpty()
   // post: this Queue will have one fewer element
   public Object dequeue() throws QueueEmptyException{
	   if( numItems==0 ){
	         throw new QueueEmptyException("cannot dequeue() empty queue");
	      }
	   
	   Node N = front;
	   Object returnValue = N.item;
       front = front.next;
       N.next = null;
       numItems--;
       return returnValue;
   }

   // peek()
   // pre: !isEmpty()
   // post: returns item at front of Queue
   public Object peek() throws QueueEmptyException{
	   if( numItems==0 ){
	         throw new QueueEmptyException("cannot peek() empty queue");
	      }
	   return front.item;
   }

   // dequeueAll()
   // sets this Queue to the empty state
   // pre: !isEmpty()
   // post: isEmpty()
   public void dequeueAll() throws QueueEmptyException{
	   if( numItems==0 ){
	         throw new QueueEmptyException("cannot dequeueAll() empty queue");
	      }
	   front = null;
	   numItems = 0;
   }

   // toString()
   // overrides Object's toString() method
   public String toString(){
	   StringBuffer sb = new StringBuffer();
	   Node N = front;
	   for( ; N!=null; N=N.next) sb.append(N.item).append(" ");
	      return new String(sb);
	   }
   
}
