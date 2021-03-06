/*
 * Name: Juan D.Cardozo
 * Student I.D: 1362585
 * Cruz I.D: jcardozo
 * Class: CMPS 12B
 * Section Mondays 6-8
 * Date: 04/19/2015
 * Programming Assignment 2
 * Search.java
 * This programs opens a file and reads each line.
 * then organizes it alphabetically and then does a
 * binary search to find the target word
 */

import java.io.*;
import java.util.Scanner;

public class Search{

    //binarySearch()
    // Returnes the index if the target string was found
    public  static int  binarySearch(String[] A, int p, int r, String  target){
		int q;
		if(p > r) {
			return -1;
		}else{
			q =(p+r)/2;
			if(target.compareTo(A[q])== 0){
				return q;
			}else if(target.compareTo(A[q]) < 0){
				return binarySearch(A,p,q-1,target);
			}else{
				return binarySearch(A,q+1,r,target);
			}
		}
    }

    // mergeSort()
   // sort subarray A[p...r]
   public static void mergeSort(String[] A, int p, int r){
      int q;
      if(p < r) {
         q = (p+r)/2;
         
         mergeSort(A, p, q);
         mergeSort(A, q+1, r);
         merge(A, p, q, r);
      }
   }

   // merge()
   // merges sorted subarrays A[p..q] and A[q+1..r]
   public static void merge(String[] A, int p, int q, int r){
      int n1 = q-p+1;
      int n2 = r-q;
      String[] L = new String[n1];
      String[] R = new String[n2];
      int i, j, k;

      for(i=0; i<n1; i++) L[i] = A[p+i];
      for(j=0; j<n2; j++) R[j] = A[q+j+1];
      i = 0; j = 0;
      for(k=p; k<=r; k++){
         if( i<n1 && j<n2 ){
            if( L[i].compareTo(R[j])< 0 ){
               A[k] = L[i];
               i++;
            }else{
               A[k] = R[j];
               j++;
            }
         }else if( i<n1 ){
            A[k] = L[i];
            i++;
         }else{ 
            A[k] = R[j];
            j++;
         }
      }
   }

    // main()
    public static void main(String[] args)throws IOException{
	String[] token;
	String[] target = new String[args.length -1];
	Scanner in = null;
	int i = 0, lines = 0;

	// Check Comand Line Arguments
	if(args.length < 2){
	    System.out.println("Usage: FileTokens infile target1 target2 ...");
	    System.exit(1);
	} 

	//Open Files and store Comand Line arguments
	in = new Scanner(new File(args[0]));
	for(i = 1; i <=  args.length-1; i++){
	    int j = i-1;
	    target[j] = args[i];
	}
	
	// read lines from in and count lines.	
	while(in.hasNextLine() ){
	    in.nextLine();
	  // count lines
	  lines++;
	 }

      //Store each line in a string array
      token = new String[lines];
      i = 0;
      in = new Scanner(new File(args[0]));
      while (i <  lines ){
	  token[i++] = in.nextLine();
      }
      // close files
      in.close();

      // Sort the strings and search for the target
      mergeSort(token, 0, token.length-1);
      for(int j = 0; j < target.length; ++j){
	  //int j = i-1;
	  if(binarySearch(token,0, token.length-1,target[j]) >=  0){
	      System.out.println(target[j]+" found");
	  }else{
	      System.out.println(target[j]+" not found");
	  }
      }
    }
}

