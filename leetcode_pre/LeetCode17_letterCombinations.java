package coding;

import java.util.ArrayList;
import java.util.List;

public class LeetCode17_letterCombinations {
	public static List<String> letterCombinations(String digits) {
        String[] map = new String[8];
        map[0] = "abc";
        map[1] = "def";
        map[2] = "ghi";
        map[3] = "jkl";
        map[4] = "mno";
        map[5] = "pqrs";
        map[6] = "tuv";
        map[7] = "wxyz";
        List<String> res = new ArrayList<>();
        
        if(digits.length() == 1){
        	for(int i = 0; i < map[Integer.parseInt(digits)].length();i++) {
        		res.add(map[Integer.parseInt(digits)].substring(i, i+1));
        	}
        	return res;
        }
        int len = digits.length();
        int [] digiNUM = new int [len];
        
       String Num2String = map[Integer.parseInt(digits.substring(0, 1))];
       
       List<String> Recursion = letterCombinations(digits.substring(1,digits.length()));
       
       for(int i = 0; i < Num2String.length();i++) {
    	   for(int j = 0; j < Recursion.size(); j++) {
    		   res.add(Num2String.charAt(i)+Recursion.get(j));
    	   }
       }
       
       return res;
    }
}
