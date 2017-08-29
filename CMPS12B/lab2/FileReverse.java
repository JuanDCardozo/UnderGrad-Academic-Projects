/** ***************************************************************************
 * Name: Juan D. Cardozo
 * Student I.D: 1362585
 * CRUZ I.D: jcardozo
 * Class: CMPS 12M
 * Section: Mondays 6-8
 * Date: 04/13/2015
 * FileReverse.java
 * It will read each input line, pare the tokens, then print each token 
 * backwards on a line by itself.
 ******************************************************************************/
 
import java.io.*;
import java.util.Scanner;

class FileReverse{

   /**
   * stringReverse()
   * his function will return a String that is the reversal of the 
   * first n characters of s.
   */
   public static String stringReverse(String s, int n){
       String newString = "";
	if(n > 0) {
	    newString += s.charAt(n-1);
            newString += stringReverse(s,n-1);
            return newString;
	}else{
	    return newString;
	}
   }
 public static void main(String[] args) throws IOException{

      Scanner in = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      int i, n, m, j;

      // check command line arguments
      if(args.length < 2){
         System.out.println("Usage: FileTokens infile outfile");
         System.exit(1);
      }

      // open files
      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));

      // read lines from in, extract and print tokens from each line
      while( in.hasNextLine() ){

         // trim leading and trailing spaces, then add one trailing space so 
         // split works on blank lines
         line = in.nextLine().trim() + " "; 

         // split line around white space 
         token = line.split("\\s+");  

         // print out tokens       
         n = token.length;
         for(i=0; i<n; i++){
            token[i] = FileReverse.stringReverse(token[i],token[i].length());
            out.println(token[i]+" ");
         }
      }


      // close files
      in.close();
      out.close();
   }
}

  

