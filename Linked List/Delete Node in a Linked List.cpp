/*
    Company Tags         :  
    LeetCode Link        :  https://leetcode.com/problems/delete-node-in-a-linked-list/


/**************************************************************** C++ ****************************************************************/

// T.C  : O(n)
// S.C  : O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        ListNode* curr = node->next;

        while (curr != NULL) {
            prev->val = curr->val;

            if (prev->next->next == NULL) {
                prev->next = NULL;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
    }
};

/**************************************************************** JAVA ****************************************************************/

// T.C  : O(n)
// S.C  : O(1)

class Solution {
    public void deleteNode(ListNode node) {
        
        ListNode prev = node;
        ListNode curr = node.next;

        while (curr != null) {
            prev.val = curr.val;

            if (prev.next.next == null) {
                prev.next = null;
                break;
            }
            prev = curr;
            curr = curr.next;
        }
    }
}