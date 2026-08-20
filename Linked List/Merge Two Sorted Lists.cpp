/*
    Company Tags        : 
    Leetcode Link       :  https://leetcode.com/problems/merge-two-sorted-lists/

/********************************************************************* C++ ****************************************************************/

// T.C      : O(N)
// S.C      : O(N)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Create a dummy node to act as the starting anchor
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 2. Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;   // Link the smaller node
                list1 = list1->next; // Advance list1
            } else {
                tail->next = list2;   // Link the smaller node
                list2 = list2->next; // Advance list2
            }
            tail = tail->next;        // Advance the tail pointer
        }
        
        // 3. Append the remaining nodes of the non-empty list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // 4. The actual sorted list starts right after the dummy node
        return dummy.next;
    }
};


/********************************************************************* JAVA ****************************************************************/

// T.C      : O(N)
// S.C      : O(N)



class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode tail  = dummy;


        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }

        if (list1 != null) {
            tail.next = list1;
        } else {
            tail.next = list2;
        }

        return dummy.next;
    }
}
