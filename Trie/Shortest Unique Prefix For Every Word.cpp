/*
    Company Tags           : MICROSOFT , GOOGLE 
    GeekForGeeks Link      : https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1


/************************************************************ C++ ************************************************************/

// Approach : Using Trie Data 
// T.C : Building Trie O(N*L)
// S.C : Searching Trie O(N*L)


class TrieNode {
	public:
	
	TrieNode* children[26];
	int count;
	
	TrieNode() {
		count = 0;
		for (int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
	}
};



class Solution {
	public:
	
	TrieNode* root = new TrieNode();
	
	void insert(string &word) {
	    TrieNode* crawler = root;
	    
	    for (char ch : word) {
	        int idx = ch - 'a';
	        
	        if (crawler->children[idx] == nullptr) {
	            crawler->children[idx] = new TrieNode();
	        }
	        crawler = crawler->children[idx];
	        crawler->count++;
	    }
	}
	
	string getPrefix(string& word) {
	    TrieNode* crawler = root;
	    
	    string prefix = "";
	    
	    for (char ch : word) {
	        int idx = ch - 'a';
	        
	        crawler = crawler->children[idx];
	        prefix += ch;
	        
	        if (crawler->count == 1) {
	            break;
	        }
	    }
	    return prefix;
	}
	
	vector<string> findPrefixes(vector<string>& arr) {
		
		for (string &word : arr) {
		    insert(word);
		}
		
		vector<string> ans;
		
		for (string& word : arr) {
		    
		    ans.push_back(getPrefix(word));
		}
		
		return ans;
	}
};



/************************************************************ Java ************************************************************/

// Approach : Using Trie Data 
// T.C : Building Trie O(N*L)
// S.C : Searching Trie O(N*L)



class Solution {
    
    class TrieNode {
        TrieNode[] children;
        int count;
        
        TrieNode() {
            children = new TrieNode[26];
            count = 0;
        }
    }
    
    TrieNode root = new TrieNode();
    
    private void insert(String word) {
        TrieNode crawler = root;
        
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            
            if (crawler.children[idx] == null) {
                crawler.children[idx] = new TrieNode();
            }
            crawler = crawler.children[idx];
            crawler.count++;
        }
    }
    
    private String getPrefix(String word) {
        TrieNode crawler = root;
        
        StringBuilder prefix = new StringBuilder();
        
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            
            crawler = crawler.children[idx];
            
            prefix.append(ch);
            
            if (crawler.count == 1) {
                break;
            }
        }
        return prefix.toString();
    }
    
    public ArrayList<String> findPrefixes(String[] arr) {
        
        for (String word: arr) {
            insert(word);
        }
        
        ArrayList<String> ans = new ArrayList<>();
        
        for (String word: arr) {
            ans.add(getPrefix(word));
        }
        
        return ans;
    }
}