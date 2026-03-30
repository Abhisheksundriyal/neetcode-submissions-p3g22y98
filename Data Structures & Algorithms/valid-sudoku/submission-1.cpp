class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int x=0,y=0;
    for(int i=0;i<9;i+=3)
    {
        for(int j=0;j<9;j+=3)
        {
            vector<int> cnt(9,0);
            for(int a=i;a<i+3;a++)
            {
                for(int b=j;b<j+3;b++)
                {
                    if(board[a][b]!='.')
                    {
                        cnt[board[a][b]-'1']++;
                        if(cnt[board[a][b]-'1']>1)
                            return false;
                    }
                }
            }
        }
    }
    while(x<9)
    {
        vector<int> cntR(9,0),cntC(9,0);
        for(int i=0;i<9;i++)
        {
            if(board[i][y]!='.')
            {
                cntC[board[i][y]-'1']++;
                if(cntC[board[i][y]-'1']>1)
                    return false;
            }
        }
        for(int j=0;j<9;j++)
        {
            if(board[x][j]!='.')
            {
                cntR[board[x][j]-'1']++;
                if(cntR[board[x][j]-'1']>1)
                    return false;
            }
        }
        x++;
        y++;
    }
    return true;
    }
};
