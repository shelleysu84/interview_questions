class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    
    struct TrieNode {
        TrieNode (): is_word(false) {
            for(int i = 0; i < 26; i++)
                children.push_back(nullptr);
        }
        vector<TrieNode*> children;
        bool is_word;
    };
     
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here

        vector<string> result;
        if(words.size() == 0 || board.size() == 0 || board.front().size() == 0)
            return result;
        
        // insert all words into the trie
        TrieNode *root = new TrieNode();
        for(auto word : words) {
            trieInsert(root, word);
        }
        
        // search trie
        int m = board.size(), n = board.front().size();
        string path;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, i, j, root, path, result);
            }
        }
        return result;
        
    }
    
    void dfs(vector<vector<char> > &board, int i, int j, TrieNode *root, string &path, vector<string> &result) {
        
        if(!root)
            return;
        if(root->is_word) {
            root->is_word = false;
            result.push_back(path);
        }
        int m = board.size(), n = board.front().size();
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#')
            return;
        
        int index = board[i][j] - 'a';
        char c = board[i][j];
        
        TrieNode *nextroot = root->children[index];
        path.push_back(c);
        board[i][j] = '#';
        dfs(board, i+1, j, nextroot, path, result);
        dfs(board, i-1, j, nextroot, path, result);
        dfs(board, i, j+1, nextroot, path, result);
        dfs(board, i, j-1, nextroot, path, result);
        path.pop_back();
        board[i][j] = c;
        
    }
    
    void trieInsert(TrieNode *root, string word) {
        TrieNode *crawl = root;
        int len = word.length();
        for(int i = 0; i < len; i++) {
            int index = word[i] - 'a';
            if(crawl->children[index] == nullptr) {
                crawl->children[index] = new TrieNode();
            }
            crawl = crawl->children[index];
        }
        crawl->is_word = true;
    }
};