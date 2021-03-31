package coding;

public class Leetcode8_myAtoi {
	 public static boolean addExact(int x, int y) {
	        int r = x + y;
	        return !(((x ^ r) & (y ^ r)) < 0);
	    }
		
		public static int myAtoi(String str) {
			boolean flag = true;
	        if(str.equals(""))
	            return 0;
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
				
				if(!(str.charAt(i) >=48 && str.charAt(i) <= 57) && str.charAt(i)!=45&&str.charAt(i) != '+')
					return 0;
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
}
