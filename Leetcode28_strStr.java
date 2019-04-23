package coding;

/*
 * 使用KMP算法
 */
public class Leetcode28_strStr {
	
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
}
