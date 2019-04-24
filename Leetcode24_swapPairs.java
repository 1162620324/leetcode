package coding;

public class Leetcode24_swapPairs {
	
//	  Definition for singly-linked list.
	  public class ListNode {
	      int val;
	     ListNode next;
	      ListNode(int x) { val = x; }
	 }
	 
	class Solution {
	    public ListNode swapPairs(ListNode head) {
	    	ListNode realHead = new ListNode(-1);
	    	realHead.next = head;
	    	ListNode nowNode = null;
	    	ListNode last = realHead;
	    	ListNode next = null;
	    	nowNode = head;
	        while(nowNode != null) {
	        	if(nowNode.next != null) { 
	        		next = nowNode.next;
	        		nowNode.next = next.next;
	        		next.next = nowNode;
	        		last.next = next;
	        		last = nowNode;
	        		nowNode = nowNode.next;
	        	}
	            else{
	                break;
	            }
	        }
	    	
	    	return realHead.next;
	    }
	}
}
