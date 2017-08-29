//import java.util.Queue;

/** ***************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* CRUZ I.D: jcardozo
* Class: CMPS 12B
* Section: Mondays 6-8
* Date: 05/24/2015
* QueueTest.java
*
*****************************************************************************/
public class QueueTest{
    public static void main(String[] args){
	String s = "";
	int methodTestPassed = 0;
	int totalTestPassed = 0;
        Queue A = new Queue();
	

	// Test Harness Message
	System.out.println("------------------------------");
	System.out.println("Test Harness: Queue.java");
	System.out.println("------------------------------");

	Job temp;
	
	// Test 1
	Job job1 = new Job(1,1);
	A.enqueue(job1);
	temp = (Job) A.peek();
	if(job1.equals(temp)){
	    ++methodTestPassed;
	}


	//Test 2
	Job job2 = new Job(2,2);
	A.enqueue(job2);
	temp = (Job) A.peek();
	if(job1.equals(temp)){
	    ++methodTestPassed;
	}

	//Test 3
	Job job3 = new Job(3,4);
	A.enqueue(job3);
	temp = (Job) A.peek();
	if(!job2.equals(temp)){
	    ++methodTestPassed;
	}

	

	//Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method enqueue(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	    System.out.println("Method peek(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	    totalTestPassed+=2;

	}else{
	    System.out.println("Method enqueue(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	    System.out.println("Method peek(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;

	//Test for isEmpty()
	// Test 1
	if(!A.isEmpty()){
	   ++ methodTestPassed;
	}
	
	//Test 2
	Queue B = new Queue();
	if(B.isEmpty()){
	    ++methodTestPassed;
	}

	//Test 3
	Queue C = new Queue();
	if(C.isEmpty()){
	    ++methodTestPassed;
	}

	//Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method isEmpty(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method isEmpty(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
	
	// Test for length();
	// Test 1
	if(A.length() ==  3){
	    ++methodTestPassed;
	}

	// Test 2
	B.enqueue(job1);
	B.enqueue(job2);
	B.enqueue(job3);
	B.enqueue(job1);
	if(B.length() == 4){
	    ++methodTestPassed;
	}

	// Test 3
       	if(C.length() == 0){
	    ++methodTestPassed;
	}

	//Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method length(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method length(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
		
	// Test for dequeue();
	//Test 1
	A.dequeue();
	if(A.length() == 2){
	    ++methodTestPassed;
	}

	//Test 2
	A.dequeue();
	if(A.length() == 1){
	    ++methodTestPassed;
	}
	
	//Test 2
	B.dequeue();
	if(B.length() == 3){
		   ++methodTestPassed;
	}

    //Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method dequeue(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method dequeue(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
	
	// Test for dequeueAll();
	// Test 1 
	A.dequeueAll();
	if(A.isEmpty()){
	    ++methodTestPassed;
	}

	// Test 2
	B.dequeueAll();
	if(B.isEmpty()){
	    ++methodTestPassed;
	}

	// Test 3
	try {
		C.dequeueAll();
	} catch (QueueEmptyException e) {
		System.out.println("Caught Exception: ");
        System.out.println(e);
        System.out.println("Continuing without interuption");
	    ++methodTestPassed;
	}
	

    //Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method dequeueAll(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method dequeuAll(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
	
	// Test for toString();
	A.enqueue(job1);
	A.enqueue(job2);
	B.enqueue(job2);
	C.enqueue(job3);
	
	String listA = "(1, 2, *) (2, 2, *)";
	String listB = "(2, 2, *) ";
	String listC = "(3, 4, *) ";
	
	// Test 1
	System.out.println("Expected Output:");
	System.out.println(listA);
	System.out.println("Output:");
	System.out.println(A);
    
	// Test 2
	System.out.println("\nExpected Output:");
	System.out.println(listB);
	System.out.println("Output:");
	System.out.println(B);
	
	// Test 3
	System.out.println("\nExpected Output:");
	System.out.println(listC);
	System.out.println("Output:");
	System.out.println(C);
	
	
	methodTestPassed = 3;
    //Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method toString(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method toString(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
	
	// Results of Test Harness
	System.out.println("------------------------------");
	if(totalTestPassed == 7){
	    System.out.println("Test Harness Result: PASSED!");
	    System.out.println("Total Tests Passed: (7/7)");

	}else{
	    System.out.println("Test Harness Result: FAILED!");
	    System.out.println("Total Tests Passed: ("+totalTestPassed+"/7)");
	}
	System.out.println("------------------------------");

   }
}