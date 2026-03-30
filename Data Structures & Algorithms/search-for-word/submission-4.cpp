class Solution {
public:
    void recur(vector<vector<char>>& board,string& word,int i,int j
                ,int idx,vector<vector<int>>& VIS,bool& ans) {
        
        if(board[i][j]!=word[idx])
            return;
        if(idx>=word.size()-1)
        {
            ans=true;
            return;
        }
        VIS[i][j]=1;
        if(i+1<board.size() && !VIS[i+1][j])
            recur(board,word,i+1,j,idx+1,VIS,ans);
        if(i-1>=0 && !VIS[i-1][j])
            recur(board,word,i-1,j,idx+1,VIS,ans);
        if(j+1<board[0].size() && !VIS[i][j+1])
            recur(board,word,i,j+1,idx+1,VIS,ans);
        if(j-1>=0 && !VIS[i][j-1])
            recur(board,word,i,j-1,idx+1,VIS,ans);
        
        VIS[i][j]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        int n=board.size(),m=board[0].size();
        vector<vector<int>> VIS(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!ans)
                    recur(board,word,i,j,0,VIS,ans);
            }
        }
        return ans;
    }
};
