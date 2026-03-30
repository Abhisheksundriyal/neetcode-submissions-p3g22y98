class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                vector<int> cnt(10,0);
                for(int x=i;x<i+3;x++)
                {
                    for(int y=j;y<j+3;y++)
                    {
                        if(board[x][y]!='.')
                            cnt[board[x][y]-'0']++;
                    }
                        
                }
                for(int k=1;k<=9;k++)
                {
                    if(cnt[k]>1)
                        return false;
                }
            }
        }
        for(int i=0, j=0;i<9 && j<9;i++, j++)
        {
            vector<int> cnt(10,0);
            for(int c=0;c<9;c++)
            {
                if(board[i][c]!='.')
                    cnt[board[i][c]-'0']++;
            }
            for(int k=1;k<=9;k++)
            {
                if(cnt[k]>1)
                    return false;
                cnt[k]=0;
            }
            for(int r=0;r<9;r++)
            {
                if(board[r][j]!='.')
                    cnt[board[r][j]-'0']++;
            }
            for(int k=1;k<=9;k++)
            {
                if(cnt[k]>1)
                    return false;
                cnt[k]=0;
            }
        }
        return true;
    }
};
