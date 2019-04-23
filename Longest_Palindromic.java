package coding;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

public class Longest_Palindromic {
	
       
	public static void main(String[] args) {
		int [] nums = {3,2,2,3};
		
		System.out.println(countAndSay(4));;
		
	}
	
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
	
	public static String countAndSay(int n) {
        String s1 = "1", s2 = "";
        while(--n > 0) {
        	for(int i = 0; i < s1.length(); i++) {
        		for(int j = 0; ; j++) {
        			if(j == s1.length())
        			if(i + j < 	s1.length() && s1.charAt(i+j) == s1.charAt(i+j+1)) {
        				continue;
        			}
        			j++;
        			s2 = s2 + j + s1.charAt(i);
        			i = i + j -1;
        			break;
        		}
        		s1 = s2;
        		s2 = "";
        	}
        }
        return s1;
    }
	 public int searchInsert(int[] nums, int target) {
		 int res = 0;
		 for(int i = 0; i < nums.length; i++) {
			 if(nums[i] == target) {
				 res = i;
			 }
			 else if(nums[i] > target) {
				 res = i;
			 }
		 }
		 
		 return res;
		 
		 
		 
	 }
	public int strStr(String haystack, String needle) {
        int [] next = getNext(needle);
        
        char[] t = haystack.toCharArray();
        char[] p = needle.toCharArray();
        int i =0; 
        int j = 0;
        while(i < t.length && j < p.length) {
        	if(j == -1 || t[i] == p[j]) {
        		i++;
        		j++;
        	}
        	else {
        		j = next[j];
        	}
        }
        
        if(j == p.length) {
        	return i - j;
        }
        else {
        	return -1;
        }
    }
	
