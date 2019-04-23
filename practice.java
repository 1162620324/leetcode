package coding;

import java.util.*;

public class practice {

	public static void main(String[] args) {
		String s = "abcabcdeabc";
		
		System.out.println(lengthOfLongestSubstring(s));
	}

	
	public static int lengthOfLongestSubstring(String s) {
		int i = 0, j = 0;
		int longest = 0;
		Set<Character> set_Of_char = new HashSet<>();
		
		char[] char_Of_S = s.toCharArray();
		for(j = 0; j < char_Of_S.length; j++) {
			System.out.println(j + "  " +i);
			if(!set_Of_char.contains(char_Of_S[j])){
				set_Of_char.add(char_Of_S[j]);
				System.out.println(set_Of_char);
			}
			else {
				if((j-i) > longest) {
					longest = j-i;
				}
				for(int k = i; k < j; k++) {
					if(char_Of_S[k] == char_Of_S[j]) {
						i = k + 1; 
					}
				}
			}
		}
		if((j-i) > longest) {
			longest = j-i;
		}
		return longest;
	}
	
}
