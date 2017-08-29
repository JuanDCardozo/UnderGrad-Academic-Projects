/* ****************************************************************************
 * Name: Juan D. Cardozo
 * Student I.D: 1362585
 * CRUZ I.D: jcardozo
 * Class: CMPS 12M
 * Section: Mondays 6-8
 * Date: 04/06/2015
 * HelloUser2.java
 * Prints greeting in spanish to stdout, then prints the username initial.
******************************************************************************/
class HelloUser2{
   public static void main( String[] args ){
      String userName = System.getProperty("user.name");
      long time       = System.currentTimeMillis();

      System.out.println("Bienvenido "+userName+" al programa  HelloUser2\n");
      System.out.println("UserName Initial:\n");
      System.out.printf("       ### \n");
      System.out.printf("       ###\n");
      System.out.printf("       ###\n");
      System.out.printf("       ###\n");
      System.out.printf("       ###\n");
      System.out.printf("       ###\n");
      System.out.printf("       ###\n");
      System.out.printf("       ###\n");
      System.out.printf(" #########\n");
      System.out.printf(" #########\n");
      System.out.printf("\nTime: %tc.%n", time);
   }
}