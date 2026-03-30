class Solution {
public:

    bool valid(int i,int j,int n,int m,vector<vector<int>>& VIS) {
        return (i>=0 && i<n && j>=0 && j<m && VIS[i][j]==0);
    }

    bool dfs(vector<vector<char>>& board,int i,int j,int n,int m,string& word,int idx,vector<vector<int>>& VIS) {
        if(board[i][j]!=word[idx])
            return false;
        if(idx==word.size()-1)
            return true;
        VIS[i][j]=1;
        if(valid(i+1,j,n,m,VIS) && dfs(board,i+1,j,n,m,word,idx+1,VIS))
            return true;
        if(valid(i-1,j,n,m,VIS) && dfs(board,i-1,j,n,m,word,idx+1,VIS))
            return true;
        if(valid(i,j+1,n,m,VIS) && dfs(board,i,j+1,n,m,word,idx+1,VIS))
            return true;
        if(valid(i,j-1,n,m,VIS) && dfs(board,i,j-1,n,m,word,idx+1,VIS))
            return true;
        VIS[i][j]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> VIS(n, vector<int>(m, 0));
        // unordered_set<pair<int,int>> VIS;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(board,i,j,n,m,word,0,VIS))
                    return true;
            }
        }
        return false;
    }
};
