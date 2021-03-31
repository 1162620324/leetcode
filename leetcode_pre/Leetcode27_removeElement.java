package coding;

public class Leetcode27_removeElement {
    public int removeElement(int[] nums, int val) {
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
}