	public static int[] getNext(String ps) {
		char[] p = ps.toCharArray();
		int [] next = new int[ps.length()];
		next[0] = -1;
		int j = 0;
		int k = -1;
		while(j < ps.length()-1) {
			if(k == -1 || p[j] == p[k]) {
				next[++j] = ++k;
			}
			else {
				k = next[k];
			}
		}
		return next;
	}
	
	
	public static int removeElement(int[] nums, int val) {
		int res = nums.length;
        int i = 0;
        int lenght = nums.length;
        while(i < lenght) {
        	if(nums[i] == val) {
        		res--;
        		for(int j = i; j < nums.length-1; j++) {
        			int temp = nums[j];
        			nums[j] = nums[j+1];
        			nums[j+1] = temp;
        		}
        		lenght--;
        		continue;
        	}
        	i++;
        }
        return res;
    }
	
	
	 public static int removeDuplicates(int[] nums) {
		 int res = 1;
		 Arrays.sort(nums);
		 for(int i =0 ; i < nums.length-1; i++) {
			 if(!(nums[i] == nums[i+1])) {
				 res++;
			 }
		 }
		 
		 
		 return res;
	 }
	
	
    public static ListNode swapPairs(ListNode head) {
    	
    	ListNode realHead = new ListNode(-1);
    	realHead.next = head;
    	ListNode nowNode = null;
    	ListNode last = realHead;
    	ListNode next = null;
    	nowNode = head;
        while(nowNode != null) {
        	if(nowNode.next != null) { 
        		next = nowNode.next;
        		nowNode.next = next.next;
        		next.next = nowNode;
        		last.next = next;
        		last = nowNode;
        		nowNode = nowNode.next;
        	}
        	else {
        		
        	}
        }
    	
    	return realHead.next;
    }
    
//	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//        ListNode res = null;
//        ListNode point = res;
//        if(l1 == null && l2 == null) {
//        	return null;
//        }
//        if(l1 == null && l2 != null) {
//        	return l2;
//        }
//        if(l1 != null && l2 == null) {
//        	return l1;
//        }
//        
//        do{
//            if()
//        }while(l1.next != null && l2.next != null);
//    }
	
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
        
        
        return flag;
        
    }
	public static int threeSumClosest(int[] nums, int target) {
		int i = 0;
        while(true) {
        	
        	if(helpFind(nums, target+i)) {
        		return target+i;
        	}
        	if(helpFind(nums, target-i)) {
        		return target-i;
        	}
        	i++;
        }
    }
	
	public static  boolean helpFind(int [] nums, int target) {
		boolean flag = false;
		
		List<List<Integer>> lists = new ArrayList<List<Integer>>();
	    Arrays.sort(nums);
		
	    for(int k = 0; k < nums.length - 2; k++) {
	    	 int i  =k +1;
	    	 int j = nums.length-1;
	    	 int targets = -nums[k]+target;
	    	 while(i < j) {
	    		 if(nums[i] + nums[j] == targets) {
	    			 lists.add(Arrays.asList(nums[k], nums[i++], nums[j--]));
	    			 while(i<j && nums[i] == nums[i-1]) i++;
	    			 while(i<j && nums[j] == nums[j+1]) j++;
	    			 
	    		 }
	    		 else if(nums[i] + nums[j] < targets) i++;
	    		 else j--;
	    	 }
	    	 while(k < nums.length - 2 && nums[k] == nums[k+1])
	                k++;
	     }
	    
	    
		return !lists.isEmpty();
	}
	 public static List<List<Integer>> threeSum(int[] nums) {
		 List<List<Integer>> lists = new ArrayList<List<Integer>>();
	     Arrays.sort(nums);
         
	     for(int k = 0; k < nums.length - 2; k++) {
	    	 int i  =k +1;
	    	 int j = nums.length-1;
	    	 int target = -nums[k] +0;
	    	 while(i < j) {
	    		 if(nums[i] + nums[j] == nums[k]) {
	    			 lists.add(Arrays.asList(nums[k], nums[i++], nums[j--]));
	    			 while(i<j && nums[i] == nums[i-1]) i++;
	    			 while(i<j && nums[j] == nums[j+1]) j++;
	    			 
	    		 }
	    		 else if(nums[i] + nums[j] < target) i++;
	    		 else j--;
	    	 }
	    	 while(k < nums.length - 2 && nums[k] == nums[k+1])
	                k++;
	     }
	     return lists;
	       
	 }
	
	public static boolean addExact(int x, int y) {
        int r = x + y;
        return !(((x ^ r) & (y ^ r)) < 0);
    }
	
	public static int myAtoi(String str) {
		boolean flag = true;
		if(!(str.charAt(0) >=48 && str.charAt(0) <= 57) && str.charAt(0)!=32 && str.charAt(0)!='-'&&str.charAt(0) != '+')
			return 0;
		String temp = "";
		int i = 0;
			char ch = str.charAt(i);
			while(ch == ' ') {
				i++;
				if(i == str.length())
					return 0;
				ch = str.charAt(i);
			}
			System.out.println(str.charAt(i));
			if(!(str.charAt(i) >=48 && str.charAt(i) <= 57) && str.charAt(i)!=45 && str.charAt(i) != '+')
				return 0;
			System.out.println("dddd");
			if(str.charAt(i) == 45) {
				flag = false;
				i++;
			}
			else if(str.charAt(i) == '+') {
				i++;
			}
			if(i == str.length())
				return 0;
			ch = str.charAt(i);
			while(ch == '0') {
				i++;
				if(i == str.length())
					return 0;
				ch = str.charAt(i);
			}
			
			if(i == str.length() || !(str.charAt(i) >=48 && str.charAt(i) <= 57) )
				return 0;
			char ch1 = str.charAt(i);
			while(i < str.length() && (str.charAt(i)>=48 && str.charAt(i)<=57)) {
				ch1 = str.charAt(i);
				temp += ch1;
				i++;
			}
				
			char[] temp_Array = temp.toCharArray();
			
			if(temp_Array.length > 10) {
				if(flag) 
					return Integer.MAX_VALUE;
				else 
					return Integer.MIN_VALUE;
			}
			else if(temp_Array.length == 10) {
				if(temp_Array[0] > 50) {
					if(flag) 
						return Integer.MAX_VALUE;
					else 
						return Integer.MIN_VALUE;
				}
			}
				
			int ret = 0;
			
			for(int j = temp_Array.length-1; j >= 0; j--) {
				if(addExact(ret, (int)((temp_Array[j]-48)*Math.pow(10, temp_Array.length-1-j)))) {
					
					ret += (temp_Array[j]-48)*Math.pow(10, temp_Array.length-1-j);
				}
				else {
					if(flag) 
						return Integer.MAX_VALUE;
					else 
						return Integer.MIN_VALUE;
				}
					
			}
			
			return flag ? ret : ret *(-1);
	}
	
	
	public static int reverse(int x) {
			boolean flag = false;
			if(x < 0) {
				x = x* (-1); 
				flag = false;
			}
			else
				flag = true;
			System.out.println(x);
			StringBuilder temp = new StringBuilder(((Integer)Math.abs(x)).toString()).reverse();
			int ret = 0;
			if(Double.parseDouble(temp.toString()) > Integer.MIN_VALUE)
				return 0;
			else 
				 ret = Integer.parseInt(temp.toString());
			if(flag)
				return ret;
			else 
				return ret*-1;
	    
	}
	
	public static int ten_pow(int i) {
		int ret = 1;
		for(int j = 1 ; j <= i; j++) {
			ret *= 10;
		}
		return ret;
	}
	
	public String convert(String s, int numRows) {
        if(numRows == 1) 
        	return s;
        
        List<StringBuilder> rows = new ArrayList<>();
        boolean goningDown = false;
        int curRow = 0;
        
        for(int i =0; i < Math.min(numRows, s.length()); i++) {
        	rows.add(new StringBuilder());
        }
        
        for(char ch: s.toCharArray()) {
        	rows.get(curRow).append(ch);
        	if(curRow == 0 || curRow == numRows-1) 
        		goningDown = !goningDown;
        	curRow += goningDown ? 1 : -1;
        }
        
        StringBuilder ret = new StringBuilder();
        for(StringBuilder sb: rows) 
        	ret.append(sb);
        return ret.toString();
    }
	
	
	
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
