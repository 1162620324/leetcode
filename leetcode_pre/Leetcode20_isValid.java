package coding;

import java.util.Stack;

public class Leetcode20_isValid {
	public static boolean isValid(String s) {
        boolean flag = true;
        Stack<Character> zhong = new Stack<>();
        
        for(int i = 0; i < s.length(); i++) {
        	char ch = s.charAt(i);
        	if(ch == '(' || ch == '[' || ch == '{') {
        		zhong.push(ch);
        	}
        	else if(ch == ')' || ch == ']' || ch == '}') {
        		if(zhong.isEmpty()) {
        			flag =  false;
        		}
        		else {
        			char x = zhong.pop();
        			if((ch == ')' && x != '(')
        					|| (ch == ']' && x != '[')
        					|| (ch == '}' && x != '{')) {
        				flag = false;
        			}
        		}
        		
        	}
        }
        
        if(!zhong.isEmpty())
            flag = false;
        return flag;
        
    }
}
