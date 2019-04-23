package coding;

public class Leetcode14_longestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0)
            return "";
        String prefix = "";
        int minLength = Integer.MAX_VALUE;
        for(int i = 0; i < strs.length; i++){
            if(strs[i].length() < minLength ){
                minLength = strs[i].length();
            }
        }
        
        
        for(int j = 0; j < minLength; j++){
            boolean flag = true;
            for(int k = 0; k < strs.length-1; k++){
                if(strs[k].charAt(j) != strs[k+1].charAt(j))
                    flag = false;
            }
            if(flag)
                prefix += strs[0].charAt(j);
            else
                break;
        }
        
        return prefix;
    }
}
