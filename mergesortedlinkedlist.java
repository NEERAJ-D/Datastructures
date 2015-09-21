/* Merge two sorted list */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head=null,temp=null;
        if(l1 == null){
            return l2;
        }
        if(l2 == null){
            return l1;
        }
        while(l1!=null && l2!=null){
            if(head==null){
                if(l1.val < l2.val){
                    head = l1;
                    l1 = l1.next;
                }
                else{
                    head = l2;
                    l2=l2.next;
                }
                temp = head;
            }
            if(l1!=null && l2!=null && l1.val<l2.val){
                temp.next = l1;
                l1 = l1.next;
                temp = temp.next;
            }
            else{
                if(l1!=null && l2!=null)
                {temp.next = l2;
                l2 = l2.next;
                temp = temp.next;
                }
            }
        }
        if(l1!=null){
            while(l1!=null){
                temp.next = l1;
                l1 = l1.next;
                temp = temp.next;
            }
        }
        else{
            while(l2!=null){
                temp.next = l2;
                l2 = l2.next;
                temp = temp.next;
            }
        }
        return head;
    }
}