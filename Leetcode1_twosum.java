package coding;

public class Leetcode1_twosum {
	    public int[] twoSum(int[] nums, int target) {
	        int [] solution = new int [2];
	        for(int i = 0; i < nums.length; i++){
	            for(int j = i+1; j < nums.length; j++){
	                if(target == nums[i] + nums[j]){
	                    solution[0] = i;
	                    solution[1] = j;
	                    break;
	                }
	            }
	        }
	        return solution;
	    }

}
