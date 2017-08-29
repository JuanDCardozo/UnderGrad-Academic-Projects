/* ****************************************************************************
 * Name: Juan D. Cardozo
 * Student I.D: 1362585
 * CRUZ I.D: jcardozo
 * Class: CMPS 12M
 * Section: Mondays 6-8
 * Date: 04/08/2015
 * Extrema.java
 * This Program Finds the Extrema( min and max) of a list.
 ******************************************************************************/

class Extrema {
//compareMax()
//Compares two integers and returns the biggest one. If equal return a.

    static int compareMax(int a, int b) {
        if (a > b) {
            return a;
        } else if (b > a) {
            return b;
        } else {
            return a;
        }
    }

//compareMin()
    // Compares two integers and returns the smallest one. If  equal return a
    static int compareMin(int a, int b) {
        if (a > b) {
            return b;
        } else if (b > a) {
            return a;
        } else {
            return a;
        }

    }

    // maxArray()
        // returns the largest value in int array A
    static int maxArray(int[] A, int p, int r) {
        int q = (p + r) / 2;
        int temp1 = 0, temp2 = 0;
        if (q == r) {
            return A[q];
        } else {
            //Save numbers
            temp1 = maxArray(A, p, q);
            temp2 = maxArray(A, q + 1, r);

            //Compare numbers
            return compareMax(temp1, temp2);
        }
    }

    // minArray()
        // returns the smallest value in int array A
    static int minArray(int[] A, int p, int r) {
        int q = (p + r) / 2;
        int temp1 = 0, temp2 = 0;
        if (q == r) {
            return A[q];
        } else {
            // Store the numbers
            temp1 = minArray(A, p, q);
            temp2 = minArray(A, q + 1, r);

            //Compares the numbers and returns it
            return compareMin(temp1, temp2);
        }
    }

    // main()
    public static void main(String[] args) {
        int temp = 0;
        int[] B = {-1, 2, 6, 3, 9, 2, -3, -2, 11, 5, 7};
        System.out.println("max = " + maxArray(B, 0, B.length - 1));  // output: max = 11
        System.out.println("min = " + minArray(B, 0, B.length - 1));  // output: min = -3

    }

}
