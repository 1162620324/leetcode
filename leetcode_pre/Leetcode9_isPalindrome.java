package coding;

public class Leetcode9_isPalindrome {
    public boolean isPalindrome(int x) {
        if(x<0)
            return false;
        String str = ((Integer)x).toString();
        return is_Palindroic(str);
        
    }
    
    
    public static boolean is_Palindroic(String str) {
		if(str.length() == 1) 
			return true;
		
		if(str.length() == 2) 
			return str.charAt(0) == str.charAt(1);
		
		if(str.charAt(0) == str.charAt(str.length()-1)) {
			return is_Palindroic(str.substring(1, str.length()-1));
		}
		else 
			return false;
	}
}
