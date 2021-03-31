package coding;

public class Leetcode35_searchInsert {
    public int searchInsert(int[] nums, int target) {
        int res = 0;
        int i;
		 for(i = 0; i < nums.length; i++) {
			 if(nums[i] == target) {
				 res = i;
                 break;
			 }
			 else if(nums[i] > target) {
				 res = i;
                 break;
			 }
		 }
		 if(i == nums.length)
             res = i;
		 return res;
    }
}
