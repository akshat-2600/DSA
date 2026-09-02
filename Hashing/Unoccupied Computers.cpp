/*  
    Company Tags        : 
    GeekForGeeks Link   : https://www.geeksforgeeks.org/problems/unoccupied-computers-1646661078/1

/****************************************************************** C++ ****************************************************/

// T.C : O(length of string)
// S.C : O(length of string)

class Solution {
	public:
	int solve(int n, string s) {
		
		unordered_map<char, bool> mp;
		int ans = 0;
		
		for (char ch : s) {
			if (mp.find(ch) == mp.end()) {
				if (n > 0) {
					mp[ch] = true;
					n--;
				} else {
					mp[ch] = false;
					ans++;
				}
			} else {
				if (mp[ch] == true) {
					n++;
				}
			}
		}
		return ans;
	}
};
