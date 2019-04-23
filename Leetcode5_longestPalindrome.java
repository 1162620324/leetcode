package coding;

/*
 * 动态规划
 */
public class Leetcode5_longestPalindrome {
	public static String longestPalindrome(String s) {
		 if(s.equals("")){
	            return "";
	        }
       String longest_Pal = null;
       int length = s.length();
       int [][] dynamic_Array = new int[length][length];
       
       for(int i = 0; i < length; i++) {
       	for(int j = 0; j < length; j++) {
       		dynamic_Array[i][j] = 0;
       	}
       }
       
       for(int k = 1; k <= length; k++) {
       	for(int i = 0; i < length-k+1; i++ ) {
       		if(k == 1) {
       			dynamic_Array[i][i+k-1] = 1;
       		}
       		if(k == 2) {
       			if((s.charAt(i) == s.charAt(i+k-1))) 
       				dynamic_Array[i][i+k-1] = 2;
       			else
       				dynamic_Array[i][i+k-1] = 0;
       		}
       		if(k != 1 && k != 2) {
       			if((s.charAt(i) == s.charAt(i+k-1))) {
       				if(dynamic_Array[i+1][i+k-2] != 0) {
       					dynamic_Array[i][i+k-1] = dynamic_Array[i+1][i+k-2]+2;
       				}
       				else {
       					dynamic_Array[i][i+k-1] = 0;
       				}
       			}
       		}
       	}
       }
       
       int maxi = 0;
       int maxj = 0;
       int max = 0;
       for(int i = 0; i < length; i++) {
       	for(int j = i; j < length; j++) {
       		if(dynamic_Array[i][j] > max) {
       			max = dynamic_Array[i][j];
       			maxi = i;
       			maxj = j;
       		}
       	}
       }
       
       longest_Pal = s.substring(maxi, maxj+1);
       
       
       return longest_Pal;
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
