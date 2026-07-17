/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        if(head.next==null) return null;
        ListNode ptr1 = head;
        
        int total_nodes = 0;

        while(ptr1!=null){
            total_nodes += 1;
            ptr1 = ptr1.next;
        }

        ptr1 = head;
        ListNode ptr2 = null;

        int m = total_nodes - n;

        for(int i = 0; i<m; i++){
            // System.out.println(ptr1.val);
            ptr2 = ptr1;
            ptr1 = ptr1.next;
        }

        ptr2.next = ptr1.next;
        ptr1.next = null;

        return head;
    }
}
