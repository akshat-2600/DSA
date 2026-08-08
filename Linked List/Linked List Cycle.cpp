/*
    Company Tags        : 
    LeetCode Link       :   https://leetcode.com/problems/linked-list-cycle/description/


/************************************************************ C++ ************************************************************************/

// Approach : fast and slow pointer
//T.C : O(n)
//S.C : O(n)


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast != NULL && slow == fast ) {
                return true;
            }
        }
        return false;
    }
};



/************************************************************ JAVA ************************************************************************/

// Approach : fast and slow pointer
//T.C : O(n)
//S.C : O(n)


public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (fast != null && slow == fast) {
                return true;
            }    
        }
        return false;
    }
}
