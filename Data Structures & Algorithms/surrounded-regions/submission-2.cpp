class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& VIS,bool& ans) {
    VIS[i][j]=true;
    if(i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1)
        ans=false;
    if(i+1<board.size() && board[i+1][j]=='O' && !VIS[i+1][j])
         dfs(board,i+1,j,VIS,ans);
    if(i-1>=0 && board[i-1][j]=='O' && !VIS[i-1][j])
         dfs(board,i-1,j,VIS,ans);
    if(j+1<board[0].size() && board[i][j+1]=='O' && !VIS[i][j+1])
         dfs(board,i,j+1,VIS,ans);
    if(j-1>=0 && board[i][j-1]=='O' && !VIS[i][j-1])
        dfs(board,i,j-1,VIS,ans);
}

void edit(vector<vector<char>>& board,int i,int j) {
    board[i][j]='X';
    if(i+1<board.size() && board[i+1][j]=='O')
        edit(board,i+1,j);
    if(i-1>=0 && board[i-1][j]=='O')
        edit(board,i-1,j);
    if(j+1<board[0].size() && board[i][j+1]=='O')
        edit(board,i,j+1);
    if(j-1>=0 && board[i][j-1]=='O')
        edit(board,i,j-1);
}

void solve(vector<vector<char>>& board) {
    int n=board.size(),m=board[0].size();
    vector<vector<bool>> VIS(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='O' && !VIS[i][j])
            {
                bool temp=true;
                dfs(board,i,j,VIS,temp);
                if(temp)
                    edit(board,i,j);
            }

        }
    }
}
};
