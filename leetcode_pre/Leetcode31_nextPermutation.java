package coding;

public class Leetcode31_nextPermutation {
	public static void main(String[] args) {
		int[] test = {1,3,2};
		nextPermutation(test);
	}
	
	public static void sort(int[] nums, int begin, int end) {
		for(int i = 0; i < end-begin+1; i++) {
			boolean isSwap = false;
			for(int j = begin; j < end-i; j++) {
				if(nums[j] > nums[j+1]) {
					int temp = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = temp;
					isSwap = true;
				}
			}
			if(!isSwap) {
				break;
			}
		}
	}
	
	
	public static void nextPermutation(int[] nums) {
		int temp;
		boolean flag = false;
		int i;
        for( i = nums.length-2; i >=0; i--) {
        	if(nums[i] < nums[i+1]) {
        		for(int j = nums.length-1; j > i; j--) {
        			if(nums[j] > nums[i]) {
        				temp = nums[i];
                		nums[i] = nums[j];
                		nums[j] = temp;
                		break;
        			}
        		}
        		 
        		flag = true;
        		break;
        	}
        }
       
        
        if(!flag) {
        	sort(nums, 0, nums.length-1);
        	return;
        }
        sort(nums, i+1, nums.length-1);
    }
}
