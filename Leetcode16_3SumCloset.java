package coding;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Leetcode16_3SumCloset {
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
	    			 while(i<j && nums[j] == nums[j+1]) j--;
	    			 
	    		 }
	    		 else if(nums[i] + nums[j] < targets) i++;
	    		 else j--;
	    	 }
	    	 while(k < nums.length - 2 && nums[k] == nums[k+1])
	                k++;
	     }
	    
	    
		return !lists.isEmpty();
	}
}
