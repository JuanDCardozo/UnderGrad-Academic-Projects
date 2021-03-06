/** ***************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* CRUZ I.D: jcardozo
* Class: CMPS 12M
* Section: Mondays 6-8
* Date: 04/13/2015
* ListTest.java
*
*****************************************************************************/
public class ListTest{
    public static void main(String[] args){
	String s = "";
	int methodTestPassed = 0;
	int totalTestPassed = 0;
	List<String> A = new List<String>();
	List<Integer> B = new List<Integer>();
	List<Double> C =  new List<Double>();

	// Test Harness Message
	System.out.println("------------------------------");
	System.out.println("Test Harness: List.java");
	System.out.println("------------------------------");

	// Test 1
	A.add(1,"hello");
	A.add(2,"world");
	s += A.get(1);
	if(s.compareTo("hello")== 0){
	    ++methodTestPassed;
	}
	s = "";

	//Test 2
	B.add(1,2);
	int tempInt =  B.get(1);
	if(tempInt  == 2){
	    ++methodTestPassed;
	}

	//Test 3
	C.add(1,1.23);
	double tempDouble = C.get(1);
	if(tempDouble == 1.23){
	    ++methodTestPassed;
	}

	

	//Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method add(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	    System.out.println("Method get(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	    totalTestPassed+=2;

	}else{
	    System.out.println("Method add(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	    System.out.println("Method get(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;

	//Test for isEmpthy()
	// Test 1
	if(!A.isEmpty()){
	   ++ methodTestPassed;
	}
	
	//Test 2
	if(!B.isEmpty()){
	    ++methodTestPassed;
	}

	//Test 3
	List<Integer> D = new List<Integer>();
	if(D.isEmpty()){
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
	
	// Test for size();
	// Test 1
	if(A.size() ==  2){
	    ++methodTestPassed;
	}

	// Test 2
	if(B.size() == 1){
	    ++methodTestPassed;
	}

	// Test 3
       	if(C.size() == 1){
	    ++methodTestPassed;
	}

	//Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method size(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method size(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
		
	// Test for remove();
	//Test 1
	A.remove(1);
	if(A.size() == 1){
	    ++methodTestPassed;
	}

	//Test 2
	A.remove(1);
	if(A.isEmpty()){
	    ++methodTestPassed;
	}

    //Print out information about test
	if(methodTestPassed == 2){
	    System.out.println("Method remove(): PASSED!");
	    System.out.println("Tests Passed: (2/2)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method remove(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/2)\n");
	}
	methodTestPassed = 0;
	
	// Test for removeAll();
	// Test 1 
	B.add(2,5);
	B.removeAll();
	if(B.isEmpty()){
	    ++methodTestPassed;
	}

	// Test 2
	C.add(2,0.5);
	C.removeAll();
	if(C.isEmpty()){
	    ++methodTestPassed;
	}

	// Test 3
	D.removeAll();
	if(D.isEmpty()){
	    ++methodTestPassed;
	}
	

    //Print out information about test
	if(methodTestPassed == 3){
	    System.out.println("Method removeAll(): PASSED!");
	    System.out.println("Tests Passed: (3/3)\n");
	     ++totalTestPassed;
	}else{
	    System.out.println("Method removeAll(): FAILED!");
	    System.out.println("Tests Passed: ("+methodTestPassed+"/3)\n");
	}
	methodTestPassed = 0;
	
	// Test for toString();
	A.add(1,"Hello");
	A.add(2,"World");
	B.add(1,1);
	B.add(2,2);
	C.add(1,1.12);
	C.add(2,2.21);
	String listA = "Hello World ";
	String listB = "1 2 ";
	String listC = "1.12 2.21 ";
	
	// Test 1
	s = A.toString();
	if(s.compareTo(listA) == 0){
	    ++methodTestPassed;
	}

	// Test 2
	s = B.toString();
	if(s.compareTo(listB) == 0){
	    ++methodTestPassed;
	}
	
	// Test 3
	s = C.toString();
	if(s.compareTo(listC)== 0){
	    ++methodTestPassed;
	}
	
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