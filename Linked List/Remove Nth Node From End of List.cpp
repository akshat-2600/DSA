/*
    Company Tags        : 
    LeetCode Link       :   https://leetcode.com/problems/remove-nth-node-from-end-of-list/

*/    

/************************************************************ C++ ************************************************************************/

//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* temp1 = head;
        int count = 0;

        while (temp1 != NULL) {
            count++;
            temp1 = temp1->next;
        }

        if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int traverse = count - n - 1;

        ListNode* temp2 = head;

        while (traverse--) {
            temp2 = temp2->next;
        }
        ListNode* prev = temp2;

        prev->next = temp2->next->next;
        return head;
    }
};


/************************************************************ JAVA ************************************************************************/

//T.C : O(n)
//S.C : O(1)



class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Handle edge case where the list has only 1 element
        if (head == null || head.next == null) return null;

        ListNode temp1 = head;
        int count = 0;

        // First pass: Count total nodes in the list
        while (temp1 != null) {
            count++;
            temp1 = temp1.next;
        }

        // Handle case where we need to remove the first node (head)
        if (count == n) {
            ListNode newHead = head.next;
            // Java garbage collects the old head automatically; no manual delete needed
            return newHead;
        }

        // Calculate how many steps to reach the node *before* the target node
        int traverse = count - n - 1;
        ListNode temp2 = head;

        while (traverse-- > 0) {
            temp2 = temp2.next;
        }
        
        ListNode prev = temp2;

        // Skip and remove the N-th node from the end
        prev.next = temp2.next.next;
        
        return head;
    }
}
