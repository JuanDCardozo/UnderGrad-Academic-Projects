/** ***************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* CRUZ I.D: jcardozo
* Class: CMPS 12B
* Section: Mondays 6-8
* Date: 04/24/2015
* KeyNotFoundException.java
* Throws an exception if the key is nul (not found) and outputs a message
****************************************************************************/
public class KeyNotFoundException extends RuntimeException{
    public KeyNotFoundException(String s){
	super(s);
    }
}