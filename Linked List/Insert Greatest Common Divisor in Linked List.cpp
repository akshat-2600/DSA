/*
    Company Tags   : 
    LeetCode Link  :  https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

/************************************************************ C++ ************************************************************/

// T.C  : O(N * log(min(a, b)))
// S.C  : O(1)

class Solution {
public:
    int gcdNum(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;

        while (temp->next != nullptr) {
            int a = temp->val;
            int b = temp->next->val;

            int c = gcdNum(a, b);

            ListNode* node1 = new ListNode(c);
            node1->next = temp->next;
            temp->next = node1;
            temp = temp->next->next;
        }

        return head;
    }
};


/************************************************************ Java ************************************************************/

// T.C  : O(N * log(min(a, b)))
// S.C  : O(1)

class Solution {

    public int gcdNum(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode temp = head;

        while (temp.next != null) {
            int a = temp.val;
            int b = temp.next.val;
            int c = gcdNum(a, b);

            ListNode node1 = new ListNode(c);
            node1.next = temp.next;
            temp.next  = node1;

            temp = temp.next.next;
        }
        return head;
    }
}