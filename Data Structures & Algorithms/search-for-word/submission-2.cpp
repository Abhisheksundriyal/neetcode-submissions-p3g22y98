class Solution {
public:

    bool recur(vector<vector<char>>& board,vector<vector<int>> VIS,string& word,int idx,int n,int i,int j) {
        if(idx==n)
            return true;
        VIS[i][j]=1;
        if(board[i][j]!=word[idx])
            return false;
        bool ans=false;
        if(i+1>=0 && i+1<board.size() && j>=0 && j<board[i].size() && VIS[i+1][j]==0 && recur(board,VIS,word,idx+1,n,i+1,j))
            ans=true;
        if(i-1>=0 && i-1<board.size() && j>=0 && j<board[i].size() && VIS[i-1][j]==0 && recur(board,VIS,word,idx+1,n,i-1,j))
            ans=true;
        if(i>=0 && i<board.size() && j+1>=0 && j+1<board[i].size() && VIS[i][j+1]==0 && recur(board,VIS,word,idx+1,n,i,j+1))
            ans=true;
        if(i>=0 && i<board.size() && j-1>=0 && j-1<board[i].size() && VIS[i][j-1]==0 && recur(board,VIS,word,idx+1,n,i,j-1))
            ans=true;
        if(idx==(n-1))
            ans=true;
        
        
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        vector<vector<int>> VIS(n);
        for(int i=0;i<n;i++)
        {
            int m=board[i].size();
            vector<int> temp(m,0);
            VIS[i]=temp;
        }
        for(int i=0;i<n;i++)
        {
            int m=board[i].size();
            for(int j=0;j<m;j++)
            {
                if(recur(board,VIS,word,0,word.size(),i,j))
                    return true;
            }
        }
        return false;
    }
};
