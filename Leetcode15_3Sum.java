package coding;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Leetcode15_3Sum {
	public List<List<Integer>> threeSum(int[] nums) {
		 List<List<Integer>> lists = new ArrayList<List<Integer>>();
	     Arrays.sort(nums);
        
	     for(int k = 0; k < nums.length - 2; k++) {
	    	 int i  =k +1;
	    	 int j = nums.length-1;
	    	 int target = -nums[k];
	    	 while(i < j) {
	    		 if(nums[i] + nums[j] == target) {
	    			 lists.add(Arrays.asList(nums[k], nums[i++], nums[j--]));
	    			 while(i<j && nums[i] == nums[i-1]) i++;
	    			 while(i<j && nums[j] == nums[j+1]) j--;
	    			 
	    		 }
	    		 else if(nums[i] + nums[j] < target) i++;
	    		 else j--;
	    	 }
	    	 while(k < nums.length - 2 && nums[k] == nums[k+1])
	                k++;
	     }
	     return lists;
	       
	 }
}
