class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        int count;
        TrieNode() {
            for(int i=0;i<26;i++)
                child.push_back(nullptr);
            count=0;
        }
    };
    
    TrieNode* root;
    vector<string> ans;

    void recur(vector<vector<char>>& board,vector<vector<int>>& VIS,
                int i,int j,string& curr,TrieNode* node) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || !node || VIS[i][j])
            return;
        VIS[i][j]=1;
        node=node->child[board[i][j]-'a'];
        curr.push_back(board[i][j]);
        if(node && node->count)
        {
            ans.push_back(curr);
            node->count--;
        }
        recur(board,VIS,i+1,j,curr,node);
        recur(board,VIS,i-1,j,curr,node);
        recur(board,VIS,i,j+1,curr,node);
        recur(board,VIS,i,j-1,curr,node);
        curr.pop_back();
        VIS[i][j]=0;
    }

    void insert(string& word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++) {
            if(node->child[word[i]-'a']==nullptr)
            {
                TrieNode* newNode=new TrieNode();
                node->child[word[i]-'a']=newNode;
            }
            node=node->child[word[i]-'a'];
        }
        node->count++;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> VIS(n,vector<int>(m,0));
        string curr;
        root = new TrieNode();
        for(int i=0;i<words.size();i++) {
            insert(words[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                recur(board,VIS,i,j,curr,root);
        }
        return ans;
    }
};
