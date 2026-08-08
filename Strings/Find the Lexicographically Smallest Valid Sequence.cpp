/*
    Company Tags             : 
    GeeksForGeeks Link       :   https://www.geeksforgeeks.org/problems/connecting-the-graph/1


/************************************************************ C++ ************************************************************************/

// Approach : Creating a right matched length suffix array and then iterating from start to end
//T.C : O(n + m)
//S.C : O(n + m)


class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightSideMatchedLength(n, 0);
        int rightMatched = 0;

        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }
            rightSideMatchedLength[i] = rightMatched;
            i--; 
        }

        vector<int> seq;

        i = 0;
        j = 0;
        bool canChange = true;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if (canChange == true && i+1 < n && rightSideMatchedLength[i+1] >= m - j - 1) {
                seq.push_back(i);
                canChange = false;
                j++;
            }
            i++;
        }
        return j == m ? seq : vector<int>();
    }
};



/************************************************************ JAVA ************************************************************************/

// Approach : Creating a right matched length suffix array and then iterating from start to end
//T.C : O(n + m)
//S.C : O(n + m)

class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        int[] rightMatchedLength = new int[n];
        int rightMatched = 0;

        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j >= 0 && word1.charAt(i) == word2.charAt(j)) {
                rightMatched++;
                j--;
            }
            rightMatchedLength[i] = rightMatched;
            i--;
        }

        i = 0;
        j = 0;
        int[] seq = new int[m];
        int idx = 0;

        boolean canChange = true;

        while (i < n && j < m) {
            if (word1.charAt(i) == word2.charAt(j)) {
                seq[idx] = i;
                j++;
                idx++;
            } else if (canChange == true && i+1 < n && rightMatchedLength[i+1] >= m - j - 1) {
                seq[idx] = i;
                canChange = false;
                idx++;
                j++;
            }
            i++;
        }

        return j == m ? seq : new int[0];
    }
}