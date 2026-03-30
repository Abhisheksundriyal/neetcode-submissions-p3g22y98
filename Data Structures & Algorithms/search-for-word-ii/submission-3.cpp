class Solution {
    struct trie{
        vector<trie*> children;
        bool isEnd;
        trie() {
            for(int i=0;i<26;i++)
                children.push_back(nullptr);
            isEnd=false;
        }
    };


    trie* root;
    vector<string> ans;
    vector<vector<bool>> VIS;
    string curr;


    void insertWord(string& word) {
        trie* node = root;
        for(int i=0;i<word.size();i++) {
            int idx=word[i]-'a';
            if(node->children[idx]==nullptr) {
                trie* temp = new trie;
                node->children[idx]=temp;
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }

    void recur(int i,int j,int n,int m,
                vector<vector<char>>& board,trie* node) {
        int idx=board[i][j]-'a';
        node=node->children[idx];
        if(node==nullptr)
            return;
        curr.push_back(board[i][j]);
        if(node->isEnd)
        {
            node->isEnd=false;
            ans.push_back(curr);
        }
        VIS[i][j]=true;
        if(i+1<n && !VIS[i+1][j])
            recur(i+1,j,n,m,board,node);
        if(i-1>=0 && !VIS[i-1][j])
            recur(i-1,j,n,m,board,node);
        if(j+1<m && !VIS[i][j+1])
            recur(i,j+1,n,m,board,node);
        if(j-1>=0 && !VIS[i][j-1])
            recur(i,j-1,n,m,board,node);
        curr.pop_back();
        VIS[i][j]=false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new trie;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            vector<bool> temp(m,false);
            VIS.push_back(temp);
        }
        for(int i=0;i<words.size();i++)
            insertWord(words[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                recur(i,j,n,m,board,root);
        }

        return ans;
    }
};
