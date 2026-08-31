/*
    Company Tag          : 
    Leetcode Link        : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
*/


/*************************************************************** C++ *************************************************/

// T.C       : O(n)
// S.C       : O(n)  

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next->next == NULL) {
            return {-1, -1};
        }

        vector<int> criticalPoints;
        int countIdx = 2;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;

        while (c != NULL) {
            int aVal = a->val;
            int bVal = b->val;
            int cVal = c->val;

            if (aVal < bVal && bVal > cVal) {
                criticalPoints.push_back(countIdx);
            } else if (aVal > bVal && bVal < cVal) {
                criticalPoints.push_back(countIdx);
            }
            countIdx++;
            a = a->next;
            b = b->next;
            c = c->next;
        }

        int n = criticalPoints.size();

        if (n < 2) return {-1, -1};

        int minDist = INT_MAX;
        int maxDist = criticalPoints[n-1] - criticalPoints[0];

        for (int i = 1; i < n; i++) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i-1]);
        }

        return {minDist, maxDist};
    }
};



/*************************************************************** JAVA *************************************************/

// T.C       : O(n)
// S.C       : O(n)  

class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if (head.next.next == null) {
            return new int[]{-1, -1};
        } 

        List<Integer> criticalPoints = new ArrayList<>();
        int countIdx = 2;

        ListNode a = head;
        ListNode b = head.next;
        ListNode c = head.next.next;

        while (c != null) {
            int aVal = a.val;
            int bVal = b.val;
            int cVal = c.val;

            if ((aVal < bVal && bVal > cVal) || (aVal > bVal && bVal < cVal)) {
                criticalPoints.add(countIdx);
            }
            countIdx++;
            a = a.next;
            b = b.next;
            c = c.next;
        }

        int n = criticalPoints.size();

        if (n < 2) {
            return new int[]{-1, -1};
        }

        int minDist = Integer.MAX_VALUE;
        int maxDist = criticalPoints.get(n - 1) - criticalPoints.get(0);

        for (int i = 1; i < n; i++) {
            minDist = Math.min(minDist, criticalPoints.get(i) - criticalPoints.get(i-1));
        }

        return new int[]{minDist, maxDist};
    }
}