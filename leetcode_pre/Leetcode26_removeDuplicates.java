package coding;

public class Leetcode26_removeDuplicates {
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
		 int res = 0;
		 for(int i =0 ; i < nums.length-1; i++) {
			 if(!(nums[i] == nums[i+1])) {
				 res++;
                nums[res] = nums[i+1]; 
			 }
		 }
		 
		 
		 return res+1;
	 }
}
