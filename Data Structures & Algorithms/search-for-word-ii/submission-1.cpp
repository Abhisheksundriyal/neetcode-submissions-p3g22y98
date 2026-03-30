class Solution {

    struct TrieNode {
        bool isEnd=false;
        unordered_map<char,TrieNode*> children;
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++)
        {
            TrieNode* node = root;
            for(int j=0;j<words[i].size();j++)
            {
                char ch=words[i][j];
                if(node->children.count(ch)==0)
                    node->children[ch] = new TrieNode();
                node = node->children[ch];
            }
            node->isEnd=true;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board,int i,int j,TrieNode* node,string& path,vector<vector<bool>>& VIS,vector<string>& ans) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || VIS[i][j]) return;

        char ch = board[i][j];
        if(!node->children.count(ch)) return;
        
        VIS[i][j]=true;
        node = node->children[ch];
        path.push_back(ch);
        
        if(node->isEnd)
        {
            ans.push_back(path);
            node->isEnd=false;
        }

        dfs(board,i+1,j,node,path,VIS,ans);
        dfs(board,i-1,j,node,path,VIS,ans);
        dfs(board,i,j+1,node,path,VIS,ans);
        dfs(board,i,j-1,node,path,VIS,ans);

        VIS[i][j]=false;
        path.pop_back();
    }


public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        int n=board.size(),m=board[0].size();
        vector<string> ans;
        vector<vector<bool>> VIS(n, vector<bool>(m, false));
        string path;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                dfs(board,i,j,root,path,VIS,ans);
        }
        return ans;
    }
};
