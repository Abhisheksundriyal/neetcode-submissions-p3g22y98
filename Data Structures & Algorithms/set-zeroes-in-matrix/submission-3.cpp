class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int x=1,y=1,n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0 || j==0)
                    {
                        if(i==0)
                            x=0;
                        if(j==0)
                            y=0;
                    }
                    else
                    {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        if(x==0)
        {
            for(int j=0;j<m;j++)
                matrix[0][j]=0;
        }
        if(y==0)
        {
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
    }
};
