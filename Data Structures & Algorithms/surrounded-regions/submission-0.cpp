class Solution {
public:
    void check(vector<vector<char>>& board,vector<vector<bool>>& VIS,int n,int m,int i,int j,bool& ans) {
    VIS[i][j]=false;
    if(i==0 || i==n-1 || j==0 || j==m-1)
        ans=false;
    if(i+1<n && board[i+1][j]=='O' && VIS[i+1][j])
         check(board,VIS,n,m,i+1,j,ans);
    if(i-1>=0 && board[i-1][j]=='O' && VIS[i-1][j])
         check(board,VIS,n,m,i-1,j,ans);
    if(j+1<m && board[i][j+1]=='O' && VIS[i][j+1])
         check(board,VIS,n,m,i,j+1,ans);
    if(j-1>=0 && board[i][j-1]=='O' && VIS[i][j-1])
         check(board,VIS,n,m,i,j-1,ans);
}

void editBoard(vector<vector<char>>& board,int i,int j,int n,int m) {
    board[i][j]='X';
    if(i+1<n && board[i+1][j]=='O')
        editBoard(board,i+1,j,n,m);
    if(i-1>=0 && board[i-1][j]=='O')
        editBoard(board,i-1,j,n,m);
    if(j+1<m && board[i][j+1]=='O')
        editBoard(board,i,j+1,n,m);
    if(j-1>=0 && board[i][j-1]=='O')
        editBoard(board,i,j-1,n,m);
}



void solve(vector<vector<char>>& board) {
    int n=board.size(),m=board[0].size();
    vector<vector<bool>> VIS(n,vector<bool>(m,true));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='O' && VIS[i][j])
            {
                bool ans=true;
                check(board,VIS,n,m,i,j,ans);
                if(ans)
                    editBoard(board,i,j,n,m);
            }
        }
    }
}
};
